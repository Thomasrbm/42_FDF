/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:29:23 by throbert          #+#    #+#             */
/*   Updated: 2024/10/16 19:26:27 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		i++;
		while (lst->next)
		{
			i++;
			lst = lst->next;
		}
	}
	return (i);
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
// 	printf("%d", ft_lstsize(lst));
// 	return 0;
// }
