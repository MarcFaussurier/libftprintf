/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:31:04 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/04/10 10:04:22 by mfaussur         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_vprintf(const char *fmt, va_list ap)
{
    return (ft_vdprintf(STDOUT_FILENO, fmt, ap));
}
