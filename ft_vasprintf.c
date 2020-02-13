/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vasprintf.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:39:04 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 10:59:04 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

static void			ft_free_gconvertor_content(void *v)
{
	free(v);
}

static t_bool		ft_free_gconvertor()
{
	ft_lstclear(&g_convertors, &ft_free_gconvertor_content);
	g_convertors = NULL;
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

	if (ob && !g_convertors && ft_boot_convertors() && AT_EXIT)
			atexit((void(*)(void))ft_free_gconvertor);
    str = NULL;
    prev = (char*)fmt;
    while (*fmt)
        if (*fmt++ == '%')
        {
            if (!(gen = ft_substr(prev, 0, (fmt - 1) - prev)))
            {
                ft_lstclear(&str, &ft_free_str);
                return ( - ((!AT_EXIT && ft_free_gconvertor()) || 1));
            }
            if (!(new = ft_lstnew(gen)))
            {
                free(gen);
                ft_lstclear(&str, &ft_free_str);
                return ( - ((!AT_EXIT && ft_free_gconvertor()) || 1));
            }
            ft_lstadd_back(&str, new);
            if (!(gen = ft_argtoa(&fmt, ap)))
            {
                ft_lstclear(&str, &ft_free_str);
                return ( - ((!AT_EXIT && ft_free_gconvertor()) || 1));
            }
            prev = (char*)fmt;
            if (!(new = ft_lstnew(gen)))
            {
                free(gen);
                ft_lstclear(&str, &ft_free_str);
                return ( - ((!AT_EXIT && ft_free_gconvertor()) || 1));
			}
            ft_lstadd_back(&str, new);
        }
    
    if (!AT_EXIT)
        ft_free_gconvertor();
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
