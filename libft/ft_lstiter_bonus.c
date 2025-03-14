/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:24:04 by throbert          #+#    #+#             */
/*   Updated: 2024/10/17 13:17:23 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	test(void *str)
// {
// 	int i = 0;

// 	while (((char *)str)[i])
// 	{
// 		if (((char *)str)[i] >= 97 && ((char *)str)[i] <= 122)
// 			((char *)str)[i] = ((char *)str)[i] - 32;
// 		str++;
// 	}	
// }

// #include <stdio.h>

// int main()
// {
// 	t_list	first;
// 	t_list	second;
// 	t_list	third;
// 	t_list *lst = &first;

// 	first.content = ft_strdup("eoeoeoe"); // deja void * donc str[] nop;
// 	second.content = ft_strdup("wowowowo");
// 	third.content = ft_strdup("elelel");

// 	first.next = &second;
// 	second.next = &third;
// 	third.next = NULL;

// 	printf("first avant : %s\n", (char *)first.content);
// 	printf("second avant : %s\n", (char *)second.content);
// 	printf("third avant : %s\n\n",  (char *)third.content);

// 	ft_lstiter(lst, test);

// 	printf("first apres : %s\n",  (char *)first.content);
// 	printf("second apres : %s\n",  (char *)second.content);
// 	printf("third apres : %s\n",  (char *)third.content);

// 	return 0;	
// }