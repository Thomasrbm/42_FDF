/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:54:52 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 17:57:59 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_maillon;

	new_maillon = malloc(sizeof(t_list));
	if (!new_maillon)
		return (NULL);
	new_maillon->content = content;
	new_maillon->next = NULL;
	return (new_maillon);
}

// #include <stdio.h>

// int main()
// {
// 	t_list *new_maillon = ft_lstnew("Hello");
// 	printf("%s\n", (char *)new_maillon->content);
// 	printf("%p\n", new_maillon->next);
// 	return 0;
// }
// maillon = elem
//
// the malloc understands that you 
// allocate what is in structure
// so 2 pointers
//
// pointers have same size
// regardless of type
//
//
// we declare t_list * bc
//
// list are dynamic so we use
// malloc
// malloc returns a pointer
// to the new zone;
// 
// so the list point to that zone