/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:42:56 by throbert          #+#    #+#             */
/*   Updated: 2025/02/08 01:55:37 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project(t_point p, t_data *data)
{
	float	x;
	float	y;
	float	z;

	x = p.x * data->zoom;
	y = p.y * data->zoom;
	z = p.z * (data->zoom / data->z_divisor);
	rotate_x(&y, &z, data->angle_x);
	rotate_y(&x, &z, data->angle_y);
	rotate_z(&x, &y, data->angle_z);
	if (data->projection == 0)
		isometric_projection(&x, &y, z);
	else if (data->projection == 1)
		perspective_projection(&x, &y, z);
	p.x = x + data->offset_x;
	p.y = y + data->offset_y;
	return (p);
}

void	isometric_projection(float *x, float *y, float z)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

void	perspective_projection(float *x, float *y, float z)
{
	float	d;

	d = 1000;
	*x = *x / (1 + z / d);
	*y = *y / (1 + z / d);
}
