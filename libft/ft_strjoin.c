/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:01:27 by throbert          #+#    #+#             */
/*   Updated: 2025/01/13 22:38:59 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strjoin_copy(char *output, const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			output[i] = s1[i];
			i++;
		}
	}
	j = 0;
	if (s2)
	{
		while (s2[j] != '\0')
		{
			output[i] = s2[j];
			i++;
			j++;
		}
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*output;

	if (!s1 && !s2)
		return (NULL);
	len = 0;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	ft_strjoin_copy(output, s1, s2);
	output[len] = '\0';
	return (output);
}

// #include <stdio.h>

// int main()
// {
// 	char s1[] = "Hello_";
// 	char s2[] = "World";
// 	char *stock = ft_strjoin(s1, s2);
// 	printf("%s", stock);
// 	free(stock);
// }
