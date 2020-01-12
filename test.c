/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 19:01:44 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 00:17:54 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include "stdio.h"

int main()
{
	char	*out;

	out = NULL;
	ft_asprintf(&out, "lol %i %s %c %p end", 43, "hello world", 'q', 2001215);
	printf("generated: [%s]\n", out);
	out = ft_ubase(B16, 4202446464454434, ULONG_LONG_MAX);
	printf("out: %s", out);
}
