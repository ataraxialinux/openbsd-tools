#include <sys/termios.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

#define	__attribute__(x)
#define __dead		__attribute__((__noreturn__))
#define __pure		__attribute__((__const__))
#define	__unused	__attribute__((__unused__))

#ifndef __GLIBC__
#if defined(__cplusplus)
#define	__BEGIN_EXTERN_C	extern "C" {
#define	__END_EXTERN_C		}
#else
#define	__BEGIN_EXTERN_C
#define	__END_EXTERN_C
#endif

#define	__BEGIN_DECLS	__BEGIN_EXTERN_C
#define	__END_DECLS	__END_EXTERN_C
#endif

#if !defined(DEF_WEAK)
#define DEF_WEAK(x)
#endif

#define UID_MAX	UINT_MAX
#define GID_MAX	UINT_MAX
#define _PW_BUF_LEN		1024	/* length of getpw*_r buffer */
#define	_PASSWORD_LEN		128	/* max length, not counting NUL */
#define TCSASOFT	0x10		/* flag - don't alter h.w. state */
#define VSTATUS		18	/* ICANON */

typedef va_list __va_list;
struct __sFILE;

#ifdef __GLIBC__
size_t	 strlcat(char *, const char *, size_t)
		__attribute__ ((__bounded__(__string__,1,3)));
size_t	 strlcpy(char *, const char *, size_t)
		__attribute__ ((__bounded__(__string__,1,3)));
#endif

void		warnc(int, const char *, ...)
			__attribute__((__format__ (printf, 2, 3)));
void		vwarnc(int, const char *, __va_list)
			__attribute__((__format__ (printf, 2, 0)));
void	*reallocarray(void *, size_t, size_t);
char *ctime(const time_t *);
long long
	 strtonum(const char *, long long, long long, const char **);
char	*fgetln(FILE *, size_t *);
char   *fparseln(struct __sFILE *, size_t *, size_t *, const char[3], int);
__dead void	errc(int, int, const char *, ...)
			__attribute__((__format__ (printf, 3, 4)));
__dead void	verrc(int, int, const char *, __va_list)
			__attribute__((__format__ (printf, 3, 0)));
extern const char* getprogname(void);
extern void setprogname(const char*);
