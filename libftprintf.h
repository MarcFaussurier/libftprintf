/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:27:16 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/10 18:30:02 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <locale.h>
# include "libft/libft.h"
# define b2 "01"
# define b8 "01234567"
# define b10 "0123456789"
# define b16 "0123456789abcdef"
# define B2 b2
# define B8 b8
# define B10 b10
# define B16 "0123456789ABCDEF"
# ifndef LDMAXPRECISION
#  define LDMAXPRECISION 256
# endif
# define LDEXPBIAS 16383
# define POW2_15 32768
# define NO_PRECISION -424242
# define PRINTF_ERROR -42
# ifndef AT_EXIT
#  define AT_EXIT 0
# endif
typedef enum                        e_ld_states
{
    NORMAL,
    DENORMAL,
    ZERO,
    INFINITY,
    NOT_A_NUMBER,
    QUIET_NOT_A_NUMBER,
    QUIET_NOT_A_NUMBER_INVALID_OP,
    CANT_BE_GEN,
    INVALID_OP
}                                   t_ld_state;
typedef enum                        e_fmt_types
{
    NUMBER,
    PREFIXED_NUMBER,
    FLOAT_NUMBER,
    WSTRING,
    STRING,
    CHAR
}                                   t_fmt_type;
typedef union                       u_wchar
{
    wchar_t                         value;
    char                            bytes[4];
}                                   t_wchar;
typedef union                       u_float
{

    float                           value;
    struct
    {
        unsigned int                mantisa:            23;
        unsigned int                exponent:           8;
        unsigned int                sign:               1;
    }                               s_parts;
    unsigned char                   bytes[4];
}                                   t_float;
typedef union                       u_double
{
    double                          value;
    unsigned char                   bytes[8];
    struct
    {
        union
        {
            unsigned long long      value:              52;
            struct
            {
                unsigned int        low:                32;
                unsigned int        high:               20;
            }                       s_parts;
        }                           u_mantisa;
        unsigned long long          exponent:           11;
        unsigned long long          sign:               1;
    }                               s_parts;
}                                   t_double;
typedef union                       u_long_double
{
    long double                     value;
    unsigned char                   bytes[10];
    struct
    {
        union
        {
            unsigned long long      value:              64;
            struct
            {
                unsigned long long  value:              62;
                unsigned long long  y:                  1;
                unsigned long long  i:                  1;
            }                       s_bb;
            struct
            {
                unsigned long long  value:              63;
                unsigned long long  i:                  1;
            }                       s_b;
            struct
            {
                unsigned long long  low:               32;
                unsigned long long  high:              32;
            }                       s_pair;
        }                           u_mantisa;
        unsigned long long          exponent:           15;
        unsigned long long          sign:               1;
    }                               s_parts;
}                                   t_long_double;
typedef struct		                s_flags
{
    char		                    zero:               1;
    char		                    plus:		        1;
    char		                    minus:		        1;
    char		                    sharp:		        1;
    char                            space:              1;
}			                        t_flags;
typedef struct                      s_null
{
    char                            *address;
    size_t                          index;
}                                   t_null;
typedef struct      	            s_specifier_state
{
    t_flags                         flags;
    char                            *qualifiers;
    char			                specifier;
    int                             padding;
    int                             precision;
    int				                no;
    t_list                          **nulls;
    t_bool                          force_prefix;
}                   	            t_specifier_state;
typedef char*		                (*t_specifier)(t_specifier_state, va_list);
typedef struct		                s_assoc_specifier
{
    char		                    specifier;
    t_specifier	                    callback;
}			                        t_assoc_specifier;
void                                ft_putmem_fd(int, char *, size_t);
void                                ft_putmem(char*, size_t);
void                                ft_lstdel_node(t_list**, t_list*, void(*)(void*));
t_bool                              ft_lstadd_back_new(t_list**, void*);
t_bool                              ft_lstadd_front_new(t_list**, void*);
t_bool                              ft_is_in_a(int, int*, unsigned int);
t_bool			                    ft_free(void *, t_bool);
t_specifier		                    ft_get_specifier(char);
t_bool			                    ft_is_specifier(char);
t_bool			                    ft_register_specifier(t_assoc_specifier);
t_list			                    *g_specifiers;
void			                    *not_found_specifier;
t_bool			                    ft_boot_specifiers();
t_bool                              ft_lststradd(t_list **, char *);
t_list                              *ft_lststrnew(unsigned int, ...);
t_list                              *ft_vlststrnew(unsigned int, va_list);
char                                *ft_wchar_to_utf(wchar_t);
char                                *ft_numtoa(t_specifier_state, va_list, const char *, char *);
char                                *ft_unumtoa(t_specifier_state, va_list, const char *, char *);
char                                *ft_strnew(unsigned int, ...);
char                                *ft_vstrnew(unsigned int, va_list);
char                                *ft_lststrjoin(t_list*);
char                                *ft_wchar_to_UTF8(wchar_t*);
long double                         ft_pow(long double, short);
long double                         ft_upow(long double, unsigned short);
float                               ft_modff(float, float*);
double                              ft_modf(double, double*);
long double                         ft_modfl(long double, long double*);
t_ld_state                          ft_read_state_ld(long double);
t_bool                              ft_isinfl(long double);
t_bool                              ft_isnanl(long double);
char                                *ft_btoa(void * ptr, size_t size);
char			                    *ft_fmt_percent(t_specifier_state, va_list);
char			                    *ft_fmt_s(t_specifier_state, va_list);
char			                    *ft_fmt_i(t_specifier_state, va_list);
char			                    *ft_fmt_u(t_specifier_state, va_list);
char			                    *ft_fmt_o(t_specifier_state, va_list);
char			                    *ft_fmt_x(t_specifier_state, va_list);
char            			        *ft_fmt_c(t_specifier_state, va_list);
char            			        *ft_fmt_a(t_specifier_state, va_list);
char            			        *ft_fmt_p(t_specifier_state, va_list);
char            			        *ft_fmt_n(t_specifier_state, va_list);
char        		      	        *ft_fmt_f(t_specifier_state, va_list);
char            			        *ft_fmt_g(t_specifier_state, va_list);
char                                *ft_fmt_b(t_specifier_state, va_list);
char                                *ft_ftoa(float);
char                                *ft_dtoa(double);
char                                *ft_ldtoa(long double);
char                                *ft_ldtoa_base(const char*, long double);
char                                *ft_ftohex(long double);
char                                *ft_dtohex(long double);
char                                *ft_ldtohex(long double);
char                                *ft_ftoexp(long double);
char                                *ft_dtoexp(long double);
char                                *ft_ldtoexp(long double);
char                                *ft_llutoa_base(const char *, unsigned long long);
char                                *ft_lutoa_base(const char *, unsigned long);
char                                *ft_utoa_base(const char *, unsigned int);
char                                *ft_hutoa_base(const char *, unsigned short);
char                                *ft_hhutoa_base(const char *, unsigned char);
char                                *ft_llutoa(unsigned long long int);
char                                *ft_lutoa(unsigned long int);
char                                *ft_utoa(unsigned int);
char                                *ft_hutoa(unsigned short);
char                                *ft_hhutoa(unsigned char);
char                                *ft_llitoa_base(const char *, long long);
char                                *ft_litoa_base(const char *, long);
char                                *ft_itoa_base(const char *, int);
char                                *ft_hitoa_base(const char *, short);
char                                *ft_hhitoa_base(const char *, char);
char                                *ft_llitoa(long long int);
char                                *ft_litoa(long int);
char                                *ft_hitoa(short);
char                                *ft_hhitoa(char);
char		                        *ft_stoa(t_specifier_state, t_fmt_type, char *);
char		                        *ft_argtoa(char const **, va_list, int, t_list**);
int                                 ft_vdprintf(int, const char *, va_list);
int                                 ft_dprintf(int, const char *, ...);
int	 	    	                    ft_printf(const char *, ...);
int		    	                    ft_vprintf(const char *, va_list);
int		    	                    ft_vasprintf(char **, const char *, va_list);
int		    	                    ft_asprintf(char **, const char *, ...);
#endif
