## libftprintf
Reproduction of printf, with 64 bits int and 80 bits long doubles. Also implementation speed was not a goal, priority was more in code clarity and extensibility. This project is still under construction.

### primitives
* unistd.h&nbsp;&nbsp;&nbsp;read()&nbsp;&nbsp;&nbsp;write()
* stdlib.h&nbsp;&nbsp;&nbsp;malloc()&nbsp;&nbsp;&nbsp;free()
* stdargs.h&nbsp;&nbsp;&nbsp;&nbsp;va_*()

### extensibility
* register a specifier simply before calling your printf using ft_register_specifier()
* delete a specifier simply before calling your printf using ft_delete_specifier()

### notes
* gcc ... -D AT_EXIT=1 ... flag will likely boost printf speed by using a global variable for storing specifiers and callbacks association using atexit() instead of freeing the global variable at each printf exit.
* all functions that exist with a larger type will use the one with a larger type for avoiding repetitions 
* %b is a new specifier for displaying a variable in its binary representation

### credits
* reactos for modf algo: https://github.com/mirror/reactos/blob/master/reactos/lib/sdk/crt/math/modf.c

