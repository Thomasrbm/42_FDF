/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_allocate_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:46:40 by throbert          #+#    #+#             */
/*   Updated: 2025/02/10 05:34:24 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_line_width(char *line)
{
	char	**split;
	int		width;

	split = ft_split(line, ' ');
	if (!split)
		return (-1);
	width = 0;
	while (split[width])
	{
		free(split[width]);
		width++;
	}
	free(split);
	return (width);
}

int	process_dimension_line(char *line, int fd, t_map *map)
{
	char	*trim;
	int		width;

	trim = ft_strtrim(line, " \n\t\r");
	if (!trim)
	{
		ft_putstr_fd("Error: Memory allocation failed.\n", 2);
		free_map(map);
		get_next_line(fd, 1);
		exit(EXIT_FAILURE);
	}
	width = get_line_width(trim);
	free(trim);
	return (width);
}

void	free_trim_and_line(char *trim, char *line)
{
	free(trim);
	free(line);
}

void	count_dimensions(int fd, t_map *map)
{
	char	*line;
	char	*trim;
	int		width;

	map->height = 0;
	map->width = -1;
	line = get_next_line(fd, 0);
	while (line)
	{
		trim = ft_strtrim(line, " \n\t\r");
		if (trim && trim[0])
		{
			width = get_line_width(trim);
			if (!check_inconsistent_row_width(width, map))
			{
				free_trim_and_line(trim, line);
				free_map(map);
				exit(EXIT_FAILURE);
			}
			map->height++;
		}
		free_trim_and_line(trim, line);
		line = get_next_line(fd, 0);
	}
}

void	parse_map(char *filename, t_map *map)
{
	int	fd;

	open_file_and_handle_error(filename, &fd);
	count_dimensions(fd, map);
	close(fd);
	allocate_map_memory(map);
	initialize_map_values(map);
	fd = open(filename, O_RDONLY);
	read_and_fill_grid(fd, map);
	close(fd);
	compute_min_max_z(map);
}
