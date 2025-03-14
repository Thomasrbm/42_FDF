/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:41:28 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 17:58:31 by throbert         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*str_new;
	int		i;

	str_new = malloc((ft_strlen2((char *)s) + 1) * sizeof(char));
	if (!str_new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_new[i] = s[i];
		i++;
	}
	str_new[i] = '\0';
	return ((char *)str_new);
}

// #include <stdio.h>

// int main()
// {
// 	char base[]= "Hello_world";
// 	char *stock = ft_strdup(base);
// 	printf("%s", stock);
// 	free (stock);
// 	return 0;
// }