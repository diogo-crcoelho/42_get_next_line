/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:09:05 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/13 15:03:15 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	stash[FOPEN_MAX][BUFFER_SIZE + 1];
	size_t		i;

	i = -1;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{	
		if (fd > 0 && fd < FOPEN_MAX)
			while (stash[fd][++i])
				stash[fd][i] = 0;
		return (NULL);
	}
	line = NULL;
	while (*(stash[fd]) || read(fd, stash[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, stash[fd]);
		if (next_line(stash[fd]) != -1)
			break ;
	}
	return (line);
}
