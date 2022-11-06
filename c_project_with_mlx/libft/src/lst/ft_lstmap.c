/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:51:09 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:27:53 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_lst.h"

/**
 * Iterates the list ’lst’ and applies the function
 * ’f’ to the content of each element. Creates a new
 * list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to
 * delete the content of an element if needed.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*alst;
	t_list	*e;

	if (!lst)
		return (NULL);
	alst = ft_lstnew(f(lst->content));
	if (!alst)
		return (NULL);
	e = alst;
	while (lst->next)
	{
		lst = lst->next;
		e->next = ft_lstnew((f)(lst->content));
		if (!e->next)
		{
			ft_lstclear(&alst, del);
			return (NULL);
		}
		e = e->next;
	}
	return (alst);
}
