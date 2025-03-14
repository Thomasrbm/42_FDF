/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:18:53 by throbert          #+#    #+#             */
/*   Updated: 2025/02/10 04:36:03 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw(t_data *data)

{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->color_depth,
			&data->size_line, &data->color_endian_order);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_ptr, 0, 0);
	display_commands(data);
}

int	close_window(t_data *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->map)
		free_map(data->map);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(0);
	return (0);
}

void	adjust_speed(int key, t_data *data)
{
	if (key == XK_KP_Add)
	{
		if (data->movement_speed < 50)
			data->movement_speed += 3;
	}
	else if (key == XK_KP_Subtract)
	{
		if (data->movement_speed > 1)
			data->movement_speed -= 3;
	}
}

void	key_hook_extended(int keycode, t_data *data)
{
	if (keycode == KEY_UP)
		data->offset_y -= (10 * data->movement_speed);
	else if (keycode == KEY_DOWN)
		data->offset_y += (10 * data->movement_speed);
	else if (keycode == KEY_LEFT)
		data->offset_x -= (10 * data->movement_speed);
	else if (keycode == KEY_RIGHT)
		data->offset_x += (10 * data->movement_speed);
	else if (keycode == KEY_ROTATE_X_UP)
		data->angle_x += 0.02f;
	else if (keycode == KEY_ROTATE_X_DOWN)
		data->angle_x -= 0.02f;
	else if (keycode == KEY_ROTATE_Y_UP)
		data->angle_y += 0.02f;
	else if (keycode == KEY_ROTATE_Y_DOWN)
		data->angle_y -= 0.02f;
	else if (keycode == KEY_ROTATE_Z_UP)
		data->angle_z += 0.02f;
	else if (keycode == KEY_ROTATE_Z_DOWN)
		data->angle_z -= 0.02f;
	if (keycode == KEY_PAGE_UP)
		data->z_divisor -= 0.5f;
	else if (keycode == KEY_PAGE_DOWN)
		data->z_divisor += 0.5f;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_PROJECTION)
	{
		data->projection = (data->projection + 1) % 2;
		redraw(data);
	}
	else if (keycode == KEY_TOGGLE_COLOR)
	{
		data->use_palette = !(data->use_palette);
		redraw(data);
	}
	else if (keycode == KEY_TOGGLE_PALETTE)
	{
		data->current_palette++;
		if (data->current_palette > PALETTE_COUNT)
			data->current_palette = 1;
		redraw(data);
	}
	adjust_speed(keycode, data);
	key_hook_extended(keycode, data);
	redraw(data);
	return (0);
}
