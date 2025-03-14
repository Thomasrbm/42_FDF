/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:16:00 by throbert          #+#    #+#             */
/*   Updated: 2025/02/10 13:08:03 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_zoom(t_data *data, int x, int y, int direction)
{
	if (direction > 0)
	{
		data->zoom += 1;
		data->offset_x -= (x - data->offset_x) / data->zoom;
		data->offset_y -= (y - data->offset_y) / data->zoom;
	}
	else
	{
		if (data->zoom > 1)
		{
			data->offset_x += (x - data->offset_x) / data->zoom;
			data->offset_y += (y - data->offset_y) / data->zoom;
			data->zoom -= 1;
		}
	}
	data->needs_redraw = 1;
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		data->is_mouse_down = 1;
		data->mouse_prev_x = x;
		data->mouse_prev_y = y;
	}
	else if (button == 4)
		handle_zoom(data, x, y, 1);
	else if (button == 5)
		handle_zoom(data, x, y, -1);
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		data->is_mouse_down = 0;
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	int	dx;
	int	dy;

	if (data->is_mouse_down)
	{
		dx = x - data->mouse_prev_x;
		dy = y - data->mouse_prev_y;
		data->offset_x += dx;
		data->offset_y += dy;
		data->mouse_prev_x = x;
		data->mouse_prev_y = y;
		data->needs_redraw = 1;
	}
	return (0);
}

int	loop_hook(t_data *data)
{
	if (data->needs_redraw)
	{
		redraw(data);
		data->needs_redraw = 0;
	}
	return (0);
}
