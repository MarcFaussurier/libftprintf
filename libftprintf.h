/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:27:16 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 11:27:56 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <libft/libft.h>
# define NO_PRECISION -424242
# ifndef AT_EXIT
#  define AT_EXIT 0
# endif
# define b2 "01"
# define b3 "012"
# define b4 "0123"
# define b5 "01234"
# define b6 "012345"
# define b7 "0123456"
# define b8 "01234567"
# define b9 "012345678"
# define b10 "0123456789"
# define b16 "0123456789abcdef"
# define B2 b2
# define B3 b3
# define B4 b4
# define B5 b5
# define B6 b6
# define B7 b7
# define B8 b8
# define B9 b9
# define B10 b10
# define B16 "0123456789ABCDEF"

typedef struct		s_flags
{
	char		zero:		1;
	char		plus:		1;
	char		minus:		1;
	char		sharp:		1;
}			t_flags;
typedef struct      	s_specifier_state
{
	t_flags         flags;
	int             padding;
	int             precision;
	char            *qualifiers;
}                   	t_specifier_state;
typedef char*		(*t_specifier)(t_specifier_state, va_list);
typedef struct		s_assoc_specifier
{
	char		specifier;
	t_specifier	callback;
}			t_assoc_specifier;
t_specifier		ft_get_specifier(char);
t_bool			ft_is_specifier(char);
t_bool			ft_register_specifier(t_assoc_specifier);
t_list			*g_specifiers;
void			*not_found_specifier;
t_bool			ft_boot_specifiers();
char			*ft_fmt_s(t_specifier_state, va_list);
char			*ft_fmt_i(t_specifier_state, va_list);
char                	*ft_lststrjoin(t_list *);
char                	*ft_llutoa_base(const char *, unsigned long long);
char                	*ft_lutoa_base(const char *, unsigned long);
char                	*ft_utoa_base(const char *, unsigned int);
char                	*ft_hutoa_base(const char *, unsigned short);
char                	*ft_hhutoa_base(const char *, unsigned char);
char                	*ft_llutoa(unsigned long long int);
char                	*ft_lutoa(unsigned long int);
char                	*ft_utoa(unsigned int);
char                	*ft_hutoa(unsigned short);
char                	*ft_hhutoa(unsigned char);
char                	*ft_llitoa_base(const char *, long long);
char                	*ft_litoa_base(const char *, long);
char                	*ft_itoa_base(const char *, int);
char                	*ft_hitoa_base(const char *, short);
char                	*ft_hhitoa_base(const char *, char);
char                	*ft_llitoa(long long int);
char                	*ft_litoa(long int);
char                	*ft_hitoa(short);
char                	*ft_hhitoa(char);
char		    	*ft_stoa(t_specifier_state, char *, t_bool);
char		    	*ft_argtoa(char const **, va_list);
int	 	    	ft_printf(const char *, ...);
int		    	ft_vprintf(const char *, va_list);
int		    	ft_vasprintf(char const **, const char *, va_list);
int		    	ft_asprintf(char const **, const char *, ...);
#endif
