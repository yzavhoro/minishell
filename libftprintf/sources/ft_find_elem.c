/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:16:17 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/19 20:16:25 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_find_elem(t_list **alst, int content_size)
{
	t_list *temp;

	temp = *alst;
	if (!temp)
		return (*alst = ft_lstnew(content_size));
	while (temp->next)
	{
		if ((int)temp->content_size == content_size)
			return (temp);
		temp = temp->next;
	}
	if ((int)temp->content_size == content_size)
		return (temp);
	temp->next = ft_lstnew(content_size);
	return (temp->next);
}
