#include "libftprintf.h"

char        *ft_strrev(char *str)
{                                             
    size_t  i;                                
    char    *o;                               

    i = ft_strlen(str);                       
    o = malloc(i + 1);                        
    o[i] = 0;
    while (*str)                          
        o[--i] = *str++;
    return (o);
}



                                              
                                              
                                              
                                              
                                              
                                              
                                              
