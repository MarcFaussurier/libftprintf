/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_convertor.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 10:59:10 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 11:05:10 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

t_convertor				ft_get_convertor(char specifier)
{
	t_list				*current;
	t_assoc_convertor	*value;

	current = g_convertors;
	while (current)
	{
		value = (t_assoc_convertor*) current->content;
		if (value->specifier == specifier)
			return (value->convertor);
		current = current->next;
	}
	return (not_found_convertor);
}
