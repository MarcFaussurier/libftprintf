/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:27:16 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 12:23:47 by mfaussur    ###    #+. /#+    ###.fr     */
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


typedef char*(*t_convertor)(t_flags, int, int, char*);

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
void				ft_boot_convertors();
#endif
