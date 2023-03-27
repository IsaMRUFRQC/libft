/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:36:27 by iduval            #+#    #+#             */
/*   Updated: 2022/01/20 16:16:22 by iduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp_lst;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		temp_lst = ft_lstnew((*f)(lst->content));
		if (!temp_lst)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp_lst);
		lst = lst->next;
	}
	return (new_lst);
}
