/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:00:16 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/04 12:19:23 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

