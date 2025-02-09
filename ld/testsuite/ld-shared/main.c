/* This is the main program for the shared library test.  */

#include <stdio.h>

int mainvar = 1;
int overriddenvar = 2;
extern int shlibvar1;

extern int shlib_mainvar ();
extern int shlib_overriddenvar ();
extern int shlib_shlibvar1 ();
extern int shlib_shlibvar2 ();
extern int shlib_shlibcall ();
extern int shlib_maincall ();
extern int shlib_checkfunptr1 (int (*) ());
extern int shlib_checkfunptr2 (int (*) ());
extern int (*shlib_getfunptr1 ()) ();
extern int (*shlib_getfunptr2 ()) ();
extern int shlib_check ();
extern int shlib_shlibcall2 ();

/* This function is called by the shared library.  */

int
main_called ()
{
  return 6;
}

/* This function overrides a function in the shared library.  */

int
shlib_overriddencall2 ()
{
  return 8;
}

int
main ()
{
  printf ("mainvar == %d\n", mainvar);
  printf ("overriddenvar == %d\n", overriddenvar);
  printf ("shlibvar1 == %d\n", shlibvar1);
#ifndef SYMBOLIC_TEST
  printf ("shlib_mainvar () == %d\n", shlib_mainvar ());
#ifndef XCOFF_TEST
  printf ("shlib_overriddenvar () == %d\n", shlib_overriddenvar ());
#endif
#endif
  printf ("shlib_shlibvar1 () == %d\n", shlib_shlibvar1 ());
  printf ("shlib_shlibvar2 () == %d\n", shlib_shlibvar2 ());
  printf ("shlib_shlibcall () == %d\n", shlib_shlibcall ());
#ifndef SYMBOLIC_TEST
#ifndef XCOFF_TEST
  printf ("shlib_shlibcall2 () == %d\n", shlib_shlibcall2 ());
#endif
  printf ("shlib_maincall () == %d\n", shlib_maincall ());
#endif
  printf ("main_called () == %d\n", main_called ());
#ifndef SYMBOLIC_TEST
  printf ("shlib_checkfunptr1 (shlib_shlibvar1) == %d\n",
	  shlib_checkfunptr1 (shlib_shlibvar1));
  printf ("shlib_checkfunptr2 (main_called) == %d\n",
	  shlib_checkfunptr2 (main_called));
  {
    int (*p) ();

    p = shlib_getfunptr1 ();
    printf ("shlib_getfunptr1 () ");
    if (p == shlib_shlibvar1)
      printf ("==");
    else
      printf ("!=");
    printf (" shlib_shlibvar1\n");
  }
  {
    int (*p) ();

    p = shlib_getfunptr2 ();
    printf ("shlib_getfunptr2 () ");
    if (p == main_called)
      printf ("==");
    else
      printf ("!=");
    printf (" main_called\n");
  }
#endif
  printf ("shlib_check () == %d\n", shlib_check ());
  return 0;
}
