/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:01:03 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/22 11:43:00 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(src);
	while (i < len && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (n > len)
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	return (dest);
}
