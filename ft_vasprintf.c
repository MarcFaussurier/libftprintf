/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vasprintf.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:39:04 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 13:35:17 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

static void			ft_free_gconvertor_content(void *v)
{
	free(v);
}

static void			ft_free_gconvertor()
{
	ft_lstclear(&g_convertors, &ft_free_gconvertor_content);
	g_convertors = NULL;
}

int					ft_vasprintf(char const **ob, const char *fmt, va_list ap)
{
	int				oi;
	char			*bob;
	char			*gen;

	oi = 0;
	if (ob)
	{
		if (!g_convertors)
		{
			ft_boot_convertors();
			if (AT_EXIT)
				atexit(ft_free_gconvertor);
		}
		oi = ft_vasprintf(NULL, fmt, ap);
		bob = malloc(oi);
		*ob = bob;
	}
	while (*fmt)
	{
		if (*fmt == '%' && (fmt += 1))
		{
			gen = ft_argtoa(&fmt, ap);
			if (ob)
				while (*gen)
					*(bob++) = *gen++;
			else
				oi += ft_strlen(gen);
		}
		else if (ob || !(oi += 1))
			*(bob++) = *fmt;
		fmt += 1;
	}
	if (ob || !(oi += 1))
	{
		*bob = '\0';
		if (!AT_EXIT)
			ft_free_gconvertor();
	}
	return (oi);
}
