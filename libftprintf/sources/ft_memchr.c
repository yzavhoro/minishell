/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:48:57 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/27 19:12:30 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	c1;

	i = 0;
	s1 = (unsigned char*)s;
	c1 = (unsigned char)c;
	while (i < n)
	{
		if (s1[i] == c1)
			return ((void*)s1 + i);
		i++;
	}
	return (NULL);
}
