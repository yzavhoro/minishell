/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:49:04 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/28 11:50:36 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(size_t content_size)
{
	t_list	*newnode;

	newnode = (t_list*)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content_size = content_size;
	newnode->content = NULL;
	newnode->next = NULL;
	return (newnode);
}
