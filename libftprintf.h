/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 12:21:54 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 23:58:59 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# ifndef USE_AT_EXIT
#  define USE_AT_EXIT 0
# endif
# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>
# define b8 "01234567"
# define B8 b8
# define b16 "0123456789abcdef"
# define B16 "0123456789ABCDEF"

t_list					*fmtid_lst;

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
	size_t				dstsize;
	int					output_len;
	char				*output;
	const char			*fmt;
	va_list				args;
	t_flag				flags;
	int					precision;
	int					field_width;
	unsigned int		i;
	char				qualifiers[2];
	char				identifier;
}						t_fmt_state;
typedef char*			(*t_convertor)(t_fmt_state *state);
typedef struct			s_fmt_id
{
	char				qualifiers[2];
	char				identifier;
	t_convertor			callback;
}						t_fmt_id;
char					*ft_base(const char *base, long long i, long long max);
char					*ft_ubase(const char *base, unsigned long long i, unsigned long long max);
t_bool					ft_register_fmt_id(t_fmt_id);
t_bool					ft_register_defaults();
char					*ft_itob(int i);
char					*ft_uitob(unsigned int i);
char					*ft_ltob(long i);
char					*ft_ultob(unsigned long i);
char					*ft_ulltob(unsigned long i);
int						ft_vasprintf(char **strp, const char *fmt, va_list ap);
int						ft_asprintf(char **strp, const char *fmt, ...);
int						ft_vprintf(const char *format, va_list ap);
int						ft_printf(const char *format, ...);
#endif
