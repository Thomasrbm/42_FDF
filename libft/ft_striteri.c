/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:50:57 by throbert          #+#    #+#             */
/*   Updated: 2024/10/16 10:55:51 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// void test(unsigned int i, char *c)
// {
// 	*c = *c + i;
// }

// int main() 
// {
// 	char str[] = "0123";
// 	ft_striteri(str, test);
// 	printf("Résultat : %s\n", str);	
// 	return 0;
// }
