/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:24:24 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/25 18:54:48 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *to_find)
{
	int i;
	int j;

	i = 0;
	if (*to_find == '\0')
		return ((char*)src);
	while (src[i] != '\0')
	{
		j = 0;
		while (src[i + j] == to_find[j] &&
			to_find[j] != '\0' && src[i + j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return ((char*)src + i);
		i++;
	}
	return (NULL);
}
