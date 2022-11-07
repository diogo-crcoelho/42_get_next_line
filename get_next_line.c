/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:52:41 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/07 18:31:28 by dcarvalh         ###   ########.fr       */
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
	if (!ft_strchr(line, '\n'))
		return (NULL);
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

char *ft_read(int fd, char **stash)
{
	int		bytes;
	char	temp[BUFFER_SIZE + 1];
	char	*line;
	char	*temp2;

	if (!(*stash))
		line = ft_strdup("");
	else
		line = ft_strdup(*stash);
	temp2 = get_line(line, stash);
	if (temp2)
		return (temp2);
	while (1)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
			return NULL;
		temp[bytes] = 0;
		temp2 = ft_strjoin(line, temp);
		free (line);
		line = temp2;
		if (bytes < BUFFER_SIZE)
			break;
	}
	return (line);
}
char	*get_next_line(int fd)
{
	static char	*stash;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	char *temp =  ft_read(fd, &stash);
	//stash = ft_strdup("Helll0\nteste123");
	//printf("%s-\n", stash);
	return(get_line(temp, &stash));
	//printf("line-%s", teste);
	//printf("stash-%s\n", stash);
	
}

int main()
{
	int fd = open("teste.txt", O_RDONLY);
	get_next_line(fd);
	char **t = NULL;
}