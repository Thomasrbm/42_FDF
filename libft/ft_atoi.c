/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:51:18 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 01:15:35 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	minus;

	i = 0;
	minus = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * minus);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// 	printf("%d\n", ft_atoi(" \f\n\r\t\v   -2147483648  "));
// 	printf("%d", atoi(" \f\n\r\t\v    -2147483648  "));
// 	return 0;
// }
