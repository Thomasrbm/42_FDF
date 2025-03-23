/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:46:13 by throbert          #+#    #+#             */
/*   Updated: 2025/02/08 01:54:44 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	check_open_and_file_format(char *filename)
{
	size_t	len;
	int		fd;
	char	buf[1];

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".fdf", 4) != 0)
	{
		ft_putstr_fd("Error: File must have a .fdf extension.\n", 2);
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: No permission OR File does not exist.\n", 2);
		return (0);
	}
	if (read(fd, buf, 1) == 0)
	{
		ft_putstr_fd("Error: File is empty.\n", 2);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	validate_args(int argc, char **av)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <file.fdf>\n", 2);
		return (0);
	}
	if (!check_open_and_file_format(av[1]))
		return (0);
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;

	str = ft_strtrim(str, " \t\n\r");
	if (!str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			free(str);
			return (0);
		}
		i++;
	}
	free(str);
	return (1);
}

int	is_valid(char *str)
{
	int		num;
	char	*trim;

	trim = ft_strtrim(str, " \t\n\r");
	if (!trim || !is_valid_number(trim))
	{
		free(trim);
		return (0);
	}
	num = ft_atoi(trim);
	free(trim);
	if (num > 10000 || num < -10000)
		return (0);
	return (1);
}

int	is_valid_hexa(char *str, t_map *map)
{
	int		i;
	char	*trim;

	trim = ft_strtrim(str, " \t\n\r");
	if (!trim)
		error_exit(map, "Error: Allocation failed in is_valid_hexa.\n");
	i = 0;
	if (trim[i] == '0' && trim[i + 1])
	{
		if (trim[i + 1] == 'x' || trim[i + 1] == 'X')
			i += 2;
	}
	while (trim[i])
	{
		if (!(trim[i] >= '0' && trim[i] <= '9')
			&& !(trim[i] >= 'a' && trim[i] <= 'f')
			&& !(trim[i] >= 'A' && trim[i] <= 'F'))
		{
			free(trim);
			return (0);
		}
		i++;
	}
	free(trim);
	return (1);
}
