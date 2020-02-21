[still in heavy developpement]

## libftprintf

reproduction of printf, with 64 bits int and 80 bits long doubles.
also implementation speed was not a goal, priority was more in code clarity and extensibility.

### allowed primitives:
* unistd.h    read()      write()
* stdlib.h    malloc()    free()
* stdargs.h   va_*()

### extensibility:

* register a specifier simply before calling your printf using ft_register_specifier()
* delete a specifier simply before calling your printf using ft_delete_specifier()

### new specifiers
* %b for binary displaying of any mem region

### implementation notes
* gcc ... -D AT_EXIT=1 ... flag will likely boost printf speed by using a global variable for storing specifiers and callbacks association using atexit() instead of freeing the global variable at each printf exit.
* all functions that exist with a larger type will use the one with a larger type for avoiding repetitions 

### CREDITS:

- apple for hexfloat algo: https://opensource.apple.com/source/Libc/Libc-320/stdio/hexfloat.c.auto.html
- reactos for modf algo: https://github.com/mirror/reactos/blob/master/reactos/lib/sdk/crt/math/modf.c
- wikipedia for floating points with extended precision https://en.wikipedia.org/wiki/Extended_precision
