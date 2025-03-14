/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:11:28 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 17:58:38 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// #include <stdio.h>
// #include <bsd/string.h>

// int main()
// {
// 	char dest[] = "hello";
// 	char src[] = "world";

// 	printf("taille return : %zu\n", ft_strlcpy(dest, src, 6));
// 	printf("taille return : %zu\n", strlcpy(dest, src, 6));
// 	printf("Reproduction : %s\n", dest);
// 	return 0;
// }