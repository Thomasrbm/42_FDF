/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:04:03 by throbert          #+#    #+#             */
/*   Updated: 2024/10/16 16:58:17 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>

// int main()
// {
// 	t_list	first;
// 	t_list	second;
// 	t_list	third;

// 	first.next = &second;
// 	second.next = &third;
// 	third.next = NULL;
// 	t_list *lst = &first;

// 	first.content = "first";
// 	second.content = "second";
// 	third.content =  "third";
// 	lst = ft_lstlast(lst);
// 	printf("%s", (char *)lst->content);
// 	return (0);
// }