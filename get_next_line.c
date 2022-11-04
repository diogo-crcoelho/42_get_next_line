/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:02:00 by dcarvalh          #+#    #+#             */
/*   Updated: 2022/11/04 12:39:04 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char 	get_next_line(int fd)
{
	static char *stash;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
}

int main()
{
	get_next_line(1);
}