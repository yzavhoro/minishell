/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:58:28 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/28 11:58:36 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (find[i] == '\0')
		return ((char*)src);
	while (src[i] != '\0' && i < len)
	{
		j = 0;
		while (src[i + j] == find[j] &&
			find[j] != '\0' && src[i + j] != '\0' && i + j < len)
			j++;
		if (find[j] == '\0')
			return ((char*)src + i);
		i++;
	}
	return (NULL);
}
