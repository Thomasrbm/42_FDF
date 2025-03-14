/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:33:30 by throbert          #+#    #+#             */
/*   Updated: 2025/02/10 06:38:05 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_hooks_and_run(t_data *data)
{
	draw_map(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win_ptr, 4, 1L << 2, mouse_press, data);
	mlx_hook(data->win_ptr, 5, 1L << 3, mouse_release, data);
	mlx_hook(data->win_ptr, 6, 1L << 6, mouse_move, data);
	mlx_hook(data->win_ptr, 17, 0L, close_window, data);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!validate_args(argc, argv))
		return (1);
	if (!initialize_map(argv[1], &data))
		return (1);
	if (!initialize_mlx(&data))
		return (1);
	setup_hooks_and_run(&data);
	get_next_line(-1, 1);
	free_map(data.map);
	return (0);
}
