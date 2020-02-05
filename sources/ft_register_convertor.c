/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_register_convertor.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 12:24:18 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 12:27:52 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

t_bool			ft_register_convertor(t_assoc_convertor convertor)
{
	t_assoc_convertor	*value;
	t_list				*new;

	value = malloc(sizeof(t_assoc_convertor));
	if (!value)
		return (FALSE);
	*value = (t_assoc_convertor) convertor;
	new = ft_lstnew(value);
	if (!new)
	{
		free(value);
		return (FALSE);
	}
	ft_lstadd_back(&g_convertors, new);
	return (TRUE);
}
