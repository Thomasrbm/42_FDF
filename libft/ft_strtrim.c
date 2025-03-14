/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:24:26 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 18:01:05 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_in_set(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	len_sin_set(char *s1, char *set)
{
	int	start;
	int	end;

	start = 0;
	while (is_in_set(set, s1[start]))
		start++;
	end = start;
	while (s1[end])
		end++;
	end--;
	while (end >= start && is_in_set(set, s1[end]))
		end--;
	return (end - start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		len;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	len = len_sin_set((char *)s1, (char *)set);
	trimmed = malloc((len + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	i = 0;
	j = 0;
	while (is_in_set((char *)set, s1[i]))
		i++;
	while (len > 0)
	{
		trimmed[j++] = s1[i++];
		len--;
	}
	trimmed[j] = '\0';
	return (trimmed);
}

// #include <stdio.h>

// int main()
// {
// 	char test[] = "";
// 	char *stock = ft_strtrim(test, "");
// 	printf("%s", stock);
// 	free(stock);
// 	return 0;
// }

// #include <stdio.h>

// int main()
// {
// 	char test[] = "-*-*-Hello-_-World-*-*-";
// 	char *stock = ft_strtrim(test, "-*");
// 	printf("%s", stock);
// 	free(stock);
// 	return 0;
// }