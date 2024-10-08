# Exercise 2

hello.c:
```
#include <stdio.h>

int main(int args, char *argv[]) {
  printf("Hello world!\n");
}
```

Makefile.am:
```
bin_PROGRAMS = pdcip hello
pdcip_SOURCES = main.c
hello_SOURCES = hello.c
```

---

# Exercise 3

Output from `./configure --with-libxml2`:
```
checking for xmlBufferCreate... no
configure: error: in `/home/mdj/pdc/build-systems/solutions/exercise3':
configure: error: Couldn't find xmlBufferCreate in libxml2
See `config.log' for more details
```

---

# Exercise 3

config.log:
```
configure:4490: checking for xmlBufferCreate
configure:4490: gcc -o conftest  -I/usr/include/libxml2    conftest.c  >&5
/usr/bin/ld: /tmp/ccdVqi8W.o: in function `main':
conftest.c:(.text+0xa): undefined reference to `xmlBufferCreate'
collect2: error: ld returned 1 exit status
```

---

# Exercise 3

configure.ac:
```
if test "$with_libxml2" != "no"; then
    PKG_CHECK_MODULES([LIBXML2], [libxml-2.0])
    AC_DEFINE([WITH_LIBXML2], [1], [Define if building with libxml2])
    CFLAGS="$CFLAGS $LIBXML2_CFLAGS"
    AC_CHECK_FUNCS([xmlBufferCreate], [],
       [AC_MSG_FAILURE([Couldn't find xmlBufferCreate in libxml2])])
else
    AC_MSG_WARN([libxml2 not used])
fi
```

---

# Exercise 3

configure.ac:
```
if test "$with_libxml2" != "no"; then
    PKG_CHECK_MODULES([LIBXML2], [libxml-2.0])
    AC_DEFINE([WITH_LIBXML2], [1], [Define if building with libxml2])
    CFLAGS="$CFLAGS $LIBXML2_CFLAGS"
    LIBS="$LIBS $LIBXML2_LIBS"
    AC_CHECK_FUNCS([xmlBufferCreate], [],
       [AC_MSG_FAILURE([Couldn't find xmlBufferCreate in libxml2])])
else
    AC_MSG_WARN([libxml2 not used])
fi
```
