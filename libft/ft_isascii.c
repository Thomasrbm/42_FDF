/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:35:38 by throbert          #+#    #+#             */
/*   Updated: 2024/10/21 19:58:37 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
// 	printf("%d\n", ft_isascii('\0'));
// 	printf("%d", isascii('\0'));
// 	return 0;
// }

// standard ascii = 128 symbols in 7 bits
// extended ; 256 on 8bit
// \200 =  non ASCII like ISO-8859-1 or UTF-8
// 'Þ' = same 
