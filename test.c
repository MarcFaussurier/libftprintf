/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 12:53:53 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 17:47:51 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "stdio.h"
#include "libftprintf.h"

int							main()
{
	int						success = 0;
	int						max_success = 3;
//------------------------------------------------------------------------------
	printf("Testing ft_strichr(char *, char)\n");
	if (ft_strichr("bonjour", 'p') == -1)
		success += 1;

	if (ft_strichr("bonjour", 'b') == 0)
		success += 1;

	if (ft_strichr("bonjour", 'r') == 6)
		success += 1;

	printf("%i/%i tests succeed!\n\n", success, max_success);
//------------------------------------------------------------------------------
	printf("Testing itoba(void *arg) ... \n");
	success = 42;
	printf("converting %i -> %s\n\n", success, ft_itoba(&success));
//------------------------------------------------------------------------------
	printf("sizeof(t_flag) / sizeof(int): %lu / %lu\n", sizeof(t_flag), sizeof(int));
}
