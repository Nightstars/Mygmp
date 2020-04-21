
/* ./.libs/lt-reuse.c - temporary wrapper executable for .libs/reuse.exe
   Generated by libtool (GNU libtool) 2.4.6

   The reuse program cannot be directly executed until all the libtool
   libraries that it depends on are installed.

   This wrapper executable should never be moved out of the build directory.
   If it is, it will not operate correctly.
*/
#ifdef _MSC_VER
# define _CRT_SECURE_NO_DEPRECATE 1
#endif
#include <stdio.h>
#include <stdlib.h>
#ifdef _MSC_VER
# include <direct.h>
# include <process.h>
# include <io.h>
#else
# include <unistd.h>
# include <stdint.h>
# ifdef __CYGWIN__
#  include <io.h>
# endif
#endif
#include <malloc.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define STREQ(s1, s2) (strcmp ((s1), (s2)) == 0)

/* declarations of non-ANSI functions */
#if defined __MINGW32__
# ifdef __STRICT_ANSI__
int _putenv (const char *);
# endif
#elif defined __CYGWIN__
# ifdef __STRICT_ANSI__
char *realpath (const char *, char *);
int putenv (char *);
int setenv (const char *, const char *, int);
# endif
/* #elif defined other_platform || defined ... */
#endif

/* portability defines, excluding path handling macros */
#if defined _MSC_VER
# define setmode _setmode
# define stat    _stat
# define chmod   _chmod
# define getcwd  _getcwd
# define putenv  _putenv
# define S_IXUSR _S_IEXEC
#elif defined __MINGW32__
# define setmode _setmode
# define stat    _stat
# define chmod   _chmod
# define getcwd  _getcwd
# define putenv  _putenv
#elif defined __CYGWIN__
# define HAVE_SETENV
# define FOPEN_WB "wb"
/* #elif defined other platforms ... */
#endif

#if defined PATH_MAX
# define LT_PATHMAX PATH_MAX
#elif defined MAXPATHLEN
# define LT_PATHMAX MAXPATHLEN
#else
# define LT_PATHMAX 1024
#endif

#ifndef S_IXOTH
# define S_IXOTH 0
#endif
#ifndef S_IXGRP
# define S_IXGRP 0
#endif

/* path handling portability macros */
#ifndef DIR_SEPARATOR
# define DIR_SEPARATOR '/'
# define PATH_SEPARATOR ':'
#endif

#if defined _WIN32 || defined __MSDOS__ || defined __DJGPP__ || \
  defined __OS2__
# define HAVE_DOS_BASED_FILE_SYSTEM
# define FOPEN_WB "wb"
# ifndef DIR_SEPARATOR_2
#  define DIR_SEPARATOR_2 '\\'
# endif
# ifndef PATH_SEPARATOR_2
#  define PATH_SEPARATOR_2 ';'
# endif
#endif

#ifndef DIR_SEPARATOR_2
# define IS_DIR_SEPARATOR(ch) ((ch) == DIR_SEPARATOR)
#else /* DIR_SEPARATOR_2 */
# define IS_DIR_SEPARATOR(ch) \
	(((ch) == DIR_SEPARATOR) || ((ch) == DIR_SEPARATOR_2))
#endif /* DIR_SEPARATOR_2 */

#ifndef PATH_SEPARATOR_2
# define IS_PATH_SEPARATOR(ch) ((ch) == PATH_SEPARATOR)
#else /* PATH_SEPARATOR_2 */
# define IS_PATH_SEPARATOR(ch) ((ch) == PATH_SEPARATOR_2)
#endif /* PATH_SEPARATOR_2 */

#ifndef FOPEN_WB
# define FOPEN_WB "w"
#endif
#ifndef _O_BINARY
# define _O_BINARY 0
#endif

#define XMALLOC(type, num)      ((type *) xmalloc ((num) * sizeof(type)))
#define XFREE(stale) do { \
  if (stale) { free (stale); stale = 0; } \
} while (0)

#if defined LT_DEBUGWRAPPER
static int lt_debug = 1;
#else
static int lt_debug = 0;
#endif

const char *program_name = "libtool-wrapper"; /* in case xstrdup fails */

void *xmalloc (size_t num);
char *xstrdup (const char *string);
const char *base_name (const char *name);
char *find_executable (const char *wrapper);
char *chase_symlinks (const char *pathspec);
int make_executable (const char *path);
int check_executable (const char *path);
char *strendzap (char *str, const char *pat);
void lt_debugprintf (const char *file, int line, const char *fmt, ...);
void lt_fatal (const char *file, int line, const char *message, ...);
static const char *nonnull (const char *s);
static const char *nonempty (const char *s);
void lt_setenv (const char *name, const char *value);
char *lt_extend_str (const char *orig_value, const char *add, int to_end);
void lt_update_exe_path (const char *name, const char *value);
void lt_update_lib_path (const char *name, const char *value);
char **prepare_spawn (char **argv);
void lt_dump_script (FILE *f);
#if __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 5)
# define externally_visible volatile
#else
# define externally_visible __attribute__((externally_visible)) volatile
#endif
externally_visible const char * MAGIC_EXE = "%%%MAGIC EXE variable%%%";
const char * LIB_PATH_VARNAME = "PATH";
const char * LIB_PATH_VALUE   = "F:\\myprogram\\msys2\\home\\Administrator\\gmp-6.2.0\\.libs;";
const char * EXE_PATH_VARNAME = "PATH";
const char * EXE_PATH_VALUE   = "F:\\myprogram\\msys2\\home\\Administrator\\gmp-6.2.0\\.libs;F:\\myprogram\\msys2\\mingw64\\lib;F:\\myprogram\\msys2\\mingw64\\bin;";
const char * TARGET_PROGRAM_NAME = "reuse.exe"; /* hopefully, no .exe */

