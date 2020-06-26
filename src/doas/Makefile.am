AM_CPPFLAGS = -I$(top_srcdir)/include
AM_LDFLAGS = -lcrypt

bin_PROGRAMS = doas
doas_SOURCES = parse.y oasis.c doas.c env.c
doas_LDADD = ../libopenbsd/libopenbsd.a
man1_MANS = doas.1
man5_MANS = doas.conf.5

install-exec-hook:
	chmod 4555 $(DESTDIR)$(bindir)/doas
