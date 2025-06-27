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

static char	*read_from_fd(int fd, char *backup)
{
	char	*temp;
	char	*holder;
	int		bytes;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && find_newline(backup) == -1)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			free(backup);
			return (NULL);
		}
		temp[bytes] = '\0';
		holder = backup;
		backup = merge_text(backup, temp);
		free(holder);
	}
	free(temp);
	return (backup);
}

static char	*get_one_line(char *backup)
{
	char	*line;
	int		i;
	int		len;

	if (!backup || !backup[0])
		return (NULL);
	len = 0;
	while (backup[len] && backup[len] != '\n')
		len++;
	if (backup[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*save_remaining(char *backup)
{
	char	*new_backup;
	int		i;
	int		j;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	i++;
	j = 0;
	while (backup[i + j])
		j++;
	new_backup = malloc(j + 1);
	if (!new_backup)
		return (NULL);
	j = 0;
	while (backup[i])
		new_backup[j++] = backup[i++];
	new_backup[j] = '\0';
	free(backup);
	return (new_backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_from_fd(fd, backup);
	if (!backup)
		return (NULL);
	line = get_one_line(backup);
	backup = save_remaining(backup);
	return (line);
}
