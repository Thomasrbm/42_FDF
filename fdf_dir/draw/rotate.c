/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:44:25 by throbert          #+#    #+#             */
/*   Updated: 2025/02/08 01:55:52 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(float *y, float *z, float angle)
{
	float	previous_y;
	float	previous_z;

	previous_y = *y;
	previous_z = *z;
	*y = previous_y * cos(angle) + previous_z * sin(angle);
	*z = -previous_y * sin(angle) + previous_z * cos(angle);
}

void	rotate_y(float *x, float *z, float angle)
{
	float	previous_x;
	float	previous_z;

	previous_x = *x;
	previous_z = *z;
	*x = previous_x * cos(angle) + previous_z * sin(angle);
	*z = -previous_x * sin(angle) + previous_z * cos(angle);
}

void	rotate_z(float *x, float *y, float angle)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(angle) - previous_y * sin(angle);
	*y = previous_x * sin(angle) + previous_y * cos(angle);
}
