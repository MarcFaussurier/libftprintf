/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_boot_specifiers.c                               :+:      :+:    :+:   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 12:30:03 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/04/10 15:44:35 by mfaussur         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool			ft_boot_specifiers()
{
    ft_register_specifier((t_assoc_specifier){'%', &ft_fmt_percent});
    ft_register_specifier((t_assoc_specifier){'s', &ft_fmt_s});
    ft_register_specifier((t_assoc_specifier){'i', &ft_fmt_i});
    ft_register_specifier((t_assoc_specifier){'d', &ft_fmt_i});
    ft_register_specifier((t_assoc_specifier){'u', &ft_fmt_u});
    ft_register_specifier((t_assoc_specifier){'c', &ft_fmt_c});
    ft_register_specifier((t_assoc_specifier){'n', &ft_fmt_n});
    ft_register_specifier((t_assoc_specifier){'p', &ft_fmt_p});
    ft_register_specifier((t_assoc_specifier){'x', &ft_fmt_x});
    ft_register_specifier((t_assoc_specifier){'o', &ft_fmt_o});
    ft_register_specifier((t_assoc_specifier){'b', &ft_fmt_b});
    ft_register_specifier((t_assoc_specifier){'f', &ft_fmt_f});
//    ft_register_specifier((t_assoc_specifier){'g', &ft_fmt_g});
    return (TRUE);
}
