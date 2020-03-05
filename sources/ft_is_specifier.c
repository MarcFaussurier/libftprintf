/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_specifier.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 11:35:33 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/05 14:00:37 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool					ft_is_specifier(char c)
{
	t_list				*current;
	t_assoc_specifier		*value;

	current = g_specifiers;
	while (current)
	{
		value = (t_assoc_specifier*) current->content;
		if (value->specifier == c || (ft_isupper(c) ? (c + 32 == value->specifier) : 0))
			return (TRUE);
		current = current->next;
	}
	return (FALSE);
}
