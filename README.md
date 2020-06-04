## libftprintf de [mfaussur](mailto:mfaussur@student.42lyon.fr?subject=[GitHub:%20libftprintf]%20) 🇫🇷🇪🇺🌍
Reproduction of official apple's closed-source printf used in MacOS 10.13, with 64-bits integers, 80-bits floating points, undefined behaviours, and a new %b specifier designed to work with binary data so easily (cf. notes). Also implementation speed was not a goal, priority was more in code clarity, extensibility and limit-less inputs (I rely on RAM instead of a hard-coded limited string in the CPU cache, cf. [Linus Torvalds's printf](https://github.com/spotify/linux/blob/master/arch/x86/boot/printf.c)). This project targets the AINSI C99 specification.

### primitives
* unistd.h&nbsp;&nbsp;&nbsp;&nbsp;read()&nbsp;&nbsp;&nbsp;write()
* stdlib.h&nbsp;&nbsp;&nbsp;&nbsp;malloc()&nbsp;&nbsp;&nbsp;free()
* stdargs.h&nbsp;&nbsp;&nbsp;&nbsp;va_*()

### extensibility
* register a specifier simply before calling your printf using ft_register_specifier()
* delete a specifier simply before calling your printf using ft_delete_specifier()

Both funtions rely on AT_EXIT=1 (cf. notes). 

### notes
* use %b to work with binary data using a pointer. This specifier is obviously compatible with regular precision / padding attributes.
```c
long double x;

x = 1;
ft_printf("%#b", sizeof(long double), &x)
->  01101000 11001010 01101011 10111111 00011000 10100100 00111111 11111111 10000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
```
For regular types, you can also use the regular qualifiers.
```c
size_t x;

x = 1;
ft_printf("%zb", &x)
->  00000000 00000000 00000000 00000001
```

* gcc ... -D AT_EXIT=1 ... compilation flag will enable the use of a global variable for storing specifier to callback associations, this global variable will then be freed at exit, using stdlib.h's atexit().
* gcc ... -D LDMAXPRECISION=1024 ... compilation will modify the max precision that printf will support when handling long doubles.
* all functions that exist with a larger type will use the one with a larger type for avoiding repetitions.
* %Lf&nbsp;is different from original %Lf flag under macos when the decimal part of a long double exeeds 16-18 digits.
* %ls and %lc dont support unicode after a setlocale() because we are not allowed to rely on it (cf. primitives), so I use the default behaviour and I dont rely on any utf conversion. No garbage in - garbage out.


### Coming soon 
- [ ] %e
- [ ] %a 
- [ ] %g
