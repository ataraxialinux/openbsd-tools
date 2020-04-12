#include <sys/types.h>
#include <sys/sysmacros.h>
#include <stddef.h>
#include <stdarg.h>

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

typedef va_list __va_list;
struct __sFILE;

void		warnc(int, const char *, ...)
			__attribute__((__format__ (printf, 2, 3)));
void		vwarnc(int, const char *, __va_list)
			__attribute__((__format__ (printf, 2, 0)));
void	*reallocarray(void *, size_t, size_t);
char *ctime(const time_t *);
long long
	 strtonum(const char *, long long, long long, const char **);
char   *fparseln(struct __sFILE *, size_t *, size_t *, const char[3], int);
