/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:53:35 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/25 18:25:49 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char*)s);
	if (c == 0)
		return ((char*)s + i);
	while (--i >= 0)
		if (s[i] == c)
			return ((char*)s + i);
	return (NULL);
}
