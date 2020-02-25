## libftprintf
Reproduction of printf, with 64 bits int and 80 bits long double. Also implementation speed was not a goal, priority was more in code clarity and extensibility. This project is still under construction.

### primitives
* unistd.h&nbsp;&nbsp;&nbsp;&nbsp;read()&nbsp;&nbsp;&nbsp;write()
* stdlib.h&nbsp;&nbsp;&nbsp;&nbsp;malloc()&nbsp;&nbsp;&nbsp;free()
* stdargs.h&nbsp;&nbsp;&nbsp;&nbsp;va_*()

### extensibility
* register a specifier simply before calling your printf using ft_register_specifier()
* delete a specifier simply before calling your printf using ft_delete_specifier()

### notes
* gcc ... -D AT_EXIT=1 ... compilation flag will enable the use of a global variable for storing specifier to callback associations, this global variable will then be freed at exit, using stdlib.h's atexit()
* gcc ... -D LDMAXPRECISION=1024 ... compilation will modify the max precision that printf will use for handling long doubles.
* all functions that exist with a larger type will use the one with a larger type for avoiding repetitions 
* %b &nbsp;is a new specifier for displaying a pointed value in its binary representation (use qualifiers or field width for passing the number of bits to show)
* %Lf&nbsp;is different from original %Lf flag under macos when the decimal part of a long double exeeds 16-18 digits

### credits
* reactos for modf algo: https://github.com/mirror/reactos/blob/master/reactos/lib/sdk/crt/math/modf.c

