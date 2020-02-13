/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/12 09:18:18 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 14:01:41 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

int 			main(void)
{
	int			a,b;

 	a = ft_printf("%12.2slol\n", NULL);
	b = printf("%12.2slol\n", NULL);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%-8.10slol\n", NULL);
	b = printf("%-8.10slol\n", NULL);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%8.10s\n", NULL);
	b = printf("%8.10s\n", NULL);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%*.*slol\n", -16, 3, NULL);
	b = printf("%*.*slol\n", -16, 3, NULL);
	printf("\n[outputs: %i %i]\n", a, b);
}