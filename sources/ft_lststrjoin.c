#include "libftprintf.h"

char                *ft_lststrjoin(t_list *lst)
{
    size_t          output_len;
    char            *output;
    t_list          *current;
    size_t          i;
    size_t          y;
    size_t          y_max;
    char            *y_str;

    output_len = 0;
    current = lst;
    while (current)
    {
        output_len += ft_strlen((char*)current->content);
        current = current->next;
    }
    output = malloc(output_len + 1);
    if (!output)
    {
        return (NULL);
    }
    current = lst;
    i = 0;
    while (current)
    {
        y = 0;
        y_str = (char*)current->content;
        y_max = ft_strlen((const char*)y_str);
        while (y < y_max)
        {
            output[i++] = y_str[y];
            y += 1;
        }
        current = current->next;
    }
    output[i] = '\0';
    return (output);
}
