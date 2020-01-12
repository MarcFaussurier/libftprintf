/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_match_fmt_id.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 15:42:54 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 16:36:55 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

t_convertor				ft_match_fmt_id(t_fmt_state state)
{
	t_list				*current;
	t_fmt_id			*current_fmt_id;

	current = fmtid_lst;
	while (current)
	{
		current_fmt_id = (t_fmt_id*)current->content;
		if (current_fmt_id->qualifiers[0] == state.qualifiers[0] && current_fmt_id->qualifiers[1] == current_fmt_id->qualifiers[1] && current_fmt_id->identifier == state.identifier)
			return (current_fmt_id->callback);
		current = current->next;
	}
	return (NULL);
}
