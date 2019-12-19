/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_register_callable.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 13:21:35 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 17:48:37 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

char						*ft_stoa(void *v)
{
	return (ft_strdup(v));
}

t_list						*ft_register_callable(void)
{
	t_list					*output;
	t_list					*addme;

	output = NULL;
	if ((addme = ft_lstnew(malloc(sizeof(t_callable)))))
		*((t_callable*)addme->content) = (t_callable) { (t_flag){0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, NULL};
	((t_callable*)addme->content)->flags.str = 1;
	((t_callable*)addme->content)->callback = ft_stoa;
	if (!addme || !(addme->content))
	{
		ft_lstclear(&output, NULL);
		return (NULL);
	}
	ft_lstadd_back(&output, addme);
	return (output);
}
