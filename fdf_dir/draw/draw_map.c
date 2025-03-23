/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:44:57 by throbert          #+#    #+#             */
/*   Updated: 2025/03/23 16:29:45 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	initialize_line(t_point start, t_point end, t_line *line)
{
	line->delta_x = abs(end.x - start.x);
	line->delta_y = -abs(end.y - start.y);
	if (start.x < end.x)
		line->step_x = 1;
	else
		line->step_x = -1;
	if (start.y < end.y)
		line->step_y = 1;
	else
		line->step_y = -1;
	line->error_margin = line->delta_x + line->delta_y;
	line->current_x = start.x;
	line->current_y = start.y;
}

void	draw_line(t_point start, t_point end, t_data *data)
{
	t_line	line;
	int		error_temp;

	initialize_line(start, end, &line);
	while (1)
	{
		plot_gradient_pixel(line, start, end, data);
		if (line.current_x == end.x && line.current_y == end.y)
			break ;
		error_temp = 2 * line.error_margin;
		if (error_temp >= line.delta_y)
		{
			line.error_margin += line.delta_y;
			line.current_x += line.step_x;
		}
		if (error_temp <= line.delta_x)
		{
			line.error_margin += line.delta_x;
			line.current_y += line.step_y;
		}
	}
}

void	draw_line_if_valid(t_data *data, t_point *a, int offset_x, int offset_y)
{
	t_point	b;

	b.x = a->x + offset_x;
	b.y = a->y + offset_y;
	if (b.x < data->map->width && b.y < data->map->height)
	{
		b.z = data->map->grid[b.y][b.x];
		if (data->use_palette)
			b.color = compute_color(b.z, data);
		else if (data->map->color[b.y][b.x] != -1)
			b.color = data->map->color[b.y][b.x];
		else
			b.color = 0xFFFFFF;
		draw_line(project(*a, data), project(b, data), data);
	}
}

void	draw_map(t_data *data)
{
	int		x;
	int		y;
	t_point	start_point;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			init_color_point(data, x, y, &start_point);
			draw_line_if_valid(data, &start_point, 1, 0);
			draw_line_if_valid(data, &start_point, 0, 1);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_ptr, 0, 0);
	display_commands(data);
}
