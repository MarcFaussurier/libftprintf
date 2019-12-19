/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_render_arg.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 16:19:39 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 16:24:54 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char						*ft_render_arg(t_list resolables, t_arg arg)
{
	convertor				callback;
	char					*swap;
	char					*output;


	callback = ft_resolve(resolables, arg);
	swap = callback(arg.value);
	output = ft_render_styles(swap, arg);
	free(swap);
	return (output);
}
