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

char                *ft_lststrjoin(t_list *lst);
char                *ft_llutoa_base(const char *, unsigned long long n);
char                *ft_llitoa_base(const char *, long long n);
char                *ft_llutoa(unsigned long long int n);
char                *ft_lutoa(unsigned long int n);
char                *ft_utoa(unsigned int n);
char                *ft_hutoa(unsigned short n);
char                *ft_hhutoa(unsigned char n);

char                *ft_llitoa(long long int n);
char                *ft_litoa(long int n);
/*
 **char                *ft_itoa(long long n);
 */
char                *ft_hitoa(short n);
char                *ft_hhitoa(char n);
int					ft_printf(const char *fmt, ...);
int					ft_vprintf(const char *fmt, va_list ap);
int					ft_vasprintf(char const **ob, const char *fmt, va_list ap);
int					ft_asprintf(char const **ob, const char *fmt, ...);

char				*ft_argtoa(char const **fmt, va_list ap);


typedef struct		s_flags
{
    char			zero:		1;
    char			plus:		1;
    char			minus:		1;
    char			sharp:		1;
}					t_flags;


typedef struct      s_convertor_state
{
    t_flags         flags;
    int             padding;
    int             precision;
    char            *qualifiers;
}                   t_convertor_state;

typedef char*(*t_convertor)(t_convertor_state, va_list);

t_convertor			ft_get_convertor(char);

typedef struct		s_assoc_convertor
{
    char			specifier;
    t_convertor		convertor;
}					t_assoc_convertor;

t_bool				ft_is_specifier(char);
t_bool				ft_register_convertor(t_assoc_convertor);
/*
 ** t_list of <t_assoc_convertor>
 */
t_list				*g_convertors;
void				*not_found_convertor;
t_bool				ft_boot_convertors();

char				*ft_fmt_s(t_convertor_state state, va_list ap);
char				*ft_fmt_i(t_convertor_state state, va_list ap);

#endif
