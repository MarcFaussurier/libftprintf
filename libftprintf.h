/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:27:16 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 12:22:33 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define IS_LITTLE_ENDIAN (1 == *(unsigned char *)&(int){1})
# include <stdarg.h>
# include <libft/libft.h>
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
# define LDEXPBIAS 16383
# define LDEXPNAN 32767
# define NO_PRECISION -424242
# define PRINTF_ERROR -42
# ifndef AT_EXIT
#  define AT_EXIT 0
# endif
typedef union               u_float
{

    float                   v;
    struct {
        unsigned int        sign:       1;
        unsigned int        exponent:   8;
        unsigned int        mantissa:   23;
    }                       s;
    char                    bytes[32];
}                           t_float;
typedef union               u_double {
    double                  v;
    struct {
        unsigned long long  sign:       1;
        unsigned long long  exponent:   11;
        unsigned long long  mantissa:   52;
    }                       s;
    char                    bytes[64];
}                           t_double;
typedef union               u_longdouble {
    long double             v;
    struct {
        unsigned int        sign:       1;
        unsigned int        exponent:   15;
        unsigned int        i:          1;
        unsigned long long  mantissa:   63;
    }                       s;
    char                    bytes[80];
}                           t_longdouble;
typedef struct		        s_flags
{
    char		            zero:       1;
    char		            plus:		1;
    char		            minus:		1;
    char		            sharp:		1;
}			                t_flags;
typedef struct      	    s_specifier_state
{
    t_flags                 flags;
    char                    *qualifiers;
    char			        specifier;
    int                     padding;
    int                     precision;
    int				        no;
}                   	    t_specifier_state;
typedef char*		        (*t_specifier)(t_specifier_state, va_list);
typedef struct		        s_assoc_specifier
{
    char		            specifier;
    t_specifier	            callback;
}			                t_assoc_specifier;
t_bool			            ft_free(void *, t_bool);
t_specifier		            ft_get_specifier(char);
t_bool			            ft_is_specifier(char);
t_bool			            ft_register_specifier(t_assoc_specifier);
t_list			            *g_specifiers;
void			            *not_found_specifier;
t_bool			            ft_boot_specifiers();
char			            *ft_fmt_s(t_specifier_state, va_list);
t_bool                      ft_lststradd(t_list **, char *);
char                        *ft_lststrjoin(t_list *);
long double                 ft_modld(long double, long double*);
char			            *ft_fmt_i(t_specifier_state, va_list);
char			            *ft_fmt_u(t_specifier_state, va_list);
char			            *ft_fmt_o(t_specifier_state, va_list);
char			            *ft_fmt_x(t_specifier_state, va_list);
char            			*ft_fmt_c(t_specifier_state, va_list);
char            			*ft_fmt_a(t_specifier_state, va_list);
char            			*ft_fmt_p(t_specifier_state, va_list);
char            			*ft_fmt_n(t_specifier_state, va_list);
char        		      	*ft_fmt_f(t_specifier_state, va_list);
char            			*ft_fmt_g(t_specifier_state, va_list);
char                        *ft_ftoa(float);
char                        *ft_dtoa(double);
char                        *ft_ldtoa(long double);
char                        *ft_ftohex(long double);
char                        *ft_dtohex(long double);
char                        *ft_ldtohex(long double);
char                        *ft_ftoexp(long double);
char                        *ft_dtoexp(long double);
char                        *ft_ldtoexp(long double);
char                        *ft_llutoa_base(const char *, unsigned long long);
char                        *ft_lutoa_base(const char *, unsigned long);
char                        *ft_utoa_base(const char *, unsigned int);
char                        *ft_hutoa_base(const char *, unsigned short);
char                        *ft_hhutoa_base(const char *, unsigned char);
char                        *ft_llutoa(unsigned long long int);
char                        *ft_lutoa(unsigned long int);
char                        *ft_utoa(unsigned int);
char                        *ft_hutoa(unsigned short);
char                        *ft_hhutoa(unsigned char);
char                        *ft_llitoa_base(const char *, long long);
char                        *ft_litoa_base(const char *, long);
char                        *ft_itoa_base(const char *, int);
char                        *ft_hitoa_base(const char *, short);
char                        *ft_hhitoa_base(const char *, char);
char                        *ft_llitoa(long long int);
char                        *ft_litoa(long int);
char                        *ft_hitoa(short);
char                        *ft_hhitoa(char);
char		                *ft_stoa(t_specifier_state, char *, t_bool);
char		                *ft_argtoa(char const **, va_list, int);
int	 	    	            ft_printf(const char *, ...);
int		    	            ft_vprintf(const char *, va_list);
int		    	            ft_vasprintf(char const **, const char *, va_list);
int		    	            ft_asprintf(char const **, const char *, ...);
#endif
