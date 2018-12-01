/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 11:54:14 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/27 11:54:15 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_spec(char format)
{
	return (format == 'o' || format == 'O' ||
		format == 'u' || format == 'U' || format == 'x'
		|| format == 'X' || format == 'd' || format == 'i'
		|| format == 'D' || format == 's' || format == 'S'
		|| format == 'c' || format == 'C' || format == 'p'
		|| format == '%');
}

void	ft_flags_overlap(t_flags *flags)
{
	if (flags->f_min || flags->pres)
		flags->f_zero = 0;
	if (flags->f_plus)
		flags->f_space = 0;
}

void	ft_fill_size(char **form, t_flags *flags)
{
	if (**form == 'z' && *(*form)++)
		flags->z++;
	else if (**form == 'j' && *(*form)++)
		flags->j++;
	while (**form == 'l')
	{
		flags->l++;
		(*form)++;
	}
	while (**form == 'h')
	{
		flags->h++;
		(*form)++;
	}
	if (**form != 'd' && **form != 'i' && **form != 'D')
	{
		flags->f_plus = 0;
		flags->f_space = 0;
	}
	if (**form != 'o' && **form != 'O' && **form != 'x' && **form != 'X')
		flags->f_hash = 0;
	else if ((**form == 'X' || **form == 'x') && flags->f_hash)
		flags->f_hash++;
	ft_flags_overlap(&(*flags));
}

void	ft_fill_flags(char **format, t_flags *flags)
{
	set_flags_to_null(flags);
	while (**format == ' ' || **format == '0' ||
		**format == '#' || **format == '+' || **format == '-')
	{
		if (**format == '-')
			flags->f_min = 1;
		else if (**format == '+')
			flags->f_plus = 1;
		else if (**format == '#')
			flags->f_hash = 1;
		else if (**format == ' ')
			flags->f_space = 1;
		else if (**format == '0')
			flags->f_zero = 1;
		(*format)++;
	}
	flags->width = ft_atoi(*format);
	*format += (flags->width ? base_size_sg(flags->width, 10) : 0);
	if (**format == '.' && (flags->f_pres = 1))
	{
		flags->pres = ft_atoi(++*format);
		*format += ft_isdigit(**format) ? base_size_sg(flags->pres, 10) : 0;
	}
	ft_fill_size(format, &(*flags));
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags	flags;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_fill_flags((char**)&format, &flags);
			if (ft_check_spec(*format))
				len += ft_print_spec((char*)format++, flags, ap);
			else if (*format)
				len += print_char(flags, *format++);
		}
		else
		{
			ft_putchar(*format++);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
