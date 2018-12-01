/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:55:03 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/27 18:45:22 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *node;

	if (lst)
	{
		node = (t_list*)malloc(sizeof(t_list));
		node = (*f)(lst);
		node->next = ft_lstmap(lst->next, f);
	}
	else
		return (NULL);
	return (node);
}
