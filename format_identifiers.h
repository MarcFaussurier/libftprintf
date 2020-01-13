/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_identifiers.h                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 09:54:01 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 11:18:59 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FORMAT_IDENTIFIERS_H
# define FORMAT_IDENTIFIERS_H

char					*ft_fmt_int(t_fmt_state *);
char					*ft_fmt_uint(t_fmt_state *);
char					*ft_fmt_double(t_fmt_state *);
char					*ft_fmt_str(t_fmt_state *);
char					*ft_fmt_char(t_fmt_state *);
char					*ft_fmt_ptr(t_fmt_state *);
char					*ft_fmt_hexa(t_fmt_state *);
char					*ft_fmt_hexac(t_fmt_state *);
char					*ft_fmt_octal(t_fmt_state *);

#endif
