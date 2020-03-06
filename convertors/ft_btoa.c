#include "libftprintf.h"

static char					*ft_reccursive_btoba(unsigned char b, unsigned char index)
{
	char					*out;
    size_t                  size;

    size = 1;
	if (index >= size * 8)
	{
		printf("\n");
		out = malloc((index + 1) * size);
		out[index] = '\0';
		return (out);
	}
	out = ft_reccursive_btoba(b >> 1, index + 1);
	out[size * 8 - index - 1] = (b & 1 ? 1 : 0) + '0';
	return (out);
}

char       *ft_btoa(void *ptr, size_t size)
{
    t_list          *str;
    void            *begin;
    str = NULL;
    begin = ptr + size - 1;
    while(1)
    {
        if (!ft_lststradd(&str, ft_reccursive_btoba(*((unsigned char*) begin), 0)))
            ft_lstclear(&str, &free);
        if (begin-- == ptr)
            break ;
        else if (!ft_lststradd(&str, ft_strdup(" ")))
            ft_lstclear(&str, &free);
    }
    return (ft_lststrjoin(str));
}

