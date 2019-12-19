/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 12:53:53 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 17:23:24 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "stdio.h"
#include "libftprintf.h"

int							main()
{
	int						success = 0;
	int						max_success = 3;
	char					*swap;
	float					tmp_f;
	int						tmp_i;
	int						precision;

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
	swap = ft_itoba(&success);
	printf("converting %i -> %s\n\n", success, swap);
	free(swap);
//------------------------------------------------------------------------------
	printf("sizeof(t_flag) / sizeof(int): %lu / %lu\n", sizeof(t_flag), sizeof(int));
//------------------------------------------------------------------------------
	tmp_i = 4242;
	tmp_f = 42.4242;
	precision = -1;
	printf("Precision with int: %.*d (original: %d)\n", precision, tmp_i, tmp_i);
	printf("Precision with flaot: %.*f (original: %f)\n", precision, tmp_f, tmp_f);
	swap = ft_strdup("Hello World");
	printf("Precision with strings: %.*s (original: %s)\n", precision, swap, swap);
	free(swap);
//------------------------------------------------------------------------------
	t_flag *test;

	test = (t_flag*) ft_calloc(1, sizeof(t_flag));
	test->minus = 1;
	test->str = 1;
	test->binary = 1;
	printf("Dumping arg with {str} only... \n");
	ft_dump_flag(*test);
	free(test);
}
