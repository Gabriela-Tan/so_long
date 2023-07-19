/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:14:08 by gabriela          #+#    #+#             */
/*   Updated: 2023/07/18 15:05:51 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_extract(char *s)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	if (ft_strlen_(s) - i == 0)
	{
		free(s);
		return (NULL);
	}
	line = (char *)ft_calloc((ft_strlen_(s) - i + 1),
			sizeof(char));
	if (line == NULL)
		return (NULL);
	while (s[i])
		line[j++] = s[i++];
	line[j] = '\0';
	free(s);
	return (line);
}

char	*ft_remainder(char *s)
{
	size_t	i;
	size_t	j;
	char	*line;

	j = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = (char *)ft_calloc(sizeof(char), (i + 1));
	while (j < i)
	{
		line[j] = s[j];
		j++;
	}
	line[j] = '\0';
	free(s);
	return (line);
}

void	ft_norm(int bytes, char **rd, char **s, char **buf)
{
	(*rd)[bytes] = '\0';
	*s = ft_strjoin(*s, *rd);
	if (buf != NULL)
	{
		free(*buf);
		*buf = ft_strdup("");
	}
	*buf = ft_strjoin(*buf, *rd);
}

char	*ft_reading(char **buf, int fd)
{
	int		bytes;
	char	*s;
	char	*rd;

	s = ft_strdup("");
	s = ft_strjoin(s, *buf);
	rd = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (rd == NULL)
		return (NULL);
	while (ft_strchr(*buf, '\n') == NULL)
	{
		bytes = read(fd, rd, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(rd);
			if (ft_strlen_(s) != 0)
				return (ft_remainder(s));
			free (s);
			return (NULL);
		}
		ft_norm(bytes, &rd, &s, buf);
	}
	free(rd);
	return (ft_remainder(s));
}

char	*get_next_line(int fd)
{
	static char	*buf[2048];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf[fd] == NULL)
		buf[fd] = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	line = ft_reading(&buf[fd], fd);
	buf[fd] = ft_extract(buf[fd]);
	return (line);
}
