/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_colors_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:15:15 by throbert          #+#    #+#             */
/*   Updated: 2025/02/10 02:15:15 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	interpolate_palette_color(t_color *palette, int size, float percentage)
{
	int		i;
	float	local_percentage;
	int		color[3];

	i = 0;
	while (i < size - 1)
	{
		if (percentage >= palette[i].position
			&& percentage <= palette[i + 1].position)
			break ;
		i++;
	}
	local_percentage = (percentage - palette[i].position)
		/ (palette[i + 1].position - palette[i].position);
	color[0] = (int)((1.0f - local_percentage)
			* ((palette[i].color >> 16) & 0xFF)
			+ local_percentage * ((palette[i + 1].color >> 16) & 0xFF));
	color[1] = (int)((1.0f - local_percentage)
			* ((palette[i].color >> 8) & 0xFF)
			+ local_percentage * ((palette[i + 1].color >> 8) & 0xFF));
	color[2] = (int)((1.0f - local_percentage) * (palette[i].color & 0xFF)
			+ local_percentage * (palette[i + 1].color & 0xFF));
	return ((color[0] << 16) | (color[1] << 8) | color[2]);
}

int	compute_color(int z, t_data *data)
{
	t_color	*palette;
	int		size;
	float	percentage;

	if (!data->use_palette)
		return (0xFFFFFF);
	get_palette(data, &palette, &size);
	if (data->map->max_z == data->map->min_z)
		percentage = 0.0f;
	else
		percentage = (float)(z - data->map->min_z)
			/ (float)(data->map->max_z - data->map->min_z);
	return (interpolate_palette_color(palette, size, percentage));
}

void	init_color_point(t_data *data, int x, int y, t_point *point)
{
	point->x = x;
	point->y = y;
	point->z = data->map->grid[y][x];
	if (data->use_palette)
		point->color = compute_color(point->z, data);
	else if (data->map->color[y][x] != -1)
		point->color = data->map->color[y][x];
	else
		point->color = 0xFFFFFF;
}
