/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:52:44 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 02:02:37 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	
	ret = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (str1[++i])
		ret[i] = str1[i];
	j = -1;
	while (str2[++j])
		ret[i++] = str2[j];
	ret[i] = 0;
	return (ret);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (NULL);
	i = -1;
	while (++i < n)
		((unsigned char *) dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*ret;

	size = ft_strlen(str) + 1;
	ret = (char *)malloc(size);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, str, size);
	return (ret);
}