/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/12 09:18:18 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 10:14:32 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

int 			main(void)
{
	int			a,b;

    printf("ft_llitoa_base: %s\n", ft_llitoa_base(b10, 258888588454));
 	a = ft_printf("%12.2slol\n", NULL);
	b = printf("%12.2slol\n", NULL);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%--8.10slol\n", NULL);
	b = printf("%--8.10slol\n", NULL);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%8.10s\n", NULL);
	b = printf("%8.10s\n", NULL);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%*.*slol\n", -16, 3, NULL);
	b = printf("%*.*slol\n", -16, 3, NULL);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%*.*hilol\n", -16, 2, 4242);
	b = printf("%*.*hilol\n", -16, 2, 4242);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%*.*hhulol\n", -16, 2, INT_MAX);
	b = printf("%*.*hhulol\n", -16, 2, INT_MAX);
	printf("\n[outputs: %i %i]\n", a, b);
}
