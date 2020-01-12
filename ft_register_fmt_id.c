/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_register_fmt_id.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 15:29:26 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 15:36:18 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool				ft_register_fmt_id(t_fmt_id fmt_id)
{
	t_list			*new;
	t_fmt_id		*content;

	if(!(content = malloc(1 * sizeof(t_fmt_id))))
		return (FALSE);
	*content = fmt_id;
	if (!(new = ft_lstnew(content)))
	{
		free(content);
		return (FALSE);
	}
	ft_lstadd_back(&fmtid_lst, new);
	return (TRUE);
}
