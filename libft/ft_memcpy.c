/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:46:20 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 18:20:50 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>

// int main()
// {
// 	char *dest = NULL;
// 	char *src =  NULL;
// 	printf("%s", (char *)memcpy(dest, src, 5));
// 	printf("%s", (char *)ft_memcpy(dest, src, 5));
// 	return 0;
// }

// int main()
// {
// 	char dest[] = "hello";
// 	char src[] = "world";
// 	printf("%s\n", (char *)memcpy(dest, src, 5));
// 	printf("%s", (char *)ft_memcpy(dest, src, 5));
// 	return 0;
// }