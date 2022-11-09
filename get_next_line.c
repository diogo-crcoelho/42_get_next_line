/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:52:41 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/09 13:19:14 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

// char	*get_line(char *line, char **stash)
// {
// 	char	*new;
// 	int		i;

// 	free (*stash);
// 	*stash = ft_strdup(ft_strchr(line, '\n') + 1);
// 	if (!(*stash))
// 		return (NULL);
// 	i = 0;
// 	while (line[i] != '\n')
// 		++i;
// 	new = (char *)malloc(i + 2);
// 	if (!new)
// 		return (NULL);
// 	ft_memcpy(&new[i], "\n", 2);
// 	while (i-- > 0)
// 	 	new[i] = line[i];
// 	return (new);
// }

char	*get_line(char *line, char **stash)
{
	char	*new;
	int		i;
	int		size;

	i = 0;
	free (*stash);
	while (line[i] && line[i] != '\n')
		++i;
	size = ft_strlen(line) - i;
	if (size)
	*stash = ft_strdup(ft_strchr(line, '\n') + 1);
	if (!(*stash))
		return (NULL);
	ft_memcpy(*stash, &line[i + 1], size);
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
		*stash = ft_strdup("");
	line = ft_strdup(*stash);
	while (1)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		temp[bytes] = 0;
		if (bytes ==  0)
			break;
		if (bytes == -1)
			return (NULL);
		temp2 = ft_strjoin(line, temp);
		free (line);
		line = temp2;
		printf("%s")
		if (ft_strchr(temp, '\n'))
			return (get_line(line, stash));
	}
	*stash = ft_strdup(line);
	return (*stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	char *temp =  ft_read(fd, &stash);
	// free (stash);
	return (temp);
	
}

int main()
{
	char *temp;
	int fd = open("teste.txt", O_RDONLY);

	// get_next_line(fd);
	// get_next_line(fd);

	// temp = get_next_line(fd);
	// temp = get_next_line(fd);
	// printf("%s\n", temp);
	// while ((temp = get_next_line(fd)) != NULL)
	for(int i = 0; i < 10; i ++)
	{
		temp = get_next_line(fd);
		printf("%s",temp);
		free(temp);
	}
	// temp = ft_strdup("");
	// get_line("teste\n123", &temp);
}