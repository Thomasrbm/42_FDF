/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:13:00 by throbert          #+#    #+#             */
/*   Updated: 2024/10/21 22:09:25 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// 	t_list first;
// 	t_list new;
// 	first.next = &new;
// 	t_list *lst = &first;

// 	printf("adress     first : %p\n", &first);
// 	printf("adress new avant : %p\n\n", new.next);
// 	ft_lstadd_front(&lst, &new);
// 	printf("adress     first : %p\n", &first);
// 	printf("adress new apres : %p\n", new.next);
// 	return 0;
// }
// **lst = is ALWAYS
// 
//  pointer to the pointer
// of the first maillon
//
//
//(new.next)->content