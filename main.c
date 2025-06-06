/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:31:41 by aamini            #+#    #+#             */
/*   Updated: 2025/06/06 13:38:33 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h" 

int main(void)
{
  int    fd;
  char  *next_line;
  int  count;

  count = 0;
  fd = open("example.txt", O_RDONLY);
  while (1)
  {
  next_line = get_next_line(fd);
  if (next_line == NULL)
  break;
  count++;
  printf("[%d]:%s\n", count, next_line); //count is to show you the line numbers
  next_line = NULL;
  }
  close(fd);
  return (0);
}