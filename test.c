/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:34:47 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 12:57:54 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{
	printf("unsuported spec: %lllllllllt\n");
	printf("[ft_printf  output: %+++--+-+-i]\n", ft_printf("[test %+874.8887llzX]\n", 42));
}
