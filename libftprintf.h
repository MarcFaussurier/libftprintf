/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 12:21:54 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 18:25:45 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
# include "stdarg.h"
# ifndef PERSISTENT_ASSOC
#  define PERSISTENT_ASSOC 0
# endif
# if PERSISTENT_ASSOC
#  include "stdlib.h"
void						*what_to_free;
# endif

/*
** TYPES
*/
typedef						char*(*convertor)(void *);
typedef struct				s_flag
{
	int						minus: 1;
	int						zero: 1;
	int						plus: 1;
	int						sharp: 1;
	int						blank: 1;
	int						i: 1;
	int						octal: 1;
	int						hex: 1;
	int						ui: 1;
	int						c: 1;
	int						str: 1;
	int						f: 1;
	int						ptr: 1;
	int						nwritten: 1;
	int						ll: 1;
	int						binary: 1;
}							t_flag;
typedef struct				s_callable
{
	t_flag					flags;
	convertor				callback;
}							t_callable;
typedef struct				s_arg
{
	t_flag					flags;
	size_t					begin;
	size_t					end;
	unsigned short			min_width;
	unsigned short			precision;
	void					*value;
}							t_arg;
/*
** UTILS
*/
int							ft_strichr(const char *str, char c);
/*
** TO STRING CONVERSIONS
*/
char						*ft_itoba(void *arg);
/*
** SOURCES
*/
/*
** t_list<t_callable> *ft_register_callable(...)
*/
t_list						*ft_register_callable(void);
convertor					ft_resolve(t_callable resolvables, t_arg arg);
/*
** t_list<t_arg> *ft_format(...)
*/
t_list						*ft_format(const char *format, va_list);
char						*ft_render_arg(t_list resolables, t_arg arg);
int							ft_vasprintf(char **, const char *, va_list);
/*
** WRAPPERS
*/
int							ft_asprintf(char **strp, const char *fmt, ...);
int							ft_vsprintf(char *str, const char *format, va_list);
int							ft_vprintf(const char *format, va_list);
int							ft_sprintf(char *str, const char *format, ...);
int							ft_printf(const char *format, ...);
#endif
