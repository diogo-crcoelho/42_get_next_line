/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:09:05 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/11 19:27:20 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	stash[BUFFER_SIZE + 1];
	size_t		i = -1;

	line = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{	
		while (stash[++i])
			stash[i] = 0;
		return (NULL);
	}
	while (*stash || read(fd, stash, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, stash);
		if (next_line(stash))
			break;
	}
	return (line);
}