#define LTWRAPPER_OPTION_PREFIX         "--lt-"

static const char *ltwrapper_option_prefix = LTWRAPPER_OPTION_PREFIX;
static const char *dumpscript_opt       = LTWRAPPER_OPTION_PREFIX "dump-script";
static const char *debug_opt            = LTWRAPPER_OPTION_PREFIX "debug";

int
main (int argc, char *argv[])
{
  char **newargz;
  int  newargc;
  char *tmp_pathspec;
  char *actual_cwrapper_path;
  char *actual_cwrapper_name;
  char *target_name;
  char *lt_argv_zero;
  int rval = 127;

  int i;

  program_name = (char *) xstrdup (base_name (argv[0]));
  newargz = XMALLOC (char *, (size_t) argc + 1);

  /* very simple arg parsing; don't want to rely on getopt
   * also, copy all non cwrapper options to newargz, except
   * argz[0], which is handled differently
   */
  newargc=0;
  for (i = 1; i < argc; i++)
    {
      if (STREQ (argv[i], dumpscript_opt))
	{
          setmode(1,_O_BINARY);
	  lt_dump_script (stdout);
	  return 0;
	}
      if (STREQ (argv[i], debug_opt))
	{
          lt_debug = 1;
          continue;
	}
      if (STREQ (argv[i], ltwrapper_option_prefix))
        {
          /* however, if there is an option in the LTWRAPPER_OPTION_PREFIX
             namespace, but it is not one of the ones we know about and
             have already dealt with, above (inluding dump-script), then
             report an error. Otherwise, targets might begin to believe
             they are allowed to use options in the LTWRAPPER_OPTION_PREFIX
             namespace. The first time any user complains about this, we'll
             need to make LTWRAPPER_OPTION_PREFIX a configure-time option
             or a configure.ac-settable value.
           */
          lt_fatal (__FILE__, __LINE__,
		    "unrecognized %s option: '%s'",
                    ltwrapper_option_prefix, argv[i]);
        }
      /* otherwise ... */
      newargz[++newargc] = xstrdup (argv[i]);
    }
  newargz[++newargc] = NULL;

  /* The GNU banner must be the first non-error debug message */
  lt_debugprintf (__FILE__, __LINE__, "libtool wrapper (GNU libtool) 2.4.6\n");
  lt_debugprintf (__FILE__, __LINE__, "(main) argv[0]: %s\n", argv[0]);
  lt_debugprintf (__FILE__, __LINE__, "(main) program_name: %s\n", program_name);

  tmp_pathspec = find_executable (argv[0]);
  if (tmp_pathspec == NULL)
    lt_fatal (__FILE__, __LINE__, "couldn't find %s", argv[0]);
  lt_debugprintf (__FILE__, __LINE__,
                  "(main) found exe (before symlink chase) at: %s\n",
		  tmp_pathspec);

  actual_cwrapper_path = chase_symlinks (tmp_pathspec);
  lt_debugprintf (__FILE__, __LINE__,
                  "(main) found exe (after symlink chase) at: %s\n",
		  actual_cwrapper_path);
  XFREE (tmp_pathspec);

  actual_cwrapper_name = xstrdup (base_name (actual_cwrapper_path));
  strendzap (actual_cwrapper_path, actual_cwrapper_name);

  /* wrapper name transforms */
  strendzap (actual_cwrapper_name, ".exe");
  tmp_pathspec = lt_extend_str (actual_cwrapper_name, ".exe", 1);
  XFREE (actual_cwrapper_name);
  actual_cwrapper_name = tmp_pathspec;
  tmp_pathspec = 0;

  /* target_name transforms -- use actual target program name; might have lt- prefix */
  target_name = xstrdup (base_name (TARGET_PROGRAM_NAME));
  strendzap (target_name, ".exe");
  tmp_pathspec = lt_extend_str (target_name, ".exe", 1);
  XFREE (target_name);
  target_name = tmp_pathspec;
  tmp_pathspec = 0;

  lt_debugprintf (__FILE__, __LINE__,
		  "(main) libtool target name: %s\n",
		  target_name);
  newargz[0] =
    XMALLOC (char, (strlen (actual_cwrapper_path) +
		    strlen (".libs") + 1 + strlen (actual_cwrapper_name) + 1));
  strcpy (newargz[0], actual_cwrapper_path);
  strcat (newargz[0], ".libs");
  strcat (newargz[0], "/");
  /* stop here, and copy so we don't have to do this twice */
  tmp_pathspec = xstrdup (newargz[0]);

  /* do NOT want the lt- prefix here, so use actual_cwrapper_name */
  strcat (newargz[0], actual_cwrapper_name);

  /* DO want the lt- prefix here if it exists, so use target_name */
  lt_argv_zero = lt_extend_str (tmp_pathspec, target_name, 1);
  XFREE (tmp_pathspec);
  tmp_pathspec = NULL;
  {
    char* p;
    while ((p = strchr (newargz[0], '\\')) != NULL)
      {
	*p = '/';
      }
    while ((p = strchr (lt_argv_zero, '\\')) != NULL)
      {
	*p = '/';
      }
  }
  XFREE (target_name);
  XFREE (actual_cwrapper_path);
  XFREE (actual_cwrapper_name);

  lt_setenv ("BIN_SH", "xpg4"); /* for Tru64 */
  lt_setenv ("DUALCASE", "1");  /* for MSK sh */
  /* Update the DLL searchpath.  EXE_PATH_VALUE ($dllsearchpath) must
     be prepended before (that is, appear after) LIB_PATH_VALUE ($temp_rpath)
     because on Windows, both *_VARNAMEs are PATH but uninstalled
     libraries must come first. */
  lt_update_exe_path (EXE_PATH_VARNAME, EXE_PATH_VALUE);
  lt_update_lib_path (LIB_PATH_VARNAME, LIB_PATH_VALUE);

  lt_debugprintf (__FILE__, __LINE__, "(main) lt_argv_zero: %s\n",
		  nonnull (lt_argv_zero));
  for (i = 0; i < newargc; i++)
    {
      lt_debugprintf (__FILE__, __LINE__, "(main) newargz[%d]: %s\n",
		      i, nonnull (newargz[i]));
    }

  /* execv doesn't actually work on mingw as expected on unix */
  newargz = prepare_spawn (newargz);
  rval = (int) _spawnv (_P_WAIT, lt_argv_zero, (const char * const *) newargz);
  if (rval == -1)
    {
      /* failed to start process */
      lt_debugprintf (__FILE__, __LINE__,
		      "(main) failed to launch target \"%s\": %s\n",
		      lt_argv_zero, nonnull (strerror (errno)));
      return 127;
    }
  return rval;
}

