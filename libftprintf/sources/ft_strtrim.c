/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:15:51 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/26 19:30:56 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		st;
	int		nd;
	char	*trimmed;
	int		len;

	st = 0;
	if (!s)
		return (NULL);
	nd = ft_strlen((char*)s) - 1;
	while ((s[st] == ' ' || s[st] == '\t' || s[st] == '\n') && s[st] != '\0')
		st++;
	while ((s[nd] == ' ' || s[nd] == '\t' || s[nd] == '\n') && nd >= 0)
		nd--;
	len = nd - st + 1;
	if (len < 0)
		len = 0;
	trimmed = (char*)malloc(sizeof(char) * len + 1);
	if (!trimmed)
		return (NULL);
	nd = 0;
	while (nd < len)
		trimmed[nd++] = s[st++];
	trimmed[nd] = '\0';
	return (trimmed);
}
