/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:41:36 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 17:58:12 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		n--;
		((char *)s)[n] = (char)c;
	}
	return (s);
}

// #include <stdio.h>

// int main()
// {
// 	char str[] = "Hello";
// 	int  c = 'a';
// 	printf("%s", (char *)ft_memset(str, c,  5));
// 	return 0;
// }