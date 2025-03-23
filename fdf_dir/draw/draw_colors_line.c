/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_colors_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:15:22 by throbert          #+#    #+#             */
/*   Updated: 2025/03/23 16:29:45 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	int	i;
	int	red;
	int	green;
	int	blue;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	i = (x * (data->color_depth / 8)) + (y * data->size_line);
	blue = color % 256;
	color = color / 256;
	green = color % 256;
	color = color / 256;
	red = color % 256;
	data->img_data[i++] = blue;
	data->img_data[i++] = green;
	data->img_data[i++] = red;
}

int	interpolate_two_color_for_line(int start_color,
		int end_color, float gradient_ratio)
{
	int	red_component;
	int	green_component;
	int	blue_component;

	red_component = (int)((1 - gradient_ratio) * ((start_color >> 16) & 0xFF)
			+ gradient_ratio * ((end_color >> 16) & 0xFF));
	green_component = (int)((1 - gradient_ratio) * ((start_color >> 8) & 0xFF)
			+ gradient_ratio * ((end_color >> 8) & 0xFF));
	blue_component = (int)((1 - gradient_ratio) * (start_color & 0xFF)
			+ gradient_ratio * (end_color & 0xFF));
	return ((red_component << 16) | (green_component << 8) | blue_component);
}

void	plot_gradient_pixel(t_line pixel_data,
	t_point start, t_point end, t_data *data)
{
	float	gradient_ratio;
	int		interpolated_color;

	if (start.x == end.x && start.y == end.y)
		interpolated_color = start.color;
	else
	{
		gradient_ratio = (float)(pixel_data.current_x - start.x)
			/ (end.x - start.x);
		interpolated_color = interpolate_two_color_for_line(start.color,
				end.color, gradient_ratio);
	}
	put_pixel_to_image(data, pixel_data.current_x,
		pixel_data.current_y, interpolated_color);
}
