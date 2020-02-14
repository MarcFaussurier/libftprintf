/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vasprintf.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:39:04 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 10:51:14 by mfaussur    ###    #+. /#+    ###.fr     */
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
	ft_lstclear(&g_specifiers, &ft_free_g_specifiers_content);
	g_specifiers = NULL;
	return (TRUE);
}

static void         ft_free_str(void *itm)
{
    free(itm);
}


int					ft_vasprintf(char const **ob, const char *fmt, va_list ap)
{
	int				oi;
	char			*gen;
    char            *prev;
    t_list          *str;
    t_list          *new;

	if (ob && !g_specifiers && ft_boot_specifiers() && AT_EXIT)
			atexit((void(*)(void))ft_free_g_specifiers);
    str = NULL;
    prev = (char*)fmt;
	oi = 0;
    while (*fmt)
        if (*fmt++ == '%' && ++oi)
        {
            if (!(gen = ft_substr(prev, 0, (fmt - 1) - prev)))
            {
                ft_lstclear(&str, &ft_free_str);
                return ( - ((!AT_EXIT && ft_free_g_specifiers()) || 1));
            }
            if (!(new = ft_lstnew(gen)))
            {
                free(gen);
                ft_lstclear(&str, &ft_free_str);
                return ( - ((!AT_EXIT && ft_free_g_specifiers()) || 1));
            }
            ft_lstadd_back(&str, new);
            if (!(gen = ft_argtoa(&fmt, ap, oi)))
            {
                ft_lstclear(&str, &ft_free_str);
                return ( - ((!AT_EXIT && ft_free_g_specifiers()) || 1));
            }
            prev = (char*)fmt;
            if (!(new = ft_lstnew(gen)))
            {
                free(gen);
                ft_lstclear(&str, &ft_free_str);
                return ( - ((!AT_EXIT && ft_free_g_specifiers()) || 1));
			}
            ft_lstadd_back(&str, new);
        }
    
    if (!AT_EXIT)
        ft_free_g_specifiers();
    if (prev != fmt)
    {
        gen = ft_substr(prev, 0, fmt - prev);
        if (!gen)
        {
            ft_lstclear(&str, &ft_free_str);
            return (-42);
        }
        new = ft_lstnew(gen);
        if (!new)
        {
            free(gen);
            ft_lstclear(&str, &ft_free_str);
            return (-42);
        }
        ft_lstadd_back(&str, new);
    }
    oi = (!(*ob = ft_lststrjoin(str))) ? -42 : ft_strlen(*ob);
    ft_lstclear(&str, &ft_free_str);
    return (oi);
}
