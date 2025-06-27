/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:34:51 by aamini            #+#    #+#             */
/*   Updated: 2025/06/25 17:12:37 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *str)
{
	int	pos;

	pos = 0;
	if (!str)
		return (-1);
	while (str[pos])
	{
		if (str[pos] == '\n')
			return (pos);
		pos++;
	}
	return (-1);
}

int	count_chars(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter])
		counter++;
	return (counter);
}

char	*merge_text(char *old_text, char *new_text)
{
	char	*result;
	int		size;
	int		i;
	int		j;
	int     need_free;

	need_free = 0;
	if (!old_text)
	{
		old_text = malloc(1);
		if (!old_text)
			return (NULL);
		old_text[0] = '\0';
		need_free = 1;
	}
	size = count_chars(old_text) + count_chars(new_text);
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (old_text[++i])
		result[i] = old_text[i];
	j = 0;
	while (new_text[j])
		result[i++] = new_text[j++];
	result[i] = '\0';
	if (need_free)
        free(old_text);
	return (result);
}
