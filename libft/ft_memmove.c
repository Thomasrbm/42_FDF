/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:47:40 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 18:22:02 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy2(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = n;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		ft_memcpy2(dest, src, n);
	else
	{
		while (i > 0)
		{
			i--;
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	return (dest);
}

// #include <stdio.h>

// Dest is before

// int main()
// {
//     char dest[] = "Hello_World";
//     char *src = &dest[5];
// 	char *stock1 = (char *)ft_memmove(dest, src, 6);
// 	char *stock2 = (char *)memmove(dest, src, 6);
//     printf("%s\n", stock1);
// 	printf("%s\n", stock2);
//     return 0;
// }

// Dest is after

// int main()
// {
//     char src[] = "Hello_World";
//     char *dest = &src[5];
// 	char *stock1 = (char *)ft_memmove(dest, src, 6);
// 	char *stock2 = (char *)memmove(dest, src, 6);
//     printf("%s\n", stock1);
// 	printf("%s\n", stock2);
//     return 0;
// }

// int main()
// {
//     char src[] = "Hello_World";
//     char dest[12];

//     ft_memmove(dest, src, 6);
//     dest[6] = '\0';
//     printf("%s\n", dest);

//     memmove(dest, src, 6);
//     dest[6] = '\0';
//     printf("%s", dest);

//     return 0;
// }