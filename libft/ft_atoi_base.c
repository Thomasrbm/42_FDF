/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:52:03 by throbert          #+#    #+#             */
/*   Updated: 2025/01/19 21:35:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

const char	*skip_prefix(const char *str, int base)
{
	if (base == 16 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		return (str + 2);
	return (str);
}

int	get_digit(char c, int base)
{
	int	digit;

	if (c >= '0' && c <= '9')
		digit = c - '0';
	else if (c >= 'A' && c <= 'F')
		digit = c - 'A' + 10;
	else if (c >= 'a' && c <= 'f')
		digit = c - 'a' + 10;
	else
		return (-1);
	if (digit >= base)
		return (-1);
	return (digit);
}

int	ft_atoi_base(const char *str, int base)
{
	int		result;
	int		digit;
	int		sign;

	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = get_sign(&str);
	str = skip_prefix(str, base);
	digit = get_digit(*str, base);
	while (digit != -1)
	{
		result = result * base + digit;
		str++;
		digit = get_digit(*str, base);
	}
	return (result * sign);
}
