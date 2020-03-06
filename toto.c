/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   toto.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/03/06 21:07:47 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/06 22:06:59 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
typedef struct toto
{
	char a: 1;
	char b: 1;
	char c: 1;
	char d: 1;
	char e: 1;
	char f: 1;
	char g: 2;

}					tata;


static char					*ft_reccursive_itoba(char i, unsigned char index)
{
	char					*out;

	if (index >= sizeof(char) * 8)
	{
		printf("\n");
		out = malloc((index + 1) * sizeof(char));
		out[index] = '\0';
		return (out);
	}
	out = ft_reccursive_itoba(i >> 1, index + 1);
	out[sizeof(char) * 8 - index - 1] = (i & 1 ? 1 : 0) + '0';
	return (out);
}

char						*ft_hhitoba(void *arg)
{
	return (ft_reccursive_itoba(*((char*) arg), 0));
}

int main()
{
		printf("sizeof tata: %zu byte(s) sizeof bool %zu but(s)\n", sizeof(tata), sizeof(t_bool));
		tata		truc = (tata) {0, 0, 0, 0, 0, 0, 0};
		truc.a = 1;
		printf("a: %hhu b %hhu\n", truc.a, truc.b);
		truc.a = 0;
		printf("a: %hhu b %hhu\n", truc.a, truc.b);
		truc.b = 1;
		printf("a: %hhu b %hhu\n", truc.a, truc.b);
		truc.b = 0;
		truc.a = 1;
		truc.b = 0;
		truc.g = -1;
		printf("%s\n", ft_hhitoba(&truc));
}
