AM_CPPFLAGS = -I$(top_srcdir)/include

bin_PROGRAMS = test
test_SOURCES = test.c
test_LDADD = ../libopenbsd/libopenbsd.a
man1_MANS = test.1

install-exec-hook:
	ln -sf test $(DESTDIR)$(bindir)/[
