/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:52:41 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/07 21:22:01 by dcarvalh         ###   ########.fr       */
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

char *ft_read(int fd, char **stash)
{
	int		bytes;
	char	temp[BUFFER_SIZE + 1];
	char	*line;
	char	*temp2;
	static int t;

	if (!(*stash))
		*stash = ft_strdup("");
	line = ft_strdup(*stash);
	while ((bytes = read(fd, temp, BUFFER_SIZE)) > 0)
	{

		temp[bytes] = 0;
		temp2 = ft_strjoin(line, temp);
		free (line);
		line = temp2;
		if (ft_strchr(line, '\n'))
		{	
			temp2 = get_line(line, stash);
			free (line);
			line = temp2;
			return (line);
		}
	}

	if (bytes == 0 && t == 0)
	{
		t ++;
		return (line);
	}
	free(line);
	return (NULL);
}
char	*get_next_line(int fd)
{
	static char	*stash;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	char *temp =  ft_read(fd, &stash);
	return (temp);
	
}

// int main()
// {
// 	char *temp;
// 	int fd = open("teste.txt", O_RDONLY);
// //	temp = get_next_line(fd);
// //	printf("%s\n", temp);
// 	while ((temp = get_next_line(fd)) != NULL)
// 	{

// 		printf("%s",temp);
// 		free(temp);
// 	}
// 	// temp = ft_strdup("");
// 	// get_line("teste\n123", &temp);
// }