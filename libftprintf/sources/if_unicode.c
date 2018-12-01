/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:13:26 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/10 13:13:30 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mask3(unsigned int val, unsigned char octet)
{
	unsigned int	mask;
	unsigned char	oc1;
	unsigned char	oc2;
	unsigned char	oc3;
	unsigned char	oc4;

	mask = 4034953344;
	oc4 = (val << 26) >> 26;
	oc3 = (val << 18) >> 26;
	oc2 = (val << 14) >> 26;
	oc1 = (val << 11) >> 29;
	octet = (mask >> 24) | oc1;
	write(1, &octet, 1);
	octet = ((mask << 8) >> 24) | oc2;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | oc3;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | oc4;
	write(1, &octet, 1);
}

void	mask2(unsigned int val, unsigned char octet)
{
	unsigned int	mask;
	unsigned char	oc1;
	unsigned char	oc2;
	unsigned char	oc3;

	mask = 14712960;
	oc3 = (val << 26) >> 26;
	oc2 = (val << 20) >> 26;
	oc1 = (val << 16) >> 28;
	octet = (mask >> 16) | oc1;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | oc2;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | oc3;
	write(1, &octet, 1);
}

void	mask1(unsigned int val, unsigned char octet)
{
	unsigned int	mask;
	unsigned char	oc1;
	unsigned char	oc2;

	mask = 49280;
	oc2 = (val << 26) >> 26;
	oc1 = (val << 21) >> 27;
	octet = (mask >> 8) | oc1;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | oc2;
	write(1, &octet, 1);
}

void	ft_if_unicode(unsigned int val)
{
	int				size;
	unsigned char	octet;

	octet = 0;
	size = base_size_unsg(val, 2);
	if (size <= 7)
		ft_putchar(val);
	else if (size <= 11)
		mask1(val, octet);
	else if (size <= 16)
		mask2(val, octet);
	else
		mask3(val, octet);
}
