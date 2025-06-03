/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:36:36 by tpirinen          #+#    #+#             */
/*   Updated: 2025/06/01 22:05:34 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(int fd, char *stat_buffer, char *line);
static char	*clean_line(char **stat_buffer);
static char	*get_left_overs(char **stat_buffer);

char	*get_next_line(int fd)
{
	static char		*stat_buffer;
	char			*line;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stat_buffer = get_line(fd, stat_buffer, buffer);
	free(buffer);
	if (!stat_buffer || !*stat_buffer)
		return (NULL);
	line = clean_line(&stat_buffer);
	buffer = get_left_overs(&stat_buffer);
	if (!stat_buffer || !line)
		return (NULL);
	free(stat_buffer);
	stat_buffer = buffer;
	return (line);
}

static char	*get_line(int fd, char *stat_buffer, char *buffer)
{
	ssize_t		bytes_read;
	char		*temp;

	bytes_read = 1;
	while (bytes_read > 0 && !(ft_strchr(stat_buffer, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!stat_buffer)
			stat_buffer = ft_strjoin("", "");
		temp = stat_buffer;
		stat_buffer = ft_strjoin(temp, buffer);
		free(temp);
		if (!stat_buffer)
			return (NULL);
	}
	return (stat_buffer);
}

static char	*clean_line(char **stat_buffer)
{
	char	*new_line;
	size_t	len;
	size_t	i;

	len = 0;
	while ((*stat_buffer)[len] && (*stat_buffer)[len] != '\n')
		len++;
	if ((*stat_buffer)[len] == '\n')
		len++;
	new_line = malloc(len + 1);
	if (!new_line)
	{
		free(*stat_buffer);
		*stat_buffer = NULL;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_line[i] = (*stat_buffer)[i];
		i++;
	}
	new_line[len] = '\0';
	return (new_line);
}

static char	*get_left_overs(char **stat_buffer)
{
	char	*left_overs;
	char	*newline;
	
	newline = ft_strchr(*stat_buffer, '\n');
	if (!newline)
		return (NULL);
	left_overs = ft_strjoin("", (newline + 1));
	if (!left_overs)
	{
		free(*stat_buffer);
		*stat_buffer = NULL;
		return (NULL);
	}
	return (left_overs);
}
