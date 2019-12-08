/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 13:49:03 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 10:25:31 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef enum		e_type
{
	t_percent,
	t_ptr,
	t_char,
	t_string,
	t_sint,
	t_usint,
	t_int,
	t_lint,
	t_luint,
	t_llint,
	t_ullint,
	t_uchar,
	t_float,
	t_double,
	t_ldouble
}					t_type;

typedef enum 		e_bool
{
	false,
	true
}					t_bool;

typedef struct		s_flst
{
	t_type			argument_type;
	unsigned int	argument_start;
	unsigned int	argument_end;
	unsigned int	precision;
	unsigned int	padding;
	t_bool			left_justify;
	t_bool			fill_zero;
	t_bool			plus;
	t_bool			sharp;
	void			*value;
	struct s_flst	*next;
}					t_flst;

t_flst				*flst_new();
void				flst_del(t_flst **root, t_flst *node);
void				flst_clr(t_flst **root);
void				flst_push(t_flst **root, t_flst *node);
t_flst				*parse_str(char *str);
int 				ft_printf(const char *, ...);

#endif
