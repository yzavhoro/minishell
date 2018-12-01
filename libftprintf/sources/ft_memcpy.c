/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:13:30 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/26 13:00:16 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ch_dest;
	unsigned char	*ch_src;
	size_t			i;

	i = 0;
	ch_dest = (unsigned char*)dest;
	ch_src = (unsigned char*)src;
	while (n--)
	{
		ch_dest[i] = ch_src[i];
		i++;
	}
	return (dest);
}
