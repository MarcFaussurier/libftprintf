/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaussur <mfaussur@student.le-101.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 10:10:37 by mfaussur          #+#    #+#             */
/*   Updated: 2020/04/10 10:10:40 by mfaussur         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

int				ft_vprintf(const char *fmt, va_list ap)
{
    return (ft_vdprintf(STDOUT_FILENO, fmt, ap));
}
