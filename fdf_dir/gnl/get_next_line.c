/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:41:38 by throbert          #+#    #+#             */
/*   Updated: 2025/03/23 16:00:42 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *buffer)
{
	char	*line;
	int		index;

	if (!buffer || *buffer == '\0')
		return (NULL);
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	line = malloc((index + 2) * sizeof(char));
	if (!line)
		return (NULL);
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	line[index] = buffer[index];
	line[index + 1] = '\0';
	return (line);
}

char	*buffer_clean(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*read_file(int fd, char *buffer)
{
	char	*temp_buffer;
	char	*new_buffer;
	int		bytes_read;

	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (free(buffer), NULL);
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(buffer), free(temp_buffer), NULL);
	if (bytes_read == 0)
		return (free(temp_buffer), buffer);
	temp_buffer[bytes_read] = '\0';
	new_buffer = ft_strjoin(buffer, temp_buffer);
	free(temp_buffer);
	free(buffer);
	if (!new_buffer || ft_strchr(new_buffer, '\n') != NULL)
		return (new_buffer);
	return (read_file(fd, new_buffer));
}

char	*free_buffer(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd, int should_free)
{
	static char	*buffer;
	char		*line;

	if (should_free)
	{
		free_buffer(&buffer);
		return (NULL);
	}
	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = buffer_clean(buffer);
	return (line);
}
