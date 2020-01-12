/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vasprintf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 15:50:28 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 20:34:40 by mfaussur    ###    #+. /#+    ###.fr     */
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
		// TODO: manage *
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
		// TODO: manage *
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
	t_fmt_id			*content;
	t_list				*current;
	unsigned char		iterno;
	int					noteq;
	char				*generated;

	iterno = 0;
	noteq = 0;
	current = fmtid_lst;
	while (current)
	{
		content = current->content;
		noteq = 0;
		iterno = 0;
		while (iterno < 2 && content->qualifiers[iterno])
		{
			if (content->qualifiers[iterno] != state->fmt[state->i + iterno])
			{
				noteq = 1;
				break;
			}
			iterno += 1;
		}
		if (!noteq && content->identifier == state->fmt[state->i + iterno])
		{
			printf("id: %c callback addr: %p\n", content->identifier, content->callback);
			generated = (*(content->callback))(state);
			if (!generated)
			{
				printf("unsupported flags // qualifiers...\n");
			}
			else
			{
				printf("|<generated: %s %p>|", generated, state->output);
				if (state->output && generated && state->dstsize)
				{
					ft_strlcat(state->output, generated, state->dstsize);
				}
				state->output_len += ft_strlen(generated);
			}
		}
		current = current->next;
	}
}


static void				ft_free_one(void *content)
{
	free(content);
}
static void				ft_free_fmtid_lst()
{
	ft_lstclear(&fmtid_lst, ft_free_one);
	fmtid_lst = NULL;
}

int						ft_vasprintf(char **strp, const char *fmt, va_list ap)
{
	t_fmt_state			*state;
	int					output;
	t_bool				freelst;

	if (!fmtid_lst)
	{
		if (!ft_register_defaults())
		{
			// errors ...
		}
#if USE_AT_EXIT == 1
		atexit(ft_free_fmtid_lst);
#endif
	}
	printf("fmtid_lst: %p\n", fmtid_lst);
	state = ft_calloc(1, sizeof(t_fmt_state));
	if (strp && !*strp)
	{
		printf("counting malloc size..\n");
		state->dstsize = ft_vasprintf(NULL, fmt, ap);
		*strp = malloc(state->dstsize * sizeof(char) + 128);
		printf("malloced\n");
		freelst = TRUE;
	} 
	else
		freelst = FALSE;

	state->output = strp != NULL ? *strp : NULL;
	if (state->output)
	{
		printf("malloc succeed\n");
	}
	state->fmt = fmt;
	state->dstsize = 0;
	va_copy(state->args, ap);
	while (fmt[state->i])
	{
		ft_putchar(fmt[state->i]);
		if (fmt[state->i] == '%')
		{
			state->i += 1;
			ft_parse_flags(state);
			ft_parse_width(state);
			ft_parse_precision(state);
			ft_parse_letters(state);
		}
		else
		{
			if (state->output)
			{
				state->output[state->output_len] = state->fmt[state->i];
			}
			state->output_len += 1;
		}
		state->i += 1;
	}
	state->output_len = state->output_len;
	output = state->output_len;
	free(state);
#if USE_AT_EXIT == 0
	if (freelst)
		ft_free_fmtid_lst();
#endif
	return (output);
}
