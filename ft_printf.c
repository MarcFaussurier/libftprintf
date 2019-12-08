/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/08 08:41:56 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 10:36:17 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"


t_flst				*flst_new()
{
	t_flst			*output;

	if (!(output = malloc(sizeof(t_flst))))
		return (NULL);
	*output = (t_flst) {t_ptr, 0, 0, 0, 0, false, false, false, NULL, NULL};
	return (output);
}

void				flst_push(t_flst **root, t_flst *node)
{
	t_flst			*current;

	if (!*root)
		*root = node;
	else
	{
		current = *root;
		while (current)
		{
			if (!current->next)
			{
				current->next = node;
				break ;
			}
			current = current->next;
		}
	}
}

void				flst_del(t_flst **root, t_flst *node)
{
	t_flst			*current;
	t_flst			*tmp;

	if (*root == node)
	{
		tmp = (*root)->next;
		free(*root);
		*root = tmp;
	}
	else
	{
		current = *root;
		while (current && current->next)
		{
			if (current->next == node)
			{
				tmp = current->next->next;
				free(current->next);
				current->next = tmp;
				break ;
			}
		}
	}
}

void				flst_clr(t_flst **root)
{
	while (*root)
		flst_del(root, *root);
}

// 0) % detection
// 1) parse flags
// 2) parse padding
// 3) parse precision
// 4) parse letters
// 5) push generated node

t_flst				*parsef_str(char *str)
{
	t_flst			*output;
	t_flst			*node;
	unsigned int	i;
	unsigned int	start;
	t_bool			prev_was_percent;
	t_bool			waiting_flags;
	t_bool			is_end;

	output = NULL;
	prev_was_percent = false;
	waiting_flags = false;
	i = -1;
	is_end = false;
	while (str[++i])
	{
		if (prev_was_percent)
		{
			while (str[++i] == )
			if (str[i] == '+')
				node->plus = true;
			else if (str[i] == '-')
				node->left_justify = true;
			else if (str[i] == ' ')
				node->plus = false;
			else if (str[i] == '0')
				node->fill_zero = true;
			else if (str[i] == '#')
				node->sharp = true;
			else if ('0' <= str[i] && str[i] <= '9')
			{
				node->padding *= 10;
				node->padding += str[i];
			}
			else if (str[i] == '%' && (is_end = true))
				node->argument_type = t_percent;
			else if (str[i] == 'c' && (is_end = true))
				node->argument_type = t_char;
			else if (str[i] == 's' && (is_end = true))
				node->argument_type = t_string;
			
			if (is_end)
			{
				prev_was_percent = false;
				node->argument_start = start;
				node->argument_end = i;
				flst_push(&output, node);
			}
		}
		else if (str[i] == '%')
		{
			is_end = false;
			start = i;
			prev_was_percent = true;
			if (!(node = flst_new()))
			{
				flst_clr(&output);
				return (NULL);
			}
		}
	}
	return (output);
}

// generate expected arguments list using str and above function
// fill // cast using va args 
// generate new string using toa functions // substrings and indexes
int					ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	t_bool			prev_percent;

	i = -1;
	va_start(args, str);
	va_end(args);
	return (0);
}
