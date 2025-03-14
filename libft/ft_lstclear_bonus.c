/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:47:05 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 17:57:49 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while ((*lst))
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = temp;
	}
	*lst = NULL;
}

// void	del(void *lst)
// {
// 	free(lst);
// }

// #include <stdio.h>

// int main()
// {
// 	t_list *first = malloc(sizeof(t_list));
// 	t_list *second = malloc(sizeof(t_list));
// 	t_list *third = malloc(sizeof(t_list));
// 	t_list *fourth = malloc(sizeof(t_list));

// 	first->next = second;
// 	second->next = third;
// 	third->next = fourth;
// 	fourth->next = NULL;

// 	first->content = ft_strdup("hello");
// 	second->content = ft_strdup("world");
// 	third->content = ft_strdup("lohell");
// 	fourth->content = ft_strdup("deworl");

// 	t_list **lst = &first;

// 	printf("%s\n", (char *)first->content);
// 	printf("%s\n", (char *)second->content);
// 	printf("%s\n", (char *)third->content);
// 	printf("%s\n\n", (char *)fourth->content);

// 	printf("%p\n", first);
// 	printf("%p\n", second);
// 	printf("%p\n", third);
// 	printf("%p\n\n", fourth);

// 	ft_lstclear(lst, del);

// 	printf("%s", (char *)first->content);
// 	printf("%s", (char *)second->content);
// 	printf("%s", (char *)third->content);
// 	printf("%s", (char *)fourth->content);

// 	return 0;
// }
//
//

//
//
//
// need a temp bc even if 
//  u dont  the ->next (u dont free the next pointer)
//
// freeing the current *
// make you loose the adress of the next *
//
//
//  LAST DEL()
//  to free the last node that does not have a next;