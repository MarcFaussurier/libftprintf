/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vasprintf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 15:50:28 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 16:37:10 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static void					ft_parse_flags(t_fmt_state *state)
{
	while (state->fmt[state->i])
	{
		if (state->fmt[state->i] == '+')
			state->flags.plus = 1;
		else if (state->fmt[state->i] == '-')
			state->flags.minus = 1;
		else if (state->fmt[state->i] == '0')
			state->flags.zero = 1;
		else if (state->fmt[state->i] == ' ')
			state->flags.space = 1;
		else if (state->fmt[state->i] == '#')
			state->flags.sharp = 1;
		else
			break;
		state->i += 1;
	}
}

static void					ft_parse_width(t_fmt_state *state)
{
	const char				*begin;
	char					*width_str;
	unsigned int			width_len;

	if (ft_isdigit(state->fmt[state->i]))
	{
		begin = &state->fmt[state->i];
		width_len = 1;
		while (++(state->i) && ft_isdigit(state->fmt[state->i]))
			width_len += 1;
		width_str = ft_substr(begin, 0, width_len);
		state->field_width = ft_atoi(width_str);
	}
}

static void				ft_parse_precision(t_fmt_state *state)
{
	const char				*begin;
	char					*precision_str;
	unsigned int			precision_len;

	if (state->fmt[state->i] == '.')
	{
		state->i += 1;
		begin = &state->fmt[state->i];
		precision_len = 0;
		while (++(state->i) && ft_isdigit(state->fmt[state->i]))
			precision_len += 1;
		precision_str = ft_substr(begin, 0, precision_len);
		state->precision = ft_atoi(precision_str);
	}
}

static void				ft_parse_letters(t_fmt_state *state)
{
	t_list				*current;
	char				letters[3];
	unsigned char		iterno;

	current = fmtidhash_lst;
	while (current)
	{
		iterno = 0;
		while (iterno < 3 && letters[iterno] == state->fmt[state->i + iterno])
		{
		
		}
		current = current->next;
	}
}

int						ft_vasprintf(char **strp, const char *fmt, va_list ap)
{
	t_fmt_state			*state;
	int					output_len;

	state = calloc(1, sizeof(t_fmt_state));
	if (strp && !*strp)
	{
		output_len = vasprintf(NULL, fmt, ap);
		*strp = malloc(output_len * sizeof(char));
	}
	state->output = *strp;
	state->fmt = fmt;
	while (fmt[state->i])
	{
		if (fmt[state->i] == '%')
		{
			state->i += 1;
			ft_parse_flags(state);
			ft_parse_width(state);
			ft_parse_precision(state);
			ft_parse_letters(state);
		}
		state->i += 1;
	}
	output_len = state->output_len;
	free(state);
	return (output_len);
}
