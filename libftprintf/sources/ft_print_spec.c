/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:37:44 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/27 15:37:45 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsgn_3(char frm, t_flags fl, uintmax_t nb, int flag)
{
	while (fl.pres-- > 0)
		ft_putchar('0');
	if (!flag)
		ft_putnbr_base_unsigned(nb, check_base(frm), frm == 'X' ? 2 : 1);
	if (fl.f_min)
		while (fl.width-- > 0)
			ft_putchar(' ');
}

void	print_unsgn_2(char frm, t_flags fl, uintmax_t nb, int flag)
{
	if (fl.f_plus && fl.f_zero && frm != 'u')
		ft_putchar('+');
	if (fl.f_hash && fl.f_zero &&
		(nb || frm == 'p' || frm == 'o' || frm == 'O'))
	{
		if (frm == 'x' || frm == 'X' || frm == 'p')
			ft_putnstr(frm == 'X' ? "0X" : "0x", 2);
		else
			ft_putchar('0');
	}
	if (!fl.f_min)
		while (fl.width-- > 0)
			ft_putchar(fl.f_zero ? '0' : ' ');
	if (fl.f_plus && !fl.f_zero && frm != 'u')
		ft_putchar('+');
	if (fl.f_hash && !fl.f_zero &&
		(nb || frm == 'p' || frm == 'o' || frm == 'O'))
	{
		if (frm == 'x' || frm == 'X' || frm == 'p')
			ft_putnstr(frm == 'X' ? "0X" : "0x", 2);
		else
			ft_putchar('0');
	}
	print_unsgn_3(frm, fl, nb, flag);
}

int		print_unsgn(char frm, t_flags fl, uintmax_t nb)
{
	int len;
	int bs;
	int base;
	int add;
	int flag;

	flag = (fl.f_pres && fl.pres <= 0 && !nb) ? 1 : 0;
	if (!fl.f_pres && !nb && frm != 'p')
		fl.f_hash = 0;
	base = check_base(frm);
	bs = flag ? 0 : base_size_unsg(nb, base);
	if (fl.f_hash == 1 && nb)
		fl.pres--;
	add = count_width(frm, fl, 0, (nb != 0 || frm == 'p'
		|| frm == 'o' || frm == 'O'));
	if (fl.width - add > bs)
		len = fl.width;
	else
		len = bs > fl.pres ? bs + add : fl.pres + add;
	len = fl.pres > len ? fl.pres : len;
	fl.width = fl.width - (fl.pres > bs ? fl.pres : bs) - add;
	fl.pres -= bs;
	print_unsgn_2(frm, fl, nb, flag);
	return (len);
}

void	print_sgn_2(t_flags fl, intmax_t nb, int flag)
{
	if (nb < 0 && fl.f_zero)
		ft_putchar('-');
	if (fl.f_plus && nb >= 0 && fl.f_zero)
		ft_putchar('+');
	if (!fl.f_min)
		while (fl.width-- > 0)
			ft_putchar(fl.f_zero ? '0' : ' ');
	if (fl.f_plus && nb >= 0 && !fl.f_zero)
		ft_putchar('+');
	if (nb < 0 && !fl.f_zero)
		ft_putchar('-');
	while (fl.pres-- > 0)
		ft_putchar('0');
	if (!flag && !(fl.f_hash && !nb))
		ft_putnbr_base(nb, 10, 1);
	if (fl.f_min)
		while (fl.width-- > 0)
			ft_putchar(' ');
}

int		print_sgn(t_flags fl, intmax_t nb)
{
	int len;
	int bs;
	int add;
	int flag;

	flag = (fl.f_pres && fl.pres <= 0 && !nb) ? 1 : 0;
	bs = flag ? 0 : base_size_sg(nb, 10);
	add = count_width(0, fl, nb < 0, nb != 0);
	if (fl.width - add > bs)
		len = fl.width;
	else
		len = bs > fl.pres ? bs + add : fl.pres + add;
	len = fl.pres + (nb < 0) > len ? fl.pres + (nb < 0) : len;
	if (fl.f_space && nb >= 0)
		ft_putchar(' ');
	fl.width = fl.width - (fl.pres >= bs ? (fl.pres + (nb < 0)) : bs) - add;
	if (fl.pres)
		fl.pres = fl.pres - bs + (nb < 0 ? 1 : 0);
	print_sgn_2(fl, nb, flag);
	return (len);
}
