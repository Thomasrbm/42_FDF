/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:20:30 by throbert          #+#    #+#             */
/*   Updated: 2024/10/25 17:57:42 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_malloc2(int n)
{
	char	*str;

	str = malloc((n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

static long	fill_case(char *str, long num)
{
	if (num == 0)
	{
		str[0] = '0';
	}
	else if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*str_stock;
	int		len;
	long	num;

	num = n;
	len = ft_len(n);
	str_stock = ft_malloc2(len);
	if (!str_stock)
		return (NULL);
	num = fill_case(str_stock, num);
	str_stock[len] = '\0';
	len--;
	while (num > 0)
	{
		str_stock[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str_stock);
}

// #include <stdio.h>

// int main()
// {
// 	char *str = ft_itoa(0);
// 	printf("%s", str);
// 	return 0;
// }
