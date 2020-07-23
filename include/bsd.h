#define _BSD_SOURCE

#include <sys/types.h>
#include <sys/sysmacros.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <termios.h>

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

/* TTY SHIT START */
#define	TTYDEF_IFLAG	(BRKINT | ICRNL | IMAXBEL | IXON | IXANY)
#define TTYDEF_OFLAG	(OPOST | ONLCR)
#define TTYDEF_LFLAG	(ECHO | ICANON | ISIG | IEXTEN | ECHOE|ECHOKE|ECHOCTL)
#define TTYDEF_CFLAG	(CREAD | CS8 | HUPCL)
#define TTYDEF_SPEED	(B9600)

#define CTRL(x)	(x&037)
#define	CEOF		CTRL('d')
#define	CEOL		((unsigned char)'\377')	/* XXX avoid _POSIX_VDISABLE */
#define	CERASE		0177
#define	CINTR		CTRL('c')
#define	CSTATUS		((unsigned char)'\377')	/* XXX avoid _POSIX_VDISABLE */
#define	CKILL		CTRL('u')
#define	CMIN		1
#define	CQUIT		034		/* FS, ^\ */
#define	CSUSP		CTRL('z')
#define	CTIME		0
#define	CDSUSP		CTRL('y')
#define	CSTART		CTRL('q')
#define	CSTOP		CTRL('s')
#define	CLNEXT		CTRL('v')
#define	CDISCARD 	CTRL('o')
#define	CWERASE 	CTRL('w')
#define	CREPRINT 	CTRL('r')
#define	CEOT		CEOF
/* compat */
#define	CBRK		CEOL
#define CRPRNT		CREPRINT
#define	CFLUSH		CDISCARD

#define VDSUSP		11	/* ISIG */

#define	TIOCEXT		_IOW('t', 96, int)	/* pty: external processing */
#define	TIOCSTOP	 _IO('t', 111)		/* stop output, like ^S */
#define	TIOCSTART	 _IO('t', 110)		/* start output, like ^Q */
#define	TTYDISC		0		/* termios tty line discipline */

#define ALTWERASE	0x00000200	/* use alternate WERASE algorithm */

#define OXTABS		0x00000004	/* expand tabs to spaces */
#define ONOEOT		0x00000008	/* discard EOT's (^D) on output */

#define	PPPDISC		5		/* ppp discipline */
#define	NMEADISC	7		/* NMEA0183 discipline */
/* TTY SHIT END */

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

