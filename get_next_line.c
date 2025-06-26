/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:34:51 by aamini            #+#    #+#             */
/*   Updated: 2025/06/26 19:58:49 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static char	*ft_free(char **ptr)
// {
// 	if (*ptr)
// 		free(*ptr);
// 	*ptr = NULL;
// 	return (NULL);
// }

char	*extract_line(char *buffer)
{
	int		i = 0;
	char 	*str;

	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	int j = 0;
	while (j < i)
	{
		str[j] = buffer[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++; 
	if (!buffer[i])
		return (free(buffer), NULL);
	temp = malloc(ft_strlen(buffer) - i + 1);
	if (!temp)
		return (NULL);
	while (buffer[i])
		temp[j++] = buffer[i++];
	temp[j] = '\0';
	free(buffer);
	return (temp);
}

// static char	*extract_line2(char **buffer)
// {
// 	int		i;
// 	char	*line;
// 	char	*new_buffer;

// 	i = 0;
// 	if (!*buffer || **buffer == '\0')
// 		return (ft_free(buffer));
// 	while ((*buffer)[i] && (*buffer)[i] != '\n')
// 		i++;
// 	if ((*buffer)[i] == '\n')
// 		i++;line
// 	line = (char *)malloc(i + 1);
// 	if (!line)buffer = 
// 		return (ft_free(buffer));
// 	i = 0;
// 	while ((*buffer)[i] && (*bu	while ((next_line = get_next_line(fd)))
	// {
	// 	printf("%s",  next_line);
	// }
	// free(next_line);
	// next_line = NULL;
// 		line[i++] = '\n';
// 	line[i] = '\0';
// 	new_buffer = ft_strdup(*buffer + i);
// 	if (!new_buffer)
// 		return (NULL);
// 	free(*buffer);line
// 	*buffer = new_buffer;
// 	return (line);
// }

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	char		*read_buf;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(read_buf), free(buffer), NULL);
		read_buf[bytes_read] = '\0';
		temp = ft_strjoin(buffer, read_buf);
		free(buffer);
		buffer = temp;
	}
	free(read_buf);
	char *line = extract_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
