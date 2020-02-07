/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_boot_convertors.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 12:30:03 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 11:53:59 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>
/*
static  char    *ft_litoa(t_convertor_state state)
{
    (void) state;
    return (NULL);
}

*/

void			ft_boot_convertors()
{
    ft_register_convertor((t_assoc_convertor){'s', &ft_fmt_s});
    ft_register_convertor((t_assoc_convertor){'i', &ft_fmt_i});
}
