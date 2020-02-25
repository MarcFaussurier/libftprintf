#include "libftprintf.h"

char           *ft_stoa(t_specifier_state state, char *input, t_bool enable_zero_padding, t_bool is_null)
{
    t_null      *cnull;
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
	if (!(output = malloc(field_width + 1)))
	    return (NULL);
    i = 0;
	if (state.flags.minus)
	{
		while (i < input_len)
		{
			output[i] = input[i];
			if (!i && is_null)
            {
                cnull = malloc(sizeof(t_null));
                *cnull = (t_null) {.address=output,.index=i};
                if (!ft_lstadd_back_new(state.nulls, cnull))
                {
                    free(output);
                    ft_lstclear(state.nulls, &free);
                    return (NULL);
                }
            }
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
        {
			output[i] = input[y];
            if (!y && is_null)
            {
                cnull = malloc(sizeof(t_null));
                *cnull = (t_null) {.address=output, .index=i};
                if (!ft_lstadd_back_new(state.nulls, cnull))
                {
                    free(output);
                    ft_lstclear(state.nulls, &free);
                    return (NULL);
                }
            }
            i += 1;
            y += 1;
        }
	}
	output[field_width] = '\0';
	return (output);
}
