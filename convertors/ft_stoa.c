#include "libftprintf.h"

char            *ft_stoa(t_specifier_state state, t_fmt_type type, char *input)
{
    char        *o;
    char        sign;
    int         i;
    int         y;
    int         len;
    t_null      *n;

	i = 0;
    y = 0;
    if (state.precision < 0 && state.precision != NO_PRECISION)
        state.precision = 0;
    if (state.padding < 0)
    {
        state.padding = -state.padding;
      //  if (!state.flags.zero)
        state.flags.minus = 1;
    }
    if (type == NUMBER || type == PREFIXED_NUMBER || type == FLOAT_NUMBER)
    {
        if (!input)
			return (NULL);
		if (state.flags.minus || (state.precision != NO_PRECISION && state.padding))
            state.flags.zero = 0;
        len = ft_strlen(input);
        sign = 0;
        if (input[0] == '-')
        {
            sign = '-';
            y += 1;
            state.padding -= 1;
            len -= 1;
        }
        else if (state.flags.plus)
        {
            sign = '+';
            state.padding -= 1;
        }
        else if (state.flags.space)
        {
            sign = ' ';
            state.padding -= 1;
        }
        if (type == PREFIXED_NUMBER)
        {
            if (input[y + 1] == 'x' || input[y + 1] == 'X')
            {
                state.padding -= 2;
                len -= 2;
            }
            else if (input[y] == '0')
            {
                state.padding -= 1;
                len -= 1;
            }
        }
        if (state.precision == NO_PRECISION)
            state.precision = len;
        o = malloc(state.padding + state.precision  + ft_strlen(input) + 10);

        if ( len > state.precision)
            state.precision = len;
        state.padding -= state.precision;
		if (!(state.flags.minus || state.flags.zero))
            while (state.padding-- > 0)
                o[i++] = ' ';
		if (sign)
            o[i++] = sign;
        if (type == PREFIXED_NUMBER)
        {
            o[i++] = input[y++];
            if (input[y] == 'x' || input[y] == 'X')
                o[i++] = input[y++];
        }
        if (!state.flags.minus)
            while (state.padding-- > 0)
                o[i++] = state.flags.zero ? '0' : ' ';
        while (len <  state.precision--)
            o[i++] = '0';
        while (len-- > 0)
            o[i++] = input[y++];
        while(state.padding-- > 0)
            o[i++] = ' ';
    }
    else if (type == STRING)
    {
        if (!input)
			input = "(null)";
		if (state.precision == NO_PRECISION)
            state.precision = ft_strlen(input);
        len = ft_strnlen(input, state.precision);
        o = malloc(state.padding + len + 1);
        if (!state.flags.minus || state.flags.zero)
			while (len < state.padding--)
				o[i++] = state.flags.zero ? '0' : ' ';
        y = 0;
        while (y++ < len)
				o[i++] = *input++;
		while ( len < state.padding--)
				o[i++] = ' ';
    }
    else if (type == CHAR)
    {
        if (!input)
			return (NULL);
		len = 1;
        o = malloc((state.padding > 1 ? state.padding : 1) + 1);
        if (!state.flags.minus)
            while (--state.padding > 0)
                o[i++] = ' ';
        o[i] = (unsigned char) !input[0] ? -42 : input[0];
        if (!input[0])
        {
            n = malloc(sizeof(t_null));
            *n = (t_null) {.address=o,.index=i};
            if (!ft_lstadd_back_new(state.nulls, n))
            {
                // malloc issue ...
            }
        }
        i += 1;
        while (--state.padding > 0)
            o[i++] = ' ';
    }
    else
        o = ft_strdup("");
    o[i] = 0;
    return (o);
}
