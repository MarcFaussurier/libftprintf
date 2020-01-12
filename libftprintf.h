/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 12:21:54 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 14:33:13 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# ifndef USE_AT_EXIT
#  define USE_AT_EXIT 0
# endif
# include <libft/libft.h>
# include <stdarg.h>

t_list					fmtid_lst;
typedef struct			s_flag
{
	int					zero: 1;
	int					plus: 1;
	int					minus: 1;
	int					space: 1;
	int					sharp: 1;
}						t_flag;
typedef struct			s_fmt_state
{
	char				*output;
	const char			*fmt;
	va_list				*args;
	t_flag				flags;
	unsigned int		i;
	char				qualifier;
	char				identifier;
}						t_fmt_state;
typedef char*			(*t_convertor)(t_fmt_state *state);
typedef struct			s_fmt_id
{
	char				qualifiers[2];
	char				identifier;
	t_convertor			callback;
}						t_fmt_id;
void					ft_register_fmt_id(t_fmt_id);
t_convertor				*ft_match_id(t_fmt_state);
char					*ft_itob(int i);
char					*ft_uitob(unsigned int i);
char					*ft_ltob(long i);
char					*ft_ultob(unsigned long i);
char					*ft_ulltob(unsigned long i);
int						vasprintf(char **strp, const char *fmt, va_list ap);
int						asprintf(char **strp, const char *fmt, ...);
int						vprintf(const char *format, va_list ap);
int						printf(const char *format, ...);
#endif
