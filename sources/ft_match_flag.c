/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_match_flag.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 13:44:52 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 13:48:46 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool						ft_match_flag(t_flag a, t_flag b)
{
	return (a.i == b.i
			&& a.octal == b.octal
			&& a.hex = b.hex
			&& a.ui == b.ui
			&& a.c == b.c
			&& a.str == b.str
			&& a.f == b.f
			&& a.ptr == b.ptr
			&& a.nwritten == b.nwritten
			&& a.ll == b.ll
			&& a.binary == b.binary);
}
