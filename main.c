/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:31:41 by aamini            #+#    #+#             */
/*   Updated: 2025/06/26 20:03:18 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		return (1);
	}
	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		printf("%d, %s", count, next_line);
		count++;
		free(next_line);
		next_line = NULL;
		next_line = get_next_line(fd);
	}
	free(next_line);
	close(fd);
	return (0);
}
