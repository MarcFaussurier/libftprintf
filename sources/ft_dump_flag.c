/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dump_flag.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 16:56:58 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 17:23:02 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void						ft_dump_flag(t_flag flag)
{
	char					*str;

	str = ft_itoba(&flag);
	ft_putendl(str);
	free(str);
	return;
}
