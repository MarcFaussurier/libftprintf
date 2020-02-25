#include "libftprintf.h"

char           *ft_stoa(t_specifier_state state, char *input, t_bool enable_zero_padding)
{

	char		*output;
	size_t		input_len;
	size_t		field_width;
	size_t		i;
	size_t		y;


	if (!input)
		input = ft_strdup("(null)");
	if (enable_zero_padding)
	{

		if (state.padding < 0 && (state.flags.minus = 1))
			state.padding = -state.padding;
		if (state.precision < state.padding)
			state.precision = ft_strlen(input);
	}
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
			output[i++] = (enable_zero_padding && state.flags.zero ) ? '0' : ' ';
	} 
	else
	{
		while ((i + input_len) < field_width)
			output[i++] = (enable_zero_padding && state.flags.zero) ? '0' : ' ';
		y = 0;
		while (i < field_width)
			output[i++] = input[y++];
	}
	output[field_width] = '\0';
	return (output);
}
