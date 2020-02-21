[still in heavy developpement]

## libftprintf
* (((((ft_printf -> ft_vprintf) || (ft_asprintf)) ->  ft_vasprintf)

* ft_*(u || i)toa -> ft_ll(u || i)toa_base -> ft_llutoa_base
* ft_ftoa -> ft_dtoa -> ft_ldtoa 
* ft_modf -> ft_modfl 

### goal: 

reproduction of ALL printf features, up to 64 bits ints, up to 80 bits long doubles and all flags / field widths / precisions / qualifiers / specifiers and undefined behaviours under macos.
also implementation speed was not a goal, priority was more in code clarity and in DRY (aka don't repeat yourself) so that optimisations could be easily added later.

### allowed primitives functions:
* unistd.h
* stdlib.h
* limits.h

### extensibility:

* register a specifier simply before calling your printf using ft_register_specifier(...)
* delete a specifier simply before calling your printf using ft_delete_specifier(...)

### new specifiers
* %b for binary displaying of any mem region

### implementation notes
* gcc ... -D AT_EXIT=1 ... flag will likely boost printf speed by using a global variable for storing specifiers and callbacks association using atexit() instead of freeing the global variable at each printf exit.
* all functions that exist with a larger type will use the one with a larger type for avoiding repetitions 

### CREDITS:

- apple for hexfloat algo: https://opensource.apple.com/source/Libc/Libc-320/stdio/hexfloat.c.auto.html
- reactos for modf algo: https://github.com/mirror/reactos/blob/master/reactos/lib/sdk/crt/math/modf.c
- wikipedia for floating points with extended precision https://en.wikipedia.org/wiki/Extended_precision
