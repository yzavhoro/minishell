/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:51:04 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/27 19:00:22 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int res;
	int i;

	res = 0;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			res++;
		i++;
	}
	if (s[0] != c && s[0])
		res++;
	return (res);
}

static char	**ft_help(char const *s, int len, char **arr, char c)
{
	int count;

	while (len && *s)
	{
		count = 0;
		if (*s != c)
		{
			while (*s && *s != c)
			{
				count++;
				s++;
			}
			if (!(*arr = ft_strnew(count)))
				return (0);
			ft_strncpy(*arr++, (s - count), count);
			len--;
		}
		else
			s++;
	}
	*arr = NULL;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	**begin;
	int		len;

	if (!s)
		return (NULL);
	len = ft_count_words(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (len + 1))))
		return (0);
	begin = arr;
	arr = ft_help(s, len, arr, c);
	return (begin);
}
