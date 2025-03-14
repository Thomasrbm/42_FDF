/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:41:55 by throbert          #+#    #+#             */
/*   Updated: 2024/11/19 00:09:01 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c )
{
	char	*str;

	str = (char *)s;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

// #include <stdio.h>

// int    main(void)
// {
//     char    s[] = "bonjour";
//     int        c = '\0';

//     printf("%s", ft_strrchr(s, c));
// 	if (&ft_strrchr == 0)
// 		printf("C'EST NULL");
// }