/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_to_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:05:14 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/10 16:05:16 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags_to_null(t_flags *flags)
{
	flags->f_min = 0;
	flags->f_plus = 0;
	flags->f_hash = 0;
	flags->f_space = 0;
	flags->f_zero = 0;
	flags->f_pres = 0;
	flags->pres = 0;
	flags->l = 0;
	flags->h = 0;
	flags->j = 0;
	flags->z = 0;
}

void	set_str_to_null(char *str)
{
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
}
