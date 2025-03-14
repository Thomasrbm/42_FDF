/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:27:30 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 17:57:51 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

// void	del(void *lst)
// {
// 	free(lst);
// }

// #include <stdio.h>

// int	main()
// {
// 	t_list	*first = malloc(sizeof(t_list));
// 	t_list	*second = malloc(sizeof(t_list));
// 	first->next = second;
// 	second->next = NULL;
// 	first->content = ft_strdup("hello");
// 	printf("avant le free : %s\n", (char *)first->content );
// 	printf("avant le free : %p\n\n", first->next );
// 	ft_lstdelone(first, del);

// 	// prouve content free ===>
// 	// printf("apres le free : %s\n", (char *)first->content ); 

// 	// free(first->next); // prouve que next not free car when done 
// 	printf("apres le free, next intact : %p\n", second); 
//	// second ne s affiche plus
//
// 	free(second);
// 	return 0;
// }

// SEG FAULT NORMAL : NOTHING LEFT
//

// WHY DEL AND FREE
//
// amibiguous, either just use
// free in del OR use both separetly.
//
//
// Del is like a custom free.
// here it does the same
// but in some more complicated case you
// can add more line which you cannot do by
// a simple free 
// +
// you can modify del without changing the rest of the code.
// more flexible
//
// u can add some condition etc.
//