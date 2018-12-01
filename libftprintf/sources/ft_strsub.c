/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:56:06 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/26 13:25:35 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	sub = (char*)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (len--)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
