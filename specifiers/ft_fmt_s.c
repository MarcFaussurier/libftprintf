/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_s.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 10:58:37 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 14:05:56 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>
// padding 16:				-> 10s(null)
// padding 16 and flag - 	-> (null)10s
// negative padding become positive
// negative precision get ignored
// precision will trim the input

char			*ft_fmt_s(t_specifier_state state, va_list ap)
{
	char		*input;
	char		*output;
	size_t		input_len;
	size_t		field_width;
	size_t		i;
	size_t		y;

	input = va_arg(ap, char *);
	if (!input)
		input = ft_strdup("(null)");
	if (state.precision < 0)
		input_len = ft_strlen(input);
	else if (state.precision > 0 && state.precision != NO_PRECISION)
		input_len = ft_strnlen(input, (size_t) state.precision);
	if (state.padding < 0 && (state.flags.minus = 1))
		field_width = (size_t) -state.padding;
	else
		field_width = state.padding ? state.padding : input_len;
	output = malloc(field_width + 1);
	i = 0;
	if (state.flags.minus)
	{
		while (i < input_len)
		{
			output[i] = input[i];
			i += 1;
		}
		while (i < field_width)
			output[i++] = ' ';
	} 
	else
	{
		while ((i + input_len) < field_width)
			output[i++] = ' ';
		y = 0;
		while (i < field_width)
			output[i++] = input[y++];
	}
	output[field_width] = '\0';
	return (output);
}
