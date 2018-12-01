/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:45:05 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/10 12:45:11 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, int len)
{
	write(1, str, len);
}

int		print_char(t_flags fl, int c)
{
	int len;

	len = (fl.width ? fl.width : 1);
	fl.width -= 1;
	if (!fl.f_min && fl.f_zero)
		while (fl.width-- > 0)
			ft_putchar('0');
	else if (!fl.f_min)
		while (fl.width-- > 0)
			ft_putchar(' ');
	ft_putchar(c);
	if (fl.f_min)
		while (fl.width-- > 0)
			ft_putchar(' ');
	return (len);
}

int		print_unicode(t_flags fl, unsigned int c)
{
	int size;
	int len;
	int bits;

	size = base_size_unsg(c, 2);
	if (size <= 7)
		bits = 1;
	else if (size <= 11)
		bits = 2;
	else if (size <= 16)
		bits = 3;
	else
		bits = 4;
	len = (fl.width - bits > 0 ? fl.width : bits);
	fl.width -= bits;
	if (fl.f_min)
		ft_if_unicode(c);
	while (fl.width-- > 0)
		ft_putchar(' ');
	if (!fl.f_min)
		ft_if_unicode(c);
	return (len);
}

int		print_unicode_str(t_flags fl, unsigned int *str)
{
	int slen;
	int len;
	int temp;

	if (!str)
		return (print_string(fl, NULL));
	temp = ft_uni_len(str, fl);
	if (fl.f_pres)
		fl.pres = fl.pres > temp ? temp : fl.pres;
	slen = fl.f_pres ? fl.pres : temp;
	len = slen > fl.width ? slen : fl.width;
	fl.width -= slen;
	if (fl.f_min)
		ft_put_unicode(str, fl);
	while (fl.width-- > 0)
		ft_putchar(fl.f_zero ? '0' : ' ');
	if (!fl.f_min)
		ft_put_unicode(str, fl);
	return (len);
}

int		print_string(t_flags fl, char *str)
{
	int		slen;
	int		len;
	char	if_null[7];

	set_str_to_null(if_null);
	if (!str)
		str = if_null;
	if (fl.f_pres)
		fl.pres = fl.pres > (int)ft_strlen(str) ? ft_strlen(str) : fl.pres;
	slen = fl.f_pres ? fl.pres : ft_strlen(str);
	len = slen > fl.width ? slen : fl.width;
	fl.width -= slen;
	if (fl.f_min)
		ft_putnstr(str, slen);
	while (fl.width-- > 0)
		ft_putchar(fl.f_zero ? '0' : ' ');
	if (!fl.f_min)
		ft_putnstr(str, slen);
	return (len);
}
