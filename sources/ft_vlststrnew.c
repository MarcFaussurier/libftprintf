#include "libftprintf.h"

t_list				*ft_vlststrnew(unsigned int n, va_list ap)
{
	t_list			*o;
	unsigned int	y;
	char			*s;

	y = 0;
	o = NULL;
	while (++y <= n && (s = va_arg(ap, char *)))
		if (!s)
			break;
		else if (!(ft_lststradd(&o, s)))
		{
			ft_lstclear(&o, &free);
			return (NULL);
		}
	return (o);
}
