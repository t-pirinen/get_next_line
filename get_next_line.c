/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:36:36 by tpirinen          #+#    #+#             */
/*   Updated: 2025/05/06 18:52:56 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer;
	char	*line;
	ssize_t	bytes_read;
	size_t	i;
	
	line = malloc(1024);
	i = 0;
	while ((bytes_read = read(fd, &buffer, 1)) > 0)
	{
		if (buffer == '\n')
			break ;
		line[i++] = buffer;
	}
	if (bytes_read == 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// char	*get_next_line(int fd)
// {
// 	char	*line;
// 	char	buffer;
// 	ssize_t	bytes_read;
// 	size_t	i;
	
// 	line = malloc(1024);
// 	i = 0;
// 	while ((bytes_read = read(fd, &buffer, 1)) > 0)
// 	{
// 		if (buffer == '\n')
// 			break ;
// 		line[i++] = buffer;
// 	}
// 	if (bytes_read == 0 && i == 0)
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	return (line);
// }
