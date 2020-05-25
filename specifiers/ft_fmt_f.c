#include "libftprintf.h"


void            ft_round_fr(char *num)
{
    if (!*num)
        return ;
    else if (*num == '.')
        ft_round_fr(num + 1);
    else if (*num == '+' || *num == '-')
        return ;
    else if (*num == '9' && (*num = '0'))
        ft_round_fr(num + 1);
    else
        *num += 1;
    return ;
}

void            ft_round_f(char *num)
{
    char        *r;
    char        *swp;

    r = ft_strrev(num);
    if (r[0] >= '5')
        ft_round_fr(r);
    swp = r;
    r = ft_strrev(r);
    free(swp);
    ft_memcpy(num, r, ft_strlen(num));
    free(r);
    return ;
}

char            *ft_fmt_f(t_specifier_state state, va_list ap)
{
    char    *num;
    char    *out;

    if (!ft_strlen(state.qualifiers))
        num = ft_ftoa((float) va_arg(ap, double));
    else if (!ft_strncmp(state.qualifiers, "l", 1))
        num = ft_dtoa(va_arg(ap, double));    
    else if (!ft_strncmp(state.qualifiers, "L", 1))
        num = ft_ldtoa(va_arg(ap, long double));
    else                                      
        num = NULL;                           
    if (!num)                                 
        return (NULL);                        
    if (state.precision == NO_PRECISION || !state.precision)
        state.precision = 6;                  
    state.precision += ft_strchr(num, '.') - num + 1;
    out = ft_stoa(state, STRING, num);        
    free(num);                                
    ft_round_f(out);                          
    return (out);
}







                                              
                                              
                                              
                                              
                                              
                                              
                                              
