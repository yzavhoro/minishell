/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:20:15 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/10 13:20:17 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		base_size_sg(intmax_t value, int base)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	if (value < 0)
	{
		i++;
		value *= -1;
	}
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

int		base_size_unsg(uintmax_t value, int base)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(intmax_t value, int base, int reg)
{
	if (value < 0)
	{
		if (value == MIN_LONG)
		{
			ft_putchar('9');
			ft_putnbr_base(223372036854775808, 10, 1);
		}
		else
			ft_putnbr_base(-value, base, reg);
	}
	else if (value < base)
	{
		if (value >= 10 && reg == 1)
			ft_putchar(value + 87);
		else if (value >= 10 && reg == 2)
			ft_putchar(value + 55);
		else
			ft_putchar(value + 48);
	}
	else
	{
		ft_putnbr_base(value / base, base, reg);
		ft_putnbr_base(value % base, base, reg);
	}
}

void	ft_putnbr_base_unsigned(uintmax_t value, int base, int reg)
{
	if (value < (uintmax_t)base)
	{
		if (value >= 10 && reg == 1)
			ft_putchar(value + 87);
		else if (value >= 10 && reg == 2)
			ft_putchar(value + 55);
		else
			ft_putchar(value + 48);
	}
	else
	{
		ft_putnbr_base_unsigned(value / base, base, reg);
		ft_putnbr_base_unsigned(value % base, base, reg);
	}
}

void	ft_put_unicode(unsigned int *str, t_flags fl)
{
	int i;

	i = 0;
	if (!fl.f_pres)
		while (str[i])
			ft_if_unicode(str[i++]);
	else
		while (str[i] && fl.pres >= 0)
		{
			fl.pres -= check_uni_size(str[i]);
			if (fl.pres >= 0)
				ft_if_unicode(str[i++]);
		}
}
