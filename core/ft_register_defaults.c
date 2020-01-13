/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_register_defaults.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 15:37:30 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 10:10:11 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool				ft_register_defaults()
{
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'},'i', &ft_fmt_int}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'},'d', &ft_fmt_int}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'},'u', &ft_fmt_int}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'l', '\0'},'i', &ft_fmt_int}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'l', '\0'},'d', &ft_fmt_int}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'l', '\0'},'u', &ft_fmt_int}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'l', 'l'},'i', &ft_fmt_int}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'l', 'l'},'d', &ft_fmt_int}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'l', 'l'},'u', &ft_fmt_int}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'}, 's', &ft_fmt_str}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'}, 'c', &ft_fmt_char}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'}, 'p', &ft_fmt_ptr}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'}, 'x', &ft_fmt_hexa}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'}, 'X', &ft_fmt_hexac}))
		return (FALSE);
	return (TRUE);
}
