/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:02:00 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/04 16:15:57 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char 	*get_next_line(int fd)
{
	static char *stash;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
}

int main()
{
	get_next_line(1);
}