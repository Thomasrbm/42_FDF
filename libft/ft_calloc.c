/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:17:46 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 18:04:05 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_bzero2(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nb_elem, size_t size_elem)
{
	void	*tab;

	tab = malloc(nb_elem * size_elem);
	if (!tab)
		return (NULL);
	ft_bzero2(tab, nb_elem * size_elem);
	return (tab);
}

// #include <stdio.h>

// int main()
// {
// 	char str[] = "Hello";
// 	char *ptr = str;
// 	printf("adress : %p, result : %s\n", ptr, ptr);
// 	ptr = ft_calloc(5, 1);
// 	printf("adress changed : %p, result null: %s", ptr, ptr);
// 	return 0;
// }