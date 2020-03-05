#include "libftprintf.h"

char           *ft_stoa(t_stoa_args args)
{
    t_null      *cnull;
	t_bool		is_n;
	char		*output;
	char		*swp;
	char		*swp2;
	size_t		input_len;
	size_t		field_width;
	size_t		i;
	size_t		y;
	size_t		oj_precision;
	size_t		oj_width;

	if (!args.input)
		args.input = (char[7]) {'(', 'n', 'u', 'l', 'l', ')', '\0'};
	if (args.input[0] == '-' && args.is_num)
	{
		swp = ft_substr(args.input, 1, ft_strlen(args.input) - 1);
		//	free(input);
		args.input = swp;
		is_n = TRUE;
	} 
	else
		is_n = FALSE;
	oj_width = args.state.padding > 0 ? args.state.padding : -args.state.padding;
	if (is_n && args.state.padding)
		args.state.padding -= 1;
	if (args.state.padding < 0 && (args.state.flags.minus = 1))
		args.state.padding = -args.state.padding;
	if (args.state.precision == NO_PRECISION)
		oj_precision = ft_strlen(args.input) > (size_t) args.state.padding ? ft_strlen(args.input) : args.state.padding;
	else
		oj_precision = args.state.precision > 0 ? args.state.precision : -args.state.precision;
	printf("precision: %zu, padding: %zu\n", oj_precision, oj_width);
	if ((args.is_num && oj_precision > oj_width))
		args.state.flags.zero = 1;
	if (args.is_num)
	{
		if (args.state.precision != NO_PRECISION && args.state.precision > args.state.padding)
			args.state.padding = args.state.precision;
		if (args.state.padding < (int)ft_strlen(args.input))
        	args.state.padding = ft_strlen(args.input);
        if (args.state.precision < args.state.padding)
			args.state.precision = ft_strlen(args.input);
	} 
	else if (args.is_one_char)
	{
		if (!args.state.precision || !args.state.padding)
		{	
			args.state.precision = 1;
		}
	}
    if (args.state.precision < 0 || args.state.precision == NO_PRECISION)
		input_len = ft_strlen(args.input);
    else 
		input_len = ft_strnlen(args.input, (size_t) args.state.precision);
	if (args.state.padding < 0 && (args.state.flags.minus = 1))
		field_width = (size_t) -args.state.padding;
	else
		field_width = args.state.padding ? args.state.padding : input_len;
	if (!(output = malloc(field_width + 1)))
	    return (NULL);
    i = 0;
	if (args.state.flags.minus)
	{
		while (i < input_len)
		{
			output[i] = args.input[i];
			if (args.is_null)
            {
                cnull = malloc(sizeof(t_null));
                *cnull = (t_null) {.address=output,.index=i};
                if (!ft_lstadd_back_new(args.state.nulls, cnull))
                {
                    free(output);
                    ft_lstclear(args.state.nulls, &free);
                    return (NULL);
                }
            }
            i += 1;
		}
		while (i < field_width)
			output[i++] = (!args.is_num && args.state.flags.zero ) ? '0' : ' ';
	} 
	else
	{
		while ((i + input_len) < field_width)
			output[i++] = ((!args.is_num && args.state.flags.zero) || (args.is_num && args.state.flags.zero && i >= (oj_width - oj_precision))) ? '0' : ' ';
		y = 0;
		while (i < field_width)
        {
			output[i] = args.input[y];
            if (args.is_null)
            {
                cnull = malloc(sizeof(t_null));
                *cnull = (t_null) {.address=output, .index=i};
                if (!ft_lstadd_back_new(args.state.nulls, cnull))
                {
                    free(output);
                    ft_lstclear(args.state.nulls, &free);
                    return (NULL);
                }
            }
            i += 1;
            y += 1;
        }
	}
	output[field_width] = '\0';
	if (is_n)
	{
		y = 0;
		while (output[y])
		{
			if ((args.state.flags.zero && output[y] != '0') || output[y] != ' ')
				break;
			y += 1;
		}
		swp = ft_substr(output, 0, y);
		swp2 = ft_substr(output, y, field_width - y);
	//	free(output);
		output = ft_strnew(3, swp, "-", swp2, NULL);
		free(swp);
		free(swp2);
	}
	return (output);
}
