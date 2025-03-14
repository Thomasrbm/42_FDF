/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:38:50 by throbert          #+#    #+#             */
/*   Updated: 2025/02/10 00:56:46 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(t_map *map, char *msg)
{
	ft_putstr_fd(msg, 2);
	get_next_line(-1, 1);
	if (map)
		free_map(map);
	exit(EXIT_FAILURE);
}

int	fill_cell(char *cell_str, t_map *map, int line_number, int cell_number)
{
	char	**split_cell;

	split_cell = ft_split(cell_str, ',');
	if (!split_cell)
		return (0);
	if (!is_valid(split_cell[0]))
	{
		free_split(split_cell);
		return (0);
	}
	map->grid[line_number][cell_number] = ft_atoi(split_cell[0]);
	if (split_cell[1])
	{
		if (!is_valid_hexa(split_cell[1], map))
		{
			free_split(split_cell);
			return (0);
		}
		map->color[line_number][cell_number] = ft_atoi_base(split_cell[1], 16);
	}
	else
		map->color[line_number][cell_number] = -1;
	free_split(split_cell);
	return (1);
}

void	allocate_line_number(t_map *map, int line_number)
{
	int	cell_num;

	map->grid[line_number] = malloc(sizeof(int) * map->width);
	map->color[line_number] = malloc(sizeof(int) * map->width);
	if (!map->grid[line_number] || !map->color[line_number])
	{
		ft_putstr_fd("Error: Memory allocation failed for grid line.\n", 2);
		exit(EXIT_FAILURE);
	}
	cell_num = 0;
	while (cell_num < map->width)
	{
		map->grid[line_number][cell_num] = 0;
		map->color[line_number][cell_num] = -1;
		cell_num++;
	}
}

void	parse_line(char *line, t_map *map, int line_number)
{
	char	**line_split;
	int		cell_num;

	line_split = ft_split(line, ' ');
	if (!line_split)
	{
		free(line);
		error_exit(map, "Error: Memory allocation failed.\n");
	}
	allocate_line_number(map, line_number);
	cell_num = 0;
	while (cell_num < map->width)
	{
		if (!line_split[cell_num]
			|| !fill_cell(line_split[cell_num], map, line_number, cell_num))
		{
			free_split(line_split);
			free(line);
			error_exit(map, "Error: Invalid cell data.\n");
		}
		cell_num++;
	}
	free_split(line_split);
}

void	read_and_fill_grid(int fd, t_map *map)
{
	char	*line;
	char	*trim;
	int		line_number;

	line_number = 0;
	line = get_next_line(fd, 0);
	while (line)
	{
		trim = ft_strtrim(line, " \n\t\r");
		if (!trim)
		{
			free(line);
			error_exit(map, "Error: Memory allocation failed for trimming.\n");
		}
		free(line);
		if (trim && trim[0])
		{
			parse_line(trim, map, line_number);
			line_number++;
		}
		free(trim);
		line = get_next_line(fd, 0);
	}
	get_next_line(fd, 1);
}
