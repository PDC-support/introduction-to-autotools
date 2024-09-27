# Overview

* autoconf

* automake

* Debugging packages configured using Autotools

---

# What are autotools?

- GNU Autotools is a suite of tools used to automate the
  *configuration*, *building*, and *installation* of software packages
  across different systems.

- Typical installation of a package using GNU Autotools
```
./configure
make
make install
```

---

# Example

main.c:
```
#include <netdb.h>
#include <stdio.h>

int main() {
    struct hostent *host;
    host = gethostbyname("www.pdc.kth.se");
    ip = host->h_addr_list[0];
    printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    return 0;
}
```

* `gethostbyname()` is provided by libnsl on Solaris

---

# Example 1

configure.ac:
```
AC_INIT([example1], [1.0])

AC_SEARCH_LIBS([gethostbyname], [nsl])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
```

Makefile.in:
```
example1:
	gcc -o example1 main.c @LIBS@
```

`./configure` will now produce a `Makefile` from `Makefile.in` replacing @LIBS@ with the proper value (-lnsl on those systems which provide gethostbyname through libnsl)

---

# What is autoconf?

- Part of the GNU build system

- Tool for producing shell scripts that automatically configure software source code packages to adapt to many kinds of Posix-like systems

  - Running `autoconf` will take `configure.ac` as input
    and produce `configure`

- The autoconf tool is not required when *building* the package:

  - `./configure` will run tests, take `Makefile.in` as input
    and produce `Makefile`

<!-- more thorough + replace with graphics -->

---

# Inner workings of autoconf

- `configure.ac` as well as the tests are written in the macro language M4

- The `configure` script is a Bourne shell script

---

# Some useful existing tests

| Test                                    | Description                               |
| ----                                    | -----------                               |
| `AC_SEARCH_LIBS(FUNCTION, SEARCH_LIBS)` | Search for `FUNCTION` among `SEARCH_LIBS` |
| `AC_CHECK_LIB(LIBRARY, FUNCTION)`       | Search for `LIBRARY` providing `FUNCTION` |
| `AC_CHECK_FUNCS(FUNCTION...)`           | Define `HAVE_FUNCTION` if found           |
| `AC_CHECK_HEADER(HEADER-FILE)`          | Define `HAVE_HEADER-FILE` if found        |
|                                         |                                           |

---

# Example 2

<!-- TODO -->

test existence of alternative to gethostname

Use CC, CFLAGS etc in Makefile.in

---

# Mini-demo on computer (pause/relief)

---

#  What is automake?

- Writing `Makefile.in` for complex projects can get tedius and repetitive

- Automake simplifies and automates the making of Makefiles

- Takes `Makefile.am` and produces `Makefile.in`for `./configure`

- A `Makefile.am` is essentially a set of variable definitions.

---

# Example 3



---

# Invoking configure

options, like --prefix

Separate source and build directories

När man utvecklar ett program:

./configure CFLAGS="-g"

./config.status

---

# Debugging autotools

config.h

config.log

example

wrong version

---

# Hands-on

HackMD (globalt dokument)

Exercises

1. autoconf

2. automake

3. Finding a problem


---

# Hands-on

* autoconf

* automake

* Debugging problems
