/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:32:13 by throbert          #+#    #+#             */
/*   Updated: 2025/03/23 16:29:59 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->height)
	{
		if (map->grid && map->grid[i])
			free(map->grid[i]);
		if (map->color && map->color[i])
			free(map->color[i]);
		i++;
	}
	if (map->grid)
		free(map->grid);
	if (map->color)
		free(map->color);
	free(map);
}

void	init_data(t_data *data)
{
	data->zoom = (WINDOW_WIDTH / data->map->width) / 2;
	if (data->zoom < 1)
		data->zoom = 1;
	data->offset_x = WINDOW_WIDTH / 2;
	data->offset_y = WINDOW_HEIGHT / 2;
	data->z_divisor = 32.0;
	data->is_mouse_down = 0;
	data->mouse_prev_x = 0;
	data->mouse_prev_y = 0;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	data->projection = 0;
	data->use_palette = 0;
	data->current_palette = 1;
	data->movement_speed = MOVEMENT_SPEED;
	data->needs_redraw = 1;
}

int	initialize_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free_map(data->map);
		ft_putstr_fd("Error: MLX initialization failed.\n", 2);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "FDF");
	if (!data->win_ptr)
	{
		free_map(data->map);
		return (write(2, "Error: Window creation failed.\n", 32));
	}
	data->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->img_ptr)
	{
		free_map(data->map);
		ft_putstr_fd("Error: Image creation failed.\n", 2);
	}
	data->img_data = mlx_get_data_addr(data->img_ptr,
			&data->color_depth, &data->size_line, &data->color_endian_order);
	init_data(data);
	return (1);
}

int	initialize_map(char *filename, t_data *data)
{
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
	{
		ft_putstr_fd("Error: Memory allocation failed for map.\n", 2);
		return (0);
	}
	data->map->min_z = INT_MAX;
	data->map->max_z = INT_MIN;
	parse_map(filename, data->map);
	return (1);
}
