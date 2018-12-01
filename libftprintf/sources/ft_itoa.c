/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:41:15 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/25 16:41:35 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		res++;
		if (n == -2147483648)
			return (11);
		n *= -1;
	}
	while (n)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*arr;
	int		len;

	len = ft_intlen(n);
	arr = (char*)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	ft_memset(arr, 48, len);
	arr[len] = '\0';
	if (n < 0)
	{
		arr[0] = '-';
		if (n == -2147483648)
		{
			arr[1] = '2';
			n %= 1000000000;
		}
		n *= -1;
	}
	while (n)
	{
		arr[--len] = (n % 10) + 48;
		n /= 10;
	}
	return (arr);
}
