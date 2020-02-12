/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/12 09:18:18 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 13:04:00 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

int 			main(void)
{
	int			a,b;

	a = printf("%.2s\n", NULL);
 	b = ft_printf("%.2s\n", NULL);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%-8.10s\n", NULL);
	b = printf("%-8.10s\n", NULL);
	printf("\n[outputs: %i %i]\n", a, b);


	a = ft_printf("%+8.10s\n", NULL);
	b = printf("%+8.10s\n", NULL);
	printf("\n[outputs: %i %i]\n", a, b);
}
