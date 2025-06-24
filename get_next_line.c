/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:34:51 by aamini            #+#    #+#             */
/*   Updated: 2025/06/06 13:35:40 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **buf)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	if (!*buf || !**buf)
		return (NULL);
	while ((*buf)[i] && (*buf)[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while ((*buf)[i] && (*buf)[i] != '\n')
	{
		line[i] = (*buf)[i];
		i++;
	}
	if ((*buf)[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	tmp = ft_strdup(*buf + i);
	free(*buf);
	*buf = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		read_bytes;
	char		temp_buffer[BUFFER_SIZE + 1];
	char		*temp_joined;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	read_bytes = 1;
	while (!ft_strchr(buffer, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), buffer = NULL, NULL);
		temp_buffer[read_bytes] = '\0';
		temp_joined = ft_strjoin(buffer, temp_buffer);
		free(buffer);
		buffer = temp_joined;
		if (!buffer)
			return (NULL);
	}
	return (extract_line(&buffer));
}
