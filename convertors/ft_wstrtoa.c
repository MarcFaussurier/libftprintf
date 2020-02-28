#include "libftprintf.h"



char	    *ft_wchartoa(wchar_t w)
{
	int		i;
    char    *o;

    o = malloc(5);
	i = 0;
	if (w <= CHAR_MAX)
		o[i++] = (w & 0x7f) | 0;
	else if (w <= SHRT_MAX)
    {
		o[i++] = (w >> 6) + 0xC0;
        o[i++] = (w & 0x3f) + 0x80;
    }
    else if (w <= 0xFFFF)
    {
        o[i++] = (w >> 12) + 0xE0;
        o[i++] = ((w >> 6) & 0x3F) + 0x80;
        o[i++] = (w & 0x3F) + 0x80;
    }
    else
    {
        o[i++] = (w >> 18) + 0xF0;
        o[i++] = ((w >> 12) & 0x3F) + 0x80;
        o[i++] = ((w >> 6) & 0x3F) + 0x80;
        o[i++] = (w & 0x3F) + 0x80;
    }
    o[i] = '\0';
    return (o);
}

char                *ft_wstrtoa(wchar_t *str)
{
    t_list          *o;
    char            *s;

    o = NULL;
    while (*str)
    {

        if (!ft_lststradd(&o, ft_wchartoa(*str)))
        {
            ft_lstclear(&o, &free);
            return (NULL);
        }
        str += 1;
    }
    s = ft_lststrjoin(o);
    ft_lstclear(&o, &free);
    return (s);
}
