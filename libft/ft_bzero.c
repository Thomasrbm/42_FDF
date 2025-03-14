/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:43:14 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 17:57:14 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

// #include <stdio.h>

// int main()
// {
// 	char str[] = "Hello";
// 	char *ptr = str;
// 	printf("%p, %s\n", ptr, ptr);
// 	ft_bzero(str, 5);
// 	printf("%p, %s\n", ptr, ptr);
// 	return 0;
// }