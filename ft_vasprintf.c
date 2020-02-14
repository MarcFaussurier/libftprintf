/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vasprintf.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:39:04 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 12:18:26 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

static void			ft_free_g_specifiers_content(void *v)
{
	free(v);
}

static t_bool		ft_free_g_specifiers()
{
	if (g_specifiers)
        ft_lstclear(&g_specifiers, &ft_free_g_specifiers_content);
	g_specifiers = NULL;
	return (TRUE);
}

int					ft_vasprintf(char const **ob, const char *fmt, va_list ap)
{
	int				oi;
    char            *prev;
    t_list          *str;

	if (ob && !g_specifiers && ft_boot_specifiers() && AT_EXIT)
			atexit((void(*)(void))ft_free_g_specifiers);
    str = NULL;
    prev = (char*)fmt;
	oi = 0;
    while (*fmt)
        if (*fmt++ == '%' && ++oi)
        {
            if (!ft_lststradd(&str, ft_substr(prev, 0, (fmt - 1) - prev)) ||
                !ft_lststradd(&str, ft_argtoa(&fmt, ap, oi)))
                return (-((!AT_EXIT && ft_free_g_specifiers()) || 1));
            prev = (char*)fmt;
        }
    if (!AT_EXIT)
        ft_free_g_specifiers();
    if (prev != fmt && !ft_lststradd(&str, ft_substr(prev, 0, fmt - prev)))
            return (-1);
    oi = (!(*ob = ft_lststrjoin(str))) ? -42 : ft_strlen(*ob);
    ft_lstclear(&str, &free);
    return (oi);
}
