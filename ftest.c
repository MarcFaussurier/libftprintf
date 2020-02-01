/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftest.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 12:21:24 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 16:59:49 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libftprintf.h"

typedef union
{
  float					f;
  struct
  {
    unsigned int		mantisa : 23;
    int					exponent : 8;
    unsigned int		sign : 1;
  }						parts;
}						float_cast;

typedef union
{
  double				f;
  struct
  {
    unsigned long 		mantisa : 52;
    int 				exponent : 11;
    unsigned int 		sign : 1;
  }						parts;
}						double_cast;

long double				ft_pow(long long x, unsigned short pow)
{

	if (!pow)
		return (1);
	if (pow == 1)
		return (x);
	return (x * ft_pow(x, pow - 1));
}


char 			*ldtoa(long double value)
{
    // Get the non-fraction part
    long long 	ival;
	long long	bkp;
	int			len;
	size_t		i;
    long double frac;
   	char		*output;
	char		*lval;
	int			negative;
	size_t		y;

	ival = (long long) value;
	frac = value - ival;
	bkp = 0;
	len = 0;

	// get len
    if (ival < 0)
    {
        negative = 1;
        ival = -ival;
		len += 1;
    }
	bkp = ival;
	while (bkp > 0)
	{
		len += 1;
		bkp /= 10;
	}
	long double frac2 = frac;
    if (frac2 > 0.0)
    {
		len += 1;
        while (TRUE)
        {
            frac2 *= 10;
            bkp  = (long long)(frac2);
            len += 1;
			frac2 -= bkp;
        	if (frac2 > (long double) 0.0)
				break;
		} 
    }
	output = malloc((len + 1) * sizeof(char));
	lval = ft_lltoa(ival);
	output[0] = '\0';
	ft_strlcat(output, lval, len + 1);
	y = ft_strlen(output);
	if (frac > (long double) 0.0)
    {
		output[y++] = '.';
		ft_putchar('.');
        do
        {
            frac *= 10;
            ival  = (int) (frac);
            output[y++] = (char) (ival + '0');
            frac -= ival;
        } while (frac > 0.0);
    }
	output[y] = '\0';
    return output;
}

int main(void) {
  double_cast d2 = {.f = 1.234567891011};
  printf("ldtoatest: %s %.100f\n", ldtoa(246484825.5695), 246484825.5695);
  printf("fval = %.20f\n", d2.f);
  printf("sign = %x\n", d2.parts.sign);
  printf("exponent = %i\n", d2.parts.exponent);
  printf("mantisa = %li\n", d2.parts.mantisa);
  printf("exp notation test: %.50e %hhu %lf \n", (double)0.65, (unsigned char)100, DBL_MAX);
}
