/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vprintf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:31:04 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 10:07:27 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_vprintf(const char *fmt, va_list ap)
{
    return (ft_vdprintf(STDIN_FILENO, fmt, ap));
}
