#include <libftprintf.h>

char           *ft_stoa(t_specifier_state state, char *si)
{
    char        *output;
    int         len;
    int         field_width;
    int         i;
    size_t      strsize;
    char        *str;

	if (!si)
		si = ft_strdup("(null)");
	len = ft_strnlen(si, state.precision);
    field_width = state.padding;
    strsize = 0;
	if ((i = -1) && !(state.flags.minus))
        while (len < field_width-- && ++strsize)
    		;
    while (++i < len && ++strsize)
    	;
	while (len < field_width-- && ++strsize)
    	;
	printf("strsize: %lu\n", strsize);
	if (!(output = malloc(strsize)) || (strsize = 0))
        return (NULL);
	str = output;
    field_width = state.padding;
    if (!(state.flags.minus))
        while (len < field_width--)
            *str++ = state.flags.zero ? '0' : ' ';
    i = 0;
    while (i < len)
    {
        *str++ = *si++;
        i += 1;
    }
    while (len < field_width--)
        *str++ = ' ';
    return (output);
}
