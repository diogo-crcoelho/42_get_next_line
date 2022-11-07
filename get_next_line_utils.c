/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:52:44 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/07 20:44:23 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

	i = -1;
	if (!src && !dest)
		return (NULL);
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

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((char *)&str[i]);
	if (str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (NULL);
}