void *
xmalloc (size_t num)
{
  void *p = (void *) malloc (num);
  if (!p)
    lt_fatal (__FILE__, __LINE__, "memory exhausted");

  return p;
}

char *
xstrdup (const char *string)
{
  return string ? strcpy ((char *) xmalloc (strlen (string) + 1),
			  string) : NULL;
}

const char *
base_name (const char *name)
{
  const char *base;

#if defined HAVE_DOS_BASED_FILE_SYSTEM
  /* Skip over the disk name in MSDOS pathnames. */
  if (isalpha ((unsigned char) name[0]) && name[1] == ':')
    name += 2;
#endif

  for (base = name; *name; name++)
    if (IS_DIR_SEPARATOR (*name))
      base = name + 1;
  return base;
}

int
check_executable (const char *path)
{
  struct stat st;

  lt_debugprintf (__FILE__, __LINE__, "(check_executable): %s\n",
                  nonempty (path));
  if ((!path) || (!*path))
    return 0;

  if ((stat (path, &st) >= 0)
      && (st.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
    return 1;
  else
    return 0;
}

int
make_executable (const char *path)
{
  int rval = 0;
  struct stat st;

  lt_debugprintf (__FILE__, __LINE__, "(make_executable): %s\n",
                  nonempty (path));
  if ((!path) || (!*path))
    return 0;

  if (stat (path, &st) >= 0)
    {
      rval = chmod (path, st.st_mode | S_IXOTH | S_IXGRP | S_IXUSR);
    }
  return rval;
}

/* Searches for the full path of the wrapper.  Returns
   newly allocated full path name if found, NULL otherwise
   Does not chase symlinks, even on platforms that support them.
*/
char *
find_executable (const char *wrapper)
{
  int has_slash = 0;
  const char *p;
  const char *p_next;
  /* static buffer for getcwd */
  char tmp[LT_PATHMAX + 1];
  size_t tmp_len;
  char *concat_name;

  lt_debugprintf (__FILE__, __LINE__, "(find_executable): %s\n",
                  nonempty (wrapper));

  if ((wrapper == NULL) || (*wrapper == '\0'))
    return NULL;

  /* Absolute path? */
#if defined HAVE_DOS_BASED_FILE_SYSTEM
  if (isalpha ((unsigned char) wrapper[0]) && wrapper[1] == ':')
    {
      concat_name = xstrdup (wrapper);
      if (check_executable (concat_name))
	return concat_name;
      XFREE (concat_name);
    }
  else
    {
#endif
      if (IS_DIR_SEPARATOR (wrapper[0]))
	{
	  concat_name = xstrdup (wrapper);
	  if (check_executable (concat_name))
	    return concat_name;
	  XFREE (concat_name);
	}
#if defined HAVE_DOS_BASED_FILE_SYSTEM
    }
#endif

  for (p = wrapper; *p; p++)
    if (*p == '/')
      {
	has_slash = 1;
	break;
      }
  if (!has_slash)
    {
      /* no slashes; search PATH */
      const char *path = getenv ("PATH");
      if (path != NULL)
	{
	  for (p = path; *p; p = p_next)
	    {
	      const char *q;
	      size_t p_len;
	      for (q = p; *q; q++)
		if (IS_PATH_SEPARATOR (*q))
		  break;
	      p_len = (size_t) (q - p);
	      p_next = (*q == '\0' ? q : q + 1);
	      if (p_len == 0)
		{
		  /* empty path: current directory */
		  if (getcwd (tmp, LT_PATHMAX) == NULL)
		    lt_fatal (__FILE__, __LINE__, "getcwd failed: %s",
                              nonnull (strerror (errno)));
		  tmp_len = strlen (tmp);
		  concat_name =
		    XMALLOC (char, tmp_len + 1 + strlen (wrapper) + 1);
		  memcpy (concat_name, tmp, tmp_len);
		  concat_name[tmp_len] = '/';
		  strcpy (concat_name + tmp_len + 1, wrapper);
		}
	      else
		{
		  concat_name =
		    XMALLOC (char, p_len + 1 + strlen (wrapper) + 1);
		  memcpy (concat_name, p, p_len);
		  concat_name[p_len] = '/';
		  strcpy (concat_name + p_len + 1, wrapper);
		}
	      if (check_executable (concat_name))
		return concat_name;
	      XFREE (concat_name);
	    }
	}
      /* not found in PATH; assume curdir */
    }
  /* Relative path | not found in path: prepend cwd */
  if (getcwd (tmp, LT_PATHMAX) == NULL)
    lt_fatal (__FILE__, __LINE__, "getcwd failed: %s",
              nonnull (strerror (errno)));
  tmp_len = strlen (tmp);
  concat_name = XMALLOC (char, tmp_len + 1 + strlen (wrapper) + 1);
  memcpy (concat_name, tmp, tmp_len);
  concat_name[tmp_len] = '/';
  strcpy (concat_name + tmp_len + 1, wrapper);

  if (check_executable (concat_name))
    return concat_name;
  XFREE (concat_name);
  return NULL;
}

char *
chase_symlinks (const char *pathspec)
{
#ifndef S_ISLNK
  return xstrdup (pathspec);
#else
  char buf[LT_PATHMAX];
  struct stat s;
  char *tmp_pathspec = xstrdup (pathspec);
  char *p;
  int has_symlinks = 0;
  while (strlen (tmp_pathspec) && !has_symlinks)
    {
      lt_debugprintf (__FILE__, __LINE__,
		      "checking path component for symlinks: %s\n",
		      tmp_pathspec);
      if (lstat (tmp_pathspec, &s) == 0)
	{
	  if (S_ISLNK (s.st_mode) != 0)
	    {
	      has_symlinks = 1;
	      break;
	    }

	  /* search backwards for last DIR_SEPARATOR */
	  p = tmp_pathspec + strlen (tmp_pathspec) - 1;
	  while ((p > tmp_pathspec) && (!IS_DIR_SEPARATOR (*p)))
	    p--;
	  if ((p == tmp_pathspec) && (!IS_DIR_SEPARATOR (*p)))
	    {
	      /* no more DIR_SEPARATORS left */
	      break;
	    }
	  *p = '\0';
	}
      else
	{
	  lt_fatal (__FILE__, __LINE__,
		    "error accessing file \"%s\": %s",
		    tmp_pathspec, nonnull (strerror (errno)));
	}
    }
  XFREE (tmp_pathspec);

  if (!has_symlinks)
    {
      return xstrdup (pathspec);
    }

  tmp_pathspec = realpath (pathspec, buf);
  if (tmp_pathspec == 0)
    {
      lt_fatal (__FILE__, __LINE__,
		"could not follow symlinks for %s", pathspec);
    }
  return xstrdup (tmp_pathspec);
#endif
}

char *
strendzap (char *str, const char *pat)
{
  size_t len, patlen;

  assert (str != NULL);
  assert (pat != NULL);

  len = strlen (str);
  patlen = strlen (pat);

  if (patlen <= len)
    {
      str += len - patlen;
      if (STREQ (str, pat))
	*str = '\0';
    }
  return str;
}

void
lt_debugprintf (const char *file, int line, const char *fmt, ...)
{
  va_list args;
  if (lt_debug)
    {
      (void) fprintf (stderr, "%s:%s:%d: ", program_name, file, line);
      va_start (args, fmt);
      (void) vfprintf (stderr, fmt, args);
      va_end (args);
    }
}

static void
lt_error_core (int exit_status, const char *file,
	       int line, const char *mode,
	       const char *message, va_list ap)
{
  fprintf (stderr, "%s:%s:%d: %s: ", program_name, file, line, mode);
  vfprintf (stderr, message, ap);
  fprintf (stderr, ".\n");

  if (exit_status >= 0)
    exit (exit_status);
}

void
lt_fatal (const char *file, int line, const char *message, ...)
{
  va_list ap;
  va_start (ap, message);
  lt_error_core (EXIT_FAILURE, file, line, "FATAL", message, ap);
  va_end (ap);
}

static const char *
nonnull (const char *s)
{
  return s ? s : "(null)";
}

static const char *
nonempty (const char *s)
{
  return (s && !*s) ? "(empty)" : nonnull (s);
}

void
lt_setenv (const char *name, const char *value)
{
  lt_debugprintf (__FILE__, __LINE__,
		  "(lt_setenv) setting '%s' to '%s'\n",
                  nonnull (name), nonnull (value));
  {
#ifdef HAVE_SETENV
    /* always make a copy, for consistency with !HAVE_SETENV */
    char *str = xstrdup (value);
    setenv (name, str, 1);
#else
    size_t len = strlen (name) + 1 + strlen (value) + 1;
    char *str = XMALLOC (char, len);
    sprintf (str, "%s=%s", name, value);
    if (putenv (str) != EXIT_SUCCESS)
      {
        XFREE (str);
      }
#endif
  }
}

char *
lt_extend_str (const char *orig_value, const char *add, int to_end)
{
  char *new_value;
  if (orig_value && *orig_value)
    {
      size_t orig_value_len = strlen (orig_value);
      size_t add_len = strlen (add);
      new_value = XMALLOC (char, add_len + orig_value_len + 1);
      if (to_end)
        {
          strcpy (new_value, orig_value);
          strcpy (new_value + orig_value_len, add);
        }
      else
        {
          strcpy (new_value, add);
          strcpy (new_value + add_len, orig_value);
        }
    }
  else
    {
      new_value = xstrdup (add);
    }
  return new_value;
}

void
lt_update_exe_path (const char *name, const char *value)
{
  lt_debugprintf (__FILE__, __LINE__,
		  "(lt_update_exe_path) modifying '%s' by prepending '%s'\n",
                  nonnull (name), nonnull (value));

  if (name && *name && value && *value)
    {
      char *new_value = lt_extend_str (getenv (name), value, 0);
      /* some systems can't cope with a ':'-terminated path #' */
      size_t len = strlen (new_value);
      while ((len > 0) && IS_PATH_SEPARATOR (new_value[len-1]))
        {
          new_value[--len] = '\0';
        }
      lt_setenv (name, new_value);
      XFREE (new_value);
    }
}

void
lt_update_lib_path (const char *name, const char *value)
{
  lt_debugprintf (__FILE__, __LINE__,
		  "(lt_update_lib_path) modifying '%s' by prepending '%s'\n",
                  nonnull (name), nonnull (value));

  if (name && *name && value && *value)
    {
      char *new_value = lt_extend_str (getenv (name), value, 0);
      lt_setenv (name, new_value);
      XFREE (new_value);
    }
}


/* Prepares an argument vector before calling spawn().
   Note that spawn() does not by itself call the command interpreter
     (getenv ("COMSPEC") != NULL ? getenv ("COMSPEC") :
      ({ OSVERSIONINFO v; v.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
         GetVersionEx(&v);
         v.dwPlatformId == VER_PLATFORM_WIN32_NT;
      }) ? "cmd.exe" : "command.com").
   Instead it simply concatenates the arguments, separated by ' ', and calls
   CreateProcess().  We must quote the arguments since Win32 CreateProcess()
   interprets characters like ' ', '\t', '\\', '"' (but not '<' and '>') in a
   special way:
   - Space and tab are interpreted as delimiters. They are not treated as
     delimiters if they are surrounded by double quotes: "...".
   - Unescaped double quotes are removed from the input. Their only effect is
     that within double quotes, space and tab are treated like normal
     characters.
   - Backslashes not followed by double quotes are not special.
   - But 2*n+1 backslashes followed by a double quote become
     n backslashes followed by a double quote (n >= 0):
       \" -> "
       \\\" -> \"
       \\\\\" -> \\"
 */
#define SHELL_SPECIAL_CHARS "\"\\ \001\002\003\004\005\006\007\010\011\012\013\014\015\016\017\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037"
#define SHELL_SPACE_CHARS " \001\002\003\004\005\006\007\010\011\012\013\014\015\016\017\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037"
char **
prepare_spawn (char **argv)
{
  size_t argc;
  char **new_argv;
  size_t i;

  /* Count number of arguments.  */
  for (argc = 0; argv[argc] != NULL; argc++)
    ;

  /* Allocate new argument vector.  */
  new_argv = XMALLOC (char *, argc + 1);

  /* Put quoted arguments into the new argument vector.  */
  for (i = 0; i < argc; i++)
    {
      const char *string = argv[i];

      if (string[0] == '\0')
	new_argv[i] = xstrdup ("\"\"");
      else if (strpbrk (string, SHELL_SPECIAL_CHARS) != NULL)
	{
	  int quote_around = (strpbrk (string, SHELL_SPACE_CHARS) != NULL);
	  size_t length;
	  unsigned int backslashes;
	  const char *s;
	  char *quoted_string;
	  char *p;

	  length = 0;
	  backslashes = 0;
	  if (quote_around)
	    length++;
	  for (s = string; *s != '\0'; s++)
	    {
	      char c = *s;
	      if (c == '"')
		length += backslashes + 1;
	      length++;
	      if (c == '\\')
		backslashes++;
	      else
		backslashes = 0;
	    }
	  if (quote_around)
	    length += backslashes + 1;

	  quoted_string = XMALLOC (char, length + 1);

	  p = quoted_string;
	  backslashes = 0;
	  if (quote_around)
	    *p++ = '"';
	  for (s = string; *s != '\0'; s++)
	    {
	      char c = *s;
	      if (c == '"')
		{
		  unsigned int j;
		  for (j = backslashes + 1; j > 0; j--)
		    *p++ = '\\';
		}
	      *p++ = c;
	      if (c == '\\')
		backslashes++;
	      else
		backslashes = 0;
	    }
	  if (quote_around)
	    {
	      unsigned int j;
	      for (j = backslashes; j > 0; j--)
		*p++ = '\\';
	      *p++ = '"';
	    }
	  *p = '\0';

	  new_argv[i] = quoted_string;
	}
      else
	new_argv[i] = (char *) string;
    }
  new_argv[argc] = NULL;

  return new_argv;
}
void lt_dump_script (FILE* f)
{
  fputs ("#! /bin/sh\n", f);
  fputs ("\n", f);
  fputs ("# reuse - temporary wrapper script for .libs/reuse.exe\n", f);
  fputs ("# Generated by libtool (GNU libtool) 2.4.6\n", f);
  fputs ("#\n", f);
  fputs ("# The reuse program cannot be directly executed until all the libtool\n", f);
  fputs ("# libraries that it depends on are installed.\n", f);
  fputs ("#\n", f);
  fputs ("# This wrapper script should never be moved out of the build directory.\n", f);
  fputs ("# If it is, it will not operate correctly.\n", f);
  fputs ("\n", f);
  fputs ("# Sed substitution that helps us do robust quoting.  It backslashifies\n", f);
  fputs ("# metacharacters that are still active within double-quoted strings.\n", f);
  fputs ("sed_quote_subst='s|\\([`\"$\\\\]\\)|\\\\\\1|g'\n", f);
  fputs ("\n", f);
  fputs ("# Be Bourne compatible\n", f);
  fputs ("if test -n \"${ZSH_VERSION+set}\" && (emulate sh) >/dev/null 2>&1; then\n", f);
  fputs ("  emulate sh\n", f);
  fputs ("  NULLCMD=:\n", f);
  fputs ("  # Zsh 3.x and 4.x performs word splitting on ${1+\"$@\"}, which\n", f);
  fputs ("  # is contrary to our usage.  Disable this feature.\n", f);
  fputs ("  alias -g '${1+\"$@\"}'='\"$@\"'\n", f);
  fputs ("  setopt NO_GLOB_SUBST\n", f);
  fputs ("else\n", f);
  fputs ("  case `(set -o) 2>/dev/null` in *posix*) set -o posix;; esac\n", f);
  fputs ("fi\n", f);
  fputs ("BIN_SH=xpg4; export BIN_SH # for Tru64\n", f);
  fputs ("DUALCASE=1; export DUALCASE # for MKS sh\n", f);
  fputs ("\n", f);
  fputs ("# The HP-UX ksh and POSIX shell print the target directory to stdout\n", f);
  fputs ("# if CDPATH is set.\n", f);
  fputs ("(unset CDPATH) >/dev/null 2>&1 && unset CDPATH\n", f);
  fputs ("\n", f);
  fputs ("relink_command=\"(cd /home/Administrator/gmp-6.2.0/tests/mpz; { test -z \\\"\\${LIB", f);
  fputs ("RARY_PATH+set}\\\" || unset LIBRARY_PATH || { LIBRARY_PATH=; export LIBRARY_PATH;", f);
  fputs (" }; }; { test -z \\\"\\${COMPILER_PATH+set}\\\" || unset COMPILER_PATH || { COMPILER", f);
  fputs ("_PATH=; export COMPILER_PATH; }; }; { test -z \\\"\\${GCC_EXEC_PREFIX+set}\\\" || un", f);
  fputs ("set GCC_EXEC_PREFIX || { GCC_EXEC_PREFIX=; export GCC_EXEC_PREFIX; }; }; { test", f);
  fputs (" -z \\\"\\${LD_RUN_PATH+set}\\\" || unset LD_RUN_PATH || { LD_RUN_PATH=; export LD_R", f);
  fputs ("UN_PATH; }; }; PATH=/mingw64/bin:/usr/local/bin:/usr/bin:/usr/bin:/c/Windows/Sy", f);
  fputs ("stem32:/c/Windows:/c/Windows/System32/Wbem:/c/Windows/System32/WindowsPowerShel", f);
  fputs ("l/v1.0:/usr/bin/site_perl:/usr/bin/vendor_perl:/usr/bin/core_perl; export PATH;", f);
  fputs (" PATH=/mingw64/bin:/usr/local/bin:/usr/bin:/usr/bin:/c/Windows/System32:/c/Wind", f);
  fputs ("ows:/c/Windows/System32/Wbem:/c/Windows/System32/WindowsPowerShell/v1.0:/usr/bi", f);
  fputs ("n/site_perl:/usr/bin/vendor_perl:/usr/bin/core_perl; export PATH; gcc -O2 -peda", f);
  fputs ("ntic -fomit-frame-pointer -m64 -mtune=k8 -march=k8 -o @OUTPUT@ reuse.o  ../../t", f);
  fputs ("ests/.libs/libtests.a -L/mingw64/lib -lgmp -L/mingw64/lib)\"\n", f);
  fputs ("\n", f);
  fputs ("# This environment variable determines our operation mode.\n", f);
  fputs ("if test \"$libtool_install_magic\" = \"%%%MAGIC variable%%%\"; then\n", f);
  fputs ("  # install mode needs the following variables:\n", f);
  fputs ("  generated_by_libtool_version='2.4.6'\n", f);
  fputs ("  notinst_deplibs=' /home/Administrator/gmp-6.2.0/libgmp.la ../../libgmp.la'\n", f);
  fputs ("else\n", f);
  fputs ("  # When we are sourced in execute mode, $file and $ECHO are already set.\n", f);
  fputs ("  if test \"$libtool_execute_magic\" != \"%%%MAGIC variable%%%\"; then\n", f);
  fputs ("    file=\"$0\"\n", f);
  fputs ("\n", f);
  fputs ("# A function that is used when there is no print builtin or printf.\n", f);
  fputs ("func_fallback_echo ()\n", f);
  fputs ("{\n", f);
  fputs ("  eval 'cat <<_LTECHO_EOF\n", f);
  fputs ("$1\n", f);
  fputs ("_LTECHO_EOF'\n", f);
  fputs ("}\n", f);
  fputs ("    ECHO=\"printf %s\\\\n\"\n", f);
  fputs ("  fi\n", f);
  fputs ("\n", f);
  fputs ("# Very basic option parsing. These options are (a) specific to\n", f);
  fputs ("# the libtool wrapper, (b) are identical between the wrapper\n", f);
  fputs ("# /script/ and the wrapper /executable/ that is used only on\n", f);
  fputs ("# windows platforms, and (c) all begin with the string --lt-\n", f);
  fputs ("# (application programs are unlikely to have options that match\n", f);
  fputs ("# this pattern).\n", f);
  fputs ("#\n", f);
  fputs ("# There are only two supported options: --lt-debug and\n", f);
  fputs ("# --lt-dump-script. There is, deliberately, no --lt-help.\n", f);
  fputs ("#\n", f);
  fputs ("# The first argument to this parsing function should be the\n", f);
  fputs ("# script's ../../libtool value, followed by yes.\n", f);
  fputs ("lt_option_debug=\n", f);
  fputs ("func_parse_lt_options ()\n", f);
  fputs ("{\n", f);
  fputs ("  lt_script_arg0=$0\n", f);
  fputs ("  shift\n", f);
  fputs ("  for lt_opt\n", f);
  fputs ("  do\n", f);
  fputs ("    case \"$lt_opt\" in\n", f);
  fputs ("    --lt-debug) lt_option_debug=1 ;;\n", f);
  fputs ("    --lt-dump-script)\n", f);
  fputs ("        lt_dump_D=`$ECHO \"X$lt_script_arg0\" | /usr/bin/sed -e 's/^X//' -e 's%/[", f);
  fputs ("^/]*$%%'`\n", f);
  fputs ("        test \"X$lt_dump_D\" = \"X$lt_script_arg0\" && lt_dump_D=.\n", f);
  fputs ("        lt_dump_F=`$ECHO \"X$lt_script_arg0\" | /usr/bin/sed -e 's/^X//' -e 's%^.", f);
  fputs ("*/%%'`\n", f);
  fputs ("        cat \"$lt_dump_D/$lt_dump_F\"\n", f);
  fputs ("        exit 0\n", f);
  fputs ("      ;;\n", f);
  fputs ("    --lt-*)\n", f);
  fputs ("        $ECHO \"Unrecognized --lt- option: '$lt_opt'\" 1>&2\n", f);
  fputs ("        exit 1\n", f);
  fputs ("      ;;\n", f);
  fputs ("    esac\n", f);
  fputs ("  done\n", f);
  fputs ("\n", f);
  fputs ("  # Print the debug banner immediately:\n", f);
  fputs ("  if test -n \"$lt_option_debug\"; then\n", f);
  fputs ("    echo \"reuse.exe:reuse:$LINENO: libtool wrapper (GNU libtool) 2.4.6\" 1>&2\n", f);
  fputs ("  fi\n", f);
  fputs ("}\n", f);
  fputs ("\n", f);
  fputs ("# Used when --lt-debug. Prints its arguments to stdout\n", f);
  fputs ("# (redirection is the responsibility of the caller)\n", f);
  fputs ("func_lt_dump_args ()\n", f);
  fputs ("{\n", f);
  fputs ("  lt_dump_args_N=1;\n", f);
  fputs ("  for lt_arg\n", f);
  fputs ("  do\n", f);
  fputs ("    $ECHO \"reuse.exe:reuse:$LINENO: newargv[$lt_dump_args_N]: $lt_arg\"\n", f);
  fputs ("    lt_dump_args_N=`expr $lt_dump_args_N + 1`\n", f);
  fputs ("  done\n", f);
  fputs ("}\n", f);
  fputs ("\n", f);
  fputs ("# Core function for launching the target application\n", f);
  fputs ("func_exec_program_core ()\n", f);
  fputs ("{\n", f);
  fputs ("\n", f);
  fputs ("      if test -n \"$lt_option_debug\"; then\n", f);
  fputs ("        $ECHO \"reuse.exe:reuse:$LINENO: newargv[0]: $progdir/$program\" 1>&2\n", f);
  fputs ("        func_lt_dump_args ${1+\"$@\"} 1>&2\n", f);
  fputs ("      fi\n", f);
  fputs ("      exec \"$progdir/$program\" ${1+\"$@\"}\n", f);
  fputs ("\n", f);
  fputs ("      $ECHO \"$0: cannot exec $program $*\" 1>&2\n", f);
  fputs ("      exit 1\n", f);
  fputs ("}\n", f);
  fputs ("\n", f);
  fputs ("# A function to encapsulate launching the target application\n", f);
  fputs ("# Strips options in the --lt-* namespace from $@ and\n", f);
  fputs ("# launches target application with the remaining arguments.\n", f);
  fputs ("func_exec_program ()\n", f);
  fputs ("{\n", f);
  fputs ("  case \" $* \" in\n", f);
  fputs ("  *\\ --lt-*)\n", f);
  fputs ("    for lt_wr_arg\n", f);
  fputs ("    do\n", f);
  fputs ("      case $lt_wr_arg in\n", f);
  fputs ("      --lt-*) ;;\n", f);
  fputs ("      *) set x \"$@\" \"$lt_wr_arg\"; shift;;\n", f);
  fputs ("      esac\n", f);
  fputs ("      shift\n", f);
  fputs ("    done ;;\n", f);
  fputs ("  esac\n", f);
  fputs ("  func_exec_program_core ${1+\"$@\"}\n", f);
  fputs ("}\n", f);
  fputs ("\n", f);
  fputs ("  # Parse options\n", f);
  fputs ("  func_parse_lt_options \"$0\" ${1+\"$@\"}\n", f);
  fputs ("\n", f);
  fputs ("  # Find the directory that this script lives in.\n", f);
  fputs ("  thisdir=`$ECHO \"$file\" | /usr/bin/sed 's%/[^/]*$%%'`\n", f);
  fputs ("  test \"x$thisdir\" = \"x$file\" && thisdir=.\n", f);
  fputs ("\n", f);
  fputs ("  # Follow symbolic links until we get to the real thisdir.\n", f);
  fputs ("  file=`ls -ld \"$file\" | /usr/bin/sed -n 's/.*-> //p'`\n", f);
  fputs ("  while test -n \"$file\"; do\n", f);
  fputs ("    destdir=`$ECHO \"$file\" | /usr/bin/sed 's%/[^/]*$%%'`\n", f);
  fputs ("\n", f);
  fputs ("    # If there was a directory component, then change thisdir.\n", f);
  fputs ("    if test \"x$destdir\" != \"x$file\"; then\n", f);
  fputs ("      case \"$destdir\" in\n", f);
  fputs ("      [\\\\/]* | [A-Za-z]:[\\\\/]*) thisdir=\"$destdir\" ;;\n", f);
  fputs ("      *) thisdir=\"$thisdir/$destdir\" ;;\n", f);
  fputs ("      esac\n", f);
  fputs ("    fi\n", f);
  fputs ("\n", f);
  fputs ("    file=`$ECHO \"$file\" | /usr/bin/sed 's%^.*/%%'`\n", f);
  fputs ("    file=`ls -ld \"$thisdir/$file\" | /usr/bin/sed -n 's/.*-> //p'`\n", f);
  fputs ("  done\n", f);
  fputs ("\n", f);
  fputs ("  # Usually 'no', except on cygwin/mingw when embedded into\n", f);
  fputs ("  # the cwrapper.\n", f);
  fputs ("  WRAPPER_SCRIPT_BELONGS_IN_OBJDIR=yes\n", f);
  fputs ("  if test \"$WRAPPER_SCRIPT_BELONGS_IN_OBJDIR\" = \"yes\"; then\n", f);
  fputs ("    # special case for '.'\n", f);
  fputs ("    if test \"$thisdir\" = \".\"; then\n", f);
  fputs ("      thisdir=`pwd`\n", f);
  fputs ("    fi\n", f);
  fputs ("    # remove .libs from thisdir\n", f);
  fputs ("    case \"$thisdir\" in\n", f);
  fputs ("    *[\\\\/].libs ) thisdir=`$ECHO \"$thisdir\" | /usr/bin/sed 's%[\\\\/][^\\\\/]*$%%'`", f);
  fputs (" ;;\n", f);
  fputs ("    .libs )   thisdir=. ;;\n", f);
  fputs ("    esac\n", f);
  fputs ("  fi\n", f);
  fputs ("\n", f);
  fputs ("  # Try to get the absolute directory name.\n", f);
  fputs ("  absdir=`cd \"$thisdir\" && pwd`\n", f);
  fputs ("  test -n \"$absdir\" && thisdir=\"$absdir\"\n", f);
  fputs ("\n", f);
  fputs ("  program='reuse.exe'\n", f);
  fputs ("  progdir=\"$thisdir/.libs\"\n", f);
  fputs ("\n", f);
  fputs ("\n", f);
  fputs ("  if test -f \"$progdir/$program\"; then\n", f);
  fputs ("    # Add the dll search path components to the executable PATH\n", f);
  fputs ("    PATH=/home/Administrator/gmp-6.2.0/.libs:/mingw64/lib:/mingw64/bin:$PATH\n", f);
  fputs ("\n", f);
  fputs ("    # Add our own library path to PATH\n", f);
  fputs ("    PATH=\"/home/Administrator/gmp-6.2.0/.libs:$PATH\"\n", f);
  fputs ("\n", f);
  fputs ("    # Some systems cannot cope with colon-terminated PATH\n", f);
  fputs ("    # The second colon is a workaround for a bug in BeOS R4 sed\n", f);
  fputs ("    PATH=`$ECHO \"$PATH\" | /usr/bin/sed 's/::*$//'`\n", f);
  fputs ("\n", f);
  fputs ("    export PATH\n", f);
  fputs ("\n", f);
  fputs ("    if test \"$libtool_execute_magic\" != \"%%%MAGIC variable%%%\"; then\n", f);
  fputs ("      # Run the actual program with our arguments.\n", f);
  fputs ("      func_exec_program ${1+\"$@\"}\n", f);
  fputs ("    fi\n", f);
  fputs ("  else\n", f);
  fputs ("    # The program doesn't exist.\n", f);
  fputs ("    $ECHO \"$0: error: '$progdir/$program' does not exist\" 1>&2\n", f);
  fputs ("    $ECHO \"This script is just a wrapper for $program.\" 1>&2\n", f);
  fputs ("    $ECHO \"See the libtool documentation for more information.\" 1>&2\n", f);
  fputs ("    exit 1\n", f);
  fputs ("  fi\n", f);
  fputs ("fi\n", f);
}
