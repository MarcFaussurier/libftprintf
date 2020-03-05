/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_convertor.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 10:59:10 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/05 12:35:05 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

t_specifier			ft_get_specifier(char specifier)
{
	t_list			*current;
	t_assoc_specifier	*value;

	current = g_specifiers;
	while (current)
	{
		value = (t_assoc_specifier*) current->content;
		if (value->specifier == specifier || (ft_isupper(specifier) ? (specifier + 32 == value->specifier) : 0))
			return (value->callback);
		current = current->next;
	}
	return (not_found_specifier);
}
