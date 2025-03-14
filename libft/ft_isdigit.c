/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:35:44 by throbert          #+#    #+#             */
/*   Updated: 2024/10/21 19:58:32 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%d", ft_isprint('d'));
// 	printf("%d", ft_isprint('8'));
// 	return 0;
// }