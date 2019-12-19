/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolve.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 13:49:32 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 14:05:39 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

convertor						ft_resolve(t_list callables, t_arg arg)
{
	t_list						*current;
	t_callable					*callable;

	current = &callables;
	while (current)
	{
		callable = (t_callable*) current->content;
		if (ft_match_flag(callable->flags, arg.flags))
		{
			return (callable->callback);
		}
		current = current->next;
	}
	return (NULL);
}
