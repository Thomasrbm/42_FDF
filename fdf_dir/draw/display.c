/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:03:28 by throbert          #+#    #+#             */
/*   Updated: 2025/02/09 11:02:29 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	display_movement_speed(t_data *data)
{
	char	*speed_str;

	speed_str = ft_itoa((int)data->movement_speed);
	if (!speed_str)
		return ;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 250, 0xFFFFFF,
		"Movement Speed: ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 250, 0xFFFFFF, speed_str);
	free(speed_str);
}

void	display_commands(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF,
		"Commands:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 30, 0xFFFFFF,
		"Move: < ^ v >");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0xFFFFFF,
		"Adjust speed: + / -");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 70, 0xFFFFFF,
		"Zoom: mouse roll");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 90, 0xFFFFFF,
		"Adjust Height: T / Y");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 110, 0xFFFFFF,
		"Rotate X: W / S");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 130, 0xFFFFFF,
		"Rotate Y: A / D");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 150, 0xFFFFFF,
		"Rotate Z: Q / E");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 170, 0xFFFFFF,
		"Change Projection: P");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 190, 0xFFFFFF,
		"Toggle color: C");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 210, 0xFFFFFF,
		"Toggle Palette: V");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 230, 0xFFFFFF,
		"Exit: ESC");
	display_movement_speed(data);
}
