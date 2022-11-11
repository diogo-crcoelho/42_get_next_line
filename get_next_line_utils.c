/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:52:44 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/11 19:26:55 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return ((i + (str[i] == '\n')));
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*ret;
	size_t	i;

	ret = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (str1 && str1[i])
	{	ret[i] = str1[i];
		i++;
	}
	while (*str2)
	{
		ret[i++] = *str2;
		if (*str2++ == '\n')
			break;
	}
	ret[i] = 0;
	free (str1);
	return (ret);
}

int	next_line(char *stash)
{
	int	i;
	int	j;
	
	i = 0;
	j = -1;
	while (stash[i]){

		if (j != -1)
			stash[j++] = stash[i];
		if (j == -1 && stash[i] == '\n')
			j++;
		stash [i++] = 0;
	}
	// while (stash[++i])
	// {
	// 	if (stash[i] == '\n')
	// 	{
	// 		stash[i] = 0;
	// 		j = 0;
	// 		break;
	// 	}
	// 	stash[i] = 0;
	// }
	// if (!j)
	// {
	// 	while (stash[i])
	// 	{
	// 		stash[j++] = stash[i];
	// 		stash[i++] = 0;
	// 	}
	// }
	return (j != -1);
}