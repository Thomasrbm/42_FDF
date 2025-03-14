/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:45:26 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 17:18:01 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen2(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (little[0] == '\0')
		return ((char *) big);
	i = 0;
	little_len = ft_strlen2((char *)little);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] && big[i + j] == little[j] && (i + j) < len)
			{
				if (j == little_len - 1)
					return ((char *)&big[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <bsd/string.h>

// int    main(void)
// {
//     char    big[] = "bjonjour a tous";
//     char    little[] = "jour";
//     size_t    len = 9;

//     printf("%s\n", ft_strnstr(big, little, len));
// 	printf("%s", strnstr(big, little, len));
// }