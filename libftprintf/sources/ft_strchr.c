/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:25:22 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/25 18:03:26 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	if (ch == 0)
		return ((char*)str + ft_strlen((char*)str));
	while (*str)
	{
		if (*str == ch)
			return ((char*)str);
		str++;
	}
	return (NULL);
}
