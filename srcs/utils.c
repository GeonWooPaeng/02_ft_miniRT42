/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:49:35 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/01 14:56:31 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_lstnew(void *content)
{
	t_list *element;

	if(!(element = (t_list *)malloc(sizeof(t_list))))
		return (0);
	element->content = content;
	element->next = 0;
	return (element);
	
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *cur;

	cur = *lst;
	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *cur;
	t_list *tmp;

	cur = *lst;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}