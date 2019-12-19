/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_render_styles.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 16:25:24 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 17:21:04 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	(unsigned) (long) (long) int 		-> no precision
**	float / doubles						-> apply precision from the dot
**	string								-> apply precision from the beginning
*/

static char					*ft_apply_precision(char *str, t_arg arg)
{
	char					*output;

	(void)str;
	(void)arg;
	output = NULL;
	if (arg.flags.i)
	{

	}
	else if (arg.flags.f)
	{

	}
	else if (arg.flags.str)
	{

	}
	else
	{
		ft_putstr("[ft_printf] ERROR: unsupported precision for given flag.\n");
	}
	return (output);
}

static char					*ft_apply_padding(char *str, t_arg arg)
{
	char					*output;

	(void)str;
	(void)arg;
	output = NULL;
	return (output);
}

static char					*ft_apply_sign(char *str, t_arg arg)
{
	char					*output;

	(void)str;
	(void)arg;
	output = NULL;
	return (output);
}

static char					*ft_apply_sharp(char *str, t_arg arg)
{
	char					*output;

	(void)str;
	(void)arg;
	output = NULL;
	return (output);
}

char						*ft_render_styles(char *str, t_arg arg)
{
	char					*swap;
	char					*swap2;

	swap = ft_apply_precision(str, arg);
	swap2 = ft_apply_padding(swap, arg);
	free(swap);
	swap = ft_apply_sign(swap2, arg);
	free(swap2);
	swap2 = ft_apply_sharp(swap, arg);
	free(swap);
	return (swap2);
}
