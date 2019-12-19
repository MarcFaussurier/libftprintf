/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vasprintf.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 18:07:47 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 18:37:20 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static void					ft_free_arg(void *content)
{
	free(content);
}

#if !PERSISTENT_ASSOC
static void					ft_free_resolvables(t_list **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
#else
static void					ft_free_resolvables_persistent(void)
{
	free(what_to_free);
}
#endif
int							ft_vasprintf(char **str, const char *format, va_list list)
{
	static t_list			*resolables;
	t_list					*args;
	t_list					*current;
	char					*swp;
	char					*swp2;
	int						bytes_written;

	if (!resolables)
	{
		resolables = ft_register_callable();
#if PERSISTENT_ASSOC
		what_to_free = (&resolables);
		atexit(ft_free_resolvables_persistent);
		resolables = NULL;
#endif
	}
	bytes_written = 0;
	args = ft_format(format, list);

	current = args;
	while (current)
	{
		swp = ft_render_arg(*resolables, *((t_arg*)current->content));
		if (!swp)
		{
			// malloc // argument issue...
		}
		swp2 = ft_strjoin(*str, swp);
		free(*str);
		if (!swp2)
		{
			// malloc issue ...
		}
		*str = swp2;
		current = current->next;
	}

	ft_lstclear(&args, ft_free_arg);
#if !PERSISTENT_ASSOC
		ft_free_resolvables(&resolables);
#endif
	return (bytes_written);
}
