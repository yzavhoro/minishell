/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:49:57 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/10 15:49:58 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_base(char f)
{
	if (f == 'o' || f == 'O')
		return (8);
	else if (f == 'x' || f == 'X' || f == 'p')
		return (16);
	else if (f == 'b')
		return (2);
	return (10);
}

int		count_width(char frm, t_flags fl, int neg, int nul)
{
	int w;

	w = 0;
	if (!neg && frm != 'u')
		w += fl.f_plus + fl.f_space;
	if (nul)
		w += fl.f_hash;
	return (w);
}

int		check_uni_size(unsigned int c)
{
	int size;

	size = base_size_unsg(c, 2);
	if (size <= 7)
		return (1);
	else if (size <= 11)
		return (2);
	else if (size <= 16)
		return (3);
	return (4);
}

int		ft_uni_len(unsigned int *str, t_flags fl)
{
	int i;
	int bits;

	i = 0;
	bits = 0;
	if (!fl.f_pres)
		while (str[i])
			bits += check_uni_size(str[i++]);
	else
	{
		while (str[i] && bits <= fl.pres)
			bits += check_uni_size(str[i++]);
		if (bits > fl.pres)
			bits -= check_uni_size(str[i - 1]);
	}
	return (bits);
}
