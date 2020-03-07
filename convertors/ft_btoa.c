#include "libftprintf.h"

static char					*ft_reccursive_btoba(unsigned char b, unsigned char index)
{
	char					*out;

	if (index >= 8)
	{
		out = malloc(9);
		out[8] = '\0';
		return (out);
	}
	out = ft_reccursive_btoba(b >> 1, index + 1);
	out[8 - index - 1] = (b & 1) + '0';
	return (out);
}

char       *ft_btoa(void *ptr, size_t size)
{
    t_list          *str;
    void            *begin;
    char            *o;

    str = NULL;
    begin = ptr + size - 1;
    while(1)
    {
        if (!ft_lststradd(&str, ft_reccursive_btoba(*((unsigned char*) begin), 0)))
            return (NULL);
        if (begin-- == ptr)
            break ;
        else if (!ft_lststradd(&str, ft_strdup(" ")))
            return (NULL);
    }
    o = ft_lststrjoin(str);
    ft_lstclear(&str, &free);
    return (o);
}


