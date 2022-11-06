/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:52:41 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 06:39:50 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>
void	ft_read(int fd)
{
	int		bytes;
	char	temp[BUFFER_SIZE];
	char	*line;

	line = ft_strdup("");
	while (1)
	{
		
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < BUFFER_SIZE)
			temp[bytes] = 0;
		printf("-%i-\n", bytes);
		if (!bytes)
			break;
	//	printf("--%s--\n", temp);
		line = ft_strjoin(line, temp);
	}
	printf("%s", line);
}
char	*get_next_line(int fd)
{
	static char	*stash;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ft_read(fd);

	
}

int main()
{
	int fd = open("teste.txt", O_RDONLY);
	get_next_line(fd);
}