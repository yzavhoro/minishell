/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 12:34:19 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/01 19:03:22 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define MIN_LONG -9223372036854775807 -1

typedef struct	s_flags
{
	short		f_plus;
	short		f_min;
	short		f_space;
	short		f_hash;
	short		f_zero;
	short		f_pres;
	int			width;
	int			pres;
	short		l;
	short		h;
	short		j;
	short		z;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_check_spec(char format);
void			set_flags_to_null(t_flags *flags);
void			ft_flags_overlap(t_flags *flags);
void			ft_fill_size(char **form, t_flags *flags);
void			ft_fill_flags(char **format, t_flags *flags);
void			ft_putnstr(char *str, int len);
int				print_char(t_flags fl, int c);
int				print_unicode(t_flags fl, unsigned int c);
int				check_uni_size(unsigned int c);
int				ft_uni_len(unsigned int *str, t_flags fl);
int				print_unicode_str(t_flags fl, unsigned int *str);
void			set_str_to_null(char *str);
int				print_string(t_flags fl, char *str);
int				check_base(char f);
int				count_width(char frm, t_flags fl, int neg, int nul);
void			print_unsgn_3(char frm, t_flags fl, uintmax_t nb, int flag);
void			print_unsgn_2(char frm, t_flags fl, uintmax_t nb, int flag);
int				print_unsgn(char frm, t_flags fl, uintmax_t nb);
void			print_sgn_2(t_flags fl, intmax_t nb, int flag);
int				print_sgn(t_flags fl, intmax_t nb);
int				ft_print_spec_2(char *frm, t_flags fl, va_list ap);
int				ft_print_spec(char *frm, t_flags fl, va_list ap);
int				base_size_sg(intmax_t value, int base);
int				base_size_unsg(uintmax_t value, int base);
void			mask3(unsigned int val, unsigned char octet);
void			mask2(unsigned int val, unsigned char octet);
void			mask1(unsigned int val, unsigned char octet);
void			ft_if_unicode(unsigned int val);
void			ft_putnbr_base(intmax_t value, int base, int reg);
void			ft_putnbr_base_unsigned(uintmax_t value, int base, int reg);
void			ft_put_unicode(unsigned int *str, t_flags fl);

#endif
