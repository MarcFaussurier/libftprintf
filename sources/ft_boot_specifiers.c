/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_boot_convertors.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 12:30:03 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 10:13:24 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

t_bool			ft_boot_specifiers()
{
    ft_register_specifier((t_assoc_specifier){'s', &ft_fmt_s});
    ft_register_specifier((t_assoc_specifier){'i', &ft_fmt_i});
    ft_register_specifier((t_assoc_specifier){'u', &ft_fmt_u});
	return (TRUE);
}
