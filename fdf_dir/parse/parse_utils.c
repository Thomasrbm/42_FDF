/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 04:16:08 by throbert          #+#    #+#             */
/*   Updated: 2025/02/10 04:16:08 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	allocate_map_memory(t_map *map)
{
	map->grid = malloc(sizeof(int *) * map->height);
	map->color = malloc(sizeof(int *) * map->height);
	if (!map->grid || !map->color)
	{
		free_map(map);
		ft_putstr_fd("Error: Memory allocation failed for grid or color.\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	initialize_map_values(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		map->grid[i] = NULL;
		map->color[i] = NULL;
		i++;
	}
	map->min_z = INT_MAX;
	map->max_z = INT_MIN;
}

void	open_file_and_handle_error(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd("Error: File cannot be opened.\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	check_inconsistent_row_width(int width, t_map *map)
{
	if (map->width == -1)
	{
		map->width = width;
		return (1);
	}
	else if (width != map->width)
	{
		ft_putstr_fd("Error: Inconsistent row width in map.\n", 2);
		get_next_line(-1, 1);
		return (0);
	}
	return (1);
}

void	compute_min_max_z(t_map *map)
{
	int	i;
	int	j;

	map->min_z = INT_MAX;
	map->max_z = INT_MIN;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] < map->min_z)
				map->min_z = map->grid[i][j];
			if (map->grid[i][j] > map->max_z)
				map->max_z = map->grid[i][j];
			j++;
		}
		i++;
	}
}
