/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vasprintf.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:39:04 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/07 09:11:56 by mfaussur    ###    #+. /#+    ###.fr     */
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
    t_list          *swp;
    size_t          y;

    y = 0;
    current_word = str;
    while (current_word)
    {
        current_null = *nulls;
        while (current_null)
        {
            swp = current_null->next;
            if (((t_null*)current_null->content)->address == current_word->content)
            {
                s[y + ((t_null*)current_null->content)->index] = '\0';
                ft_lstdel_node(nulls, current_null, &free);
            }
            current_null = swp;
        }
        y += ft_strlen(current_word->content);
        current_word = current_word->next;
    }
    return (s);
}

int					ft_vasprintf(char **ob, const char *fmt, va_list ap)
{
    char            *prev;
    t_list          *str;
    t_list          *nulls;
    int             oi;

	if (!ft_boot_specifiers())
		return (-ft_free_g_specifiers());
	if (!g_specifiers && AT_EXIT)
		atexit((void(*)(void))ft_free_g_specifiers);
    str = NULL;
    *ob = NULL;
    prev = (char*)fmt;
    nulls = NULL;
    while (*fmt)
        if (*fmt++ == '%')
        {
            if (!ft_lststradd(&str, ft_substr(prev, 0, (fmt - 1) - prev)) ||
                !ft_lststradd(&str, ft_argtoa(&fmt, str, &nulls, ap)))
	    {
			*ob = ft_strdup("");
		    return (-((!AT_EXIT && ft_free_g_specifiers()) || 1));
	    }
	    prev = (void*)fmt;
        }
    if ((prev != fmt && !ft_lststradd(&str, ft_substr(prev, 0, fmt - prev))) || (!(*ob = ft_lststrjoin(str))))
        oi = -42;
    else
        oi = ft_strlen(*ob);
   if (oi > 0)
        *ob = ft_insert_nulls(str, &nulls, *ob);
   else
   {
        if (*ob)
            free(*ob);
       *ob = ft_strdup("");
   }
   ft_lstclear(&str, &free);
    ft_lstclear(&nulls, &free);
    return (oi + (!AT_EXIT && ft_free_g_specifiers() && 0));
}
