/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:36:56 by tpirinen          #+#    #+#             */
/*   Updated: 2025/06/07 20:41:36 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	Calculates  the  length of the string pointed to by 's', excluding the
	terminating null byte ('\0').											*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*	Allocates memory (using malloc(3)) and returns a new string, which is
	the result of concatenating ’s1’ and ’s2’.								*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*iter;

	if (!s1 || !s2)
		return (NULL);
	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (NULL);
	iter = newstr;
	while (*s1)
		*iter++ = *s1++;
	while (*s2)
		*iter++ = *s2++;
	*iter = '\0';
	return (newstr);
}

/*	Returns a pointer to the first occurrence of the character 'c' in the
	string 's'.																*/
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/*	Copies up to size - 1 characters from the NUL-terminated string 'src'
	to 'dst', NUL-terminating the result.									*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;

	length = 0;
	while (src[length])
	{
		if (length + 1 < size)
			*dst++ = src[length];
		length++;
	}
	if (size > 0)
		*dst = '\0';
	return (length);
}
