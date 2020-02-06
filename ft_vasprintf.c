/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vasprintf.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:39:04 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 13:35:17 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

static void			ft_free_gconvertor_content(void *v)
{
	free(v);
}

static void			ft_free_gconvertor()
{
	ft_lstclear(&g_convertors, &ft_free_gconvertor_content);
	g_convertors = NULL;
}

static void         ft_free_str(void *itm)
{
    free(itm);
}

char                *ft_lststrjoin(t_list *lst)
{
    size_t          output_len;
    char            *output;
    t_list          *current;
    size_t          i;
    size_t          y;
    size_t          y_max;
    char            *y_str;

    output_len = 0;
    current = lst;
    while (current)
    {
        output_len += ft_strlen((char*)current->content);
        current = current->next;
    }
    output = malloc(output_len);
    if (!output)
    {
        return (NULL);
    }
    current = lst;
    i = 0;
    while (current)
    {
        y = 0;
        y_str = (char*)current->content;
        y_max = ft_strlen((const char*)y_str);
        while (y < y_max)
        {
            output[i++] = y_str[y];
            y += 1;
        }
        current = current->next;
    }
    output[i] = '\0';
    return (output);
}

int					ft_vasprintf(char const **ob, const char *fmt, va_list ap)
{
	int				oi;
	char			*gen;
    char            *prev;
    t_list          *str;
    t_list          *new;

	if (ob)
	{
		if (!g_convertors)
		{
			ft_boot_convertors();
			if (AT_EXIT)
				atexit(ft_free_gconvertor);
		}
	}
    str = NULL;
    prev = (char*)fmt;
    while (*fmt)
    {
        if (*fmt == '%' && (fmt += 1))
        {
            gen = ft_substr(prev, 0, (fmt - 1) - prev);
            if (!gen)
            {
                ft_lstclear(&str, &ft_free_str);
                if (!AT_EXIT)
                {
                    ft_free_gconvertor();
                }
                return (-42);
            }
            
            new = ft_lstnew(gen);
            if (!new)
            {
                free(gen);
                ft_lstclear(&str, &ft_free_str);
                if (!AT_EXIT)
                {
                    ft_free_gconvertor();
                }
                return (-42);
            }
            
            ft_lstadd_back(&str, new);
            gen = ft_argtoa(&fmt, ap);
            printf("gen: %s\n", gen);
            prev = (char*)fmt;
            if (!gen)
            {
                ft_lstclear(&str, &ft_free_str);
                if (!AT_EXIT)
                {
                    ft_free_gconvertor();
                }
                return (-42);
            }
            new = ft_lstnew(gen);
            if (!new)
            {
                free(gen);
                ft_lstclear(&str, &ft_free_str);
                if (!AT_EXIT)
                {
                    ft_free_gconvertor();
                }
                return (-42);
            }
            ft_lstadd_back(&str, new);
        }
        fmt += 1;
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

    if (!(*ob = ft_lststrjoin(str)))
    {
        oi = - 42;

    }
    ft_lstclear(&str, &ft_free_str);
    return (ft_strlen(*ob));
}
