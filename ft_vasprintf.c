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

#include "libftprintf.h"

static t_bool		ft_free_g_specifiers()
{
    ft_lstclear(&g_specifiers, &free);
	return (TRUE);
}

static char         *ft_insert_nulls(t_list *str, t_list **nulls, char *s)
{
    t_list          *current_word;
    t_list          *current_null;
    size_t          y;

    y = 0;
    current_word = str;
    while (current_word)
    {
        current_null = *nulls;
        while (current_null)
        {
            if (((t_null*)current_null->content)->address == current_word->content)
            {
                s[y + ((t_null*)current_null->content)->index] = '\0';
                ft_lstdel_node(nulls, current_null, &free);
            }
            current_null = current_null->next;
        }
        y += ft_strlen(current_word->content);
        current_word = current_word->next;
    }
    return (s);
}

int					ft_vasprintf(char **ob, const char *fmt, va_list ap)
{
	int				oi;
    char            *prev;
    t_list          *str;
    t_list          *nulls;

	if (!ft_boot_specifiers())
		return (-ft_free_g_specifiers());
	if (!g_specifiers && AT_EXIT)
		atexit((void(*)(void))ft_free_g_specifiers);
    str = NULL;
    prev = (char*)fmt;
	oi = 0;
    nulls = NULL;
    while (*fmt)
        if (*fmt++ == '%' && ++oi)
        {
            if (!ft_lststradd(&str, ft_substr(prev, 0, (fmt - 1) - prev)) ||
                !ft_lststradd(&str, ft_argtoa(&fmt, ap, oi, &nulls)))
                return (-((!AT_EXIT && ft_free_g_specifiers()) || 1));
            prev = (void*)fmt;
        }
    if (prev != fmt && !ft_lststradd(&str, ft_substr(prev, 0, fmt - prev)))
        oi = -42;
    else
        oi = (!(*ob = ft_lststrjoin(str))) ? -42 : ft_strlen(*ob);
    *ob = ft_insert_nulls(str, &nulls, *ob);
//    (void) ft_insert_nulls;
    ft_lstclear(&str, &free);
    ft_lstclear(&nulls, &free);
    return (oi + (!AT_EXIT && ft_free_g_specifiers() && 0));
}
