/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:09:05 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/09 16:28:13 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

char	*get_line(char *line, char **stash)
{
	char	*new;
	int		i;

	free (*stash);
	*stash = ft_strdup(ft_strchr(line, '\n') + 1);
	if (!(*stash))
		return (NULL);
	i = 0;
	while (line[i] != '\n')
		++i;
	new = (char *)malloc(i + 2);
	if (!new)
		return (NULL);
	ft_memcpy(&new[i], "\n", 2);
	while (i-- > 0)
	 	new[i] = line[i];
	return (new);
}

char	*ft_read(int fd, char **stash)
{
	int		bytes;
	char	temp[BUFFER_SIZE + 1];
	char	*line;
	char	*temp2;

	if (!(*stash))
		*stash = ft_strdup("");
	line = ft_strdup(*stash);
	while (1)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		if (bytes == 0)
			break;
		temp[bytes] = 0;
		temp2 = ft_strjoin(line, temp);
		free (line);
		line = temp2;
		if (ft_strchr(temp, '\n'))
			return (get_line(line, stash));
	}
	*stash = ft_strdup(line);
	free (line);
	return (NULL);	
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	line = ft_read(fd, &stash);
	if (line)
		return (line);	
	line = stash;
	stash = NULL;
	if (*line)
		return (line);
	return (NULL);
	// printf("-%s\n", line);
}

int main()
{
	char *temp;
	int fd = open("teste.txt", O_RDONLY);

	//get_next_line(fd);
	// get_next_line(fd);

	// temp = get_next_line(fd);
	// temp = get_next_line(fd);
	// printf("%s\n", temp);
	while ((temp = get_next_line(fd)) != NULL)
	// for(int i = 0; i < 10; i ++)
	{
//		temp = get_next_line(fd);
		printf("%s",temp);
		free(temp);
	}
	// temp = ft_strdup("");
	// get_line("teste\n123", &temp);
}
