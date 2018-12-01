/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:48:48 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/20 16:49:19 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add_buff(char *content, char *buff, int size)
{
	int		len;
	char	*upd_cont;

	len = 0;
	if (content)
		len = ft_strlen(content);
	if (!(upd_cont = (char*)malloc(sizeof(char) * (len + size + 1))))
		return (NULL);
	ft_bzero(upd_cont, len + size + 1);
	if (content)
	{
		ft_strncpy(upd_cont, content, len);
		if (*content)
			free(content);
	}
	if (upd_cont)
		ft_strncpy(upd_cont + len, buff, size);
	return (upd_cont);
}

char	*ft_del_line(char *content, int i)
{
	int		len;
	char	*new_cont;

	if (!content[i + 1] || i >= (int)ft_strlen(content))
	{
		free(content);
		return ("\0");
	}
	len = ft_strlen(content) - i - 1;
	if (!(new_cont = ft_strsub(content, i + 1, len)))
		return (NULL);
	free(content);
	return (new_cont);
}

int		ft_fill_line(char *content, char **line)
{
	int i;

	i = 0;
	while (content && content[i])
	{
		if (content[i] == '\n')
		{
			if (!(*line = (char*)malloc(sizeof(char) * i + 1)))
				return (-1);
			ft_bzero(*line, i + 1);
			ft_strncpy(*line, content, i);
			return (i);
		}
		i++;
	}
	return (-1);
}

int		gnl_2(t_list *curr, char **line, char *buff, int fd)
{
	int r;
	int i;

	while ((r = read(fd, buff, BUFF_SIZE)))
	{
		if (r < 0 || !(curr->content = ft_add_buff(curr->content, buff, r)))
			return (-1);
		if ((i = ft_fill_line(curr->content, line)) >= 0
			&& (curr->content = ft_del_line(curr->content, i)))
			return (1);
	}
	if (curr->content && *((char*)curr->content))
	{
		if (!(*line = (char*)malloc(sizeof(char)
			* (ft_strlen(curr->content) + 1))))
			return (-1);
		ft_bzero(*line, ft_strlen(curr->content) + 1);
		ft_strncpy(*line, curr->content, ft_strlen(curr->content));
		curr->content = ft_del_line(curr->content, ft_strlen(curr->content));
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*curr;
	int				i;
	char			buff[BUFF_SIZE];

	curr = ft_find_elem(&files, fd);
	if ((i = ft_fill_line(curr->content, line)) >= 0
		&& (curr->content = ft_del_line(curr->content, i)))
		return (1);
	return (gnl_2(curr, line, buff, fd));
}
