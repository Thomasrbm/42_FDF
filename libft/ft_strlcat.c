/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:31:22 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 17:58:36 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;
	size_t	j;

	len_dst = 0;
	len_src = 0;
	i = 0;
	j = 0;
	while (src[len_src])
		len_src++;
	while (dst[len_dst] && len_dst < size)
		len_dst++;
	if (len_dst >= size)
		return (size + len_src);
	while (dst[i])
		i++;
	while (src[j] && (i < (size - 1)))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}

// #include <stdio.h>
// #include <bsd/string.h>

// int main()
// {
// 	char dst[] = "hello";
// 	char src[] = "_world";
// 	ft_strlcat(dst, src, 12);
// 	printf("Repro : %s", dst);
// 	return 0; 
// }

// int main()
// {
// 	char dst[] = "hello";
// 	char src[] = "_world";
// 	strlcat(dst, src, 12);
// 	printf("Vrai fonction : %s", dst);
// 	return 0; 
// }