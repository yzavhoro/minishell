/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:54:32 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/10 15:54:33 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_spec_2(char *frm, t_flags fl, va_list ap)
{
	int len;

	if ((*frm == 'C' || (*frm == 'c' && fl.l)) && MB_CUR_MAX > 1)
		len = print_unicode(fl, va_arg(ap, unsigned int));
	else if (*frm == 'c' || *frm == 'C' || *frm == '%')
		len = print_char(fl, *frm == '%' ? 37 : va_arg(ap, int));
	else if ((*frm == 'S' || (*frm == 's' && fl.l)) && MB_CUR_MAX > 1)
		len = print_unicode_str(fl, va_arg(ap, unsigned int*));
	else if (*frm == 's' || *frm == 'S')
		len = print_string(fl, (char*)va_arg(ap, int*));
	else if (*frm == 'p')
	{
		fl.f_hash = 2;
		fl.f_space = 0;
		fl.f_plus = 0;
		len = print_unsgn(*frm, fl, va_arg(ap, unsigned long));
	}
	else if (!fl.z && !fl.l && !fl.j && *frm != 'O' && *frm != 'U')
		len = print_unsgn(*frm, fl, va_arg(ap, unsigned int));
	else
		len = print_unsgn(*frm, fl, va_arg(ap, uintmax_t));
	return (len);
}

int		ft_print_spec(char *frm, t_flags fl, va_list ap)
{
	int len;

	if (fl.h == 1 && *frm != 'U' && *frm != 'O'
		&& *frm != 'D' && *frm != 'S' && *frm != 'C')
		len = (*frm == 'd' || *frm == 'i') ?
		print_sgn(fl, (short)va_arg(ap, int)) :
		print_unsgn(*frm, fl, (unsigned short)va_arg(ap, unsigned int));
	else if (fl.h == 2 && *frm != 'U' && *frm != 'O'
		&& *frm != 'D' && *frm != 'S' && *frm != 'C')
		len = (*frm == 'd' || *frm == 'i') ?
		print_sgn(fl, (char)va_arg(ap, int)) :
		print_unsgn(*frm, fl, (unsigned char)va_arg(ap, int));
	else if ((*frm == 'd' || *frm == 'i') && !fl.z && !fl.l && !fl.j)
		len = print_sgn(fl, va_arg(ap, int));
	else if (*frm == 'd' || *frm == 'i' || *frm == 'D')
		len = print_sgn(fl, va_arg(ap, intmax_t));
	else
		len = ft_print_spec_2(frm, fl, ap);
	return (len);
}
