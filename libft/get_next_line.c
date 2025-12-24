/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:06:05 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/24 17:06:18 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_fill_stash(int fd, char **stash)
{
	char	*buf;
	char	*tmp;
	ssize_t	br;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(*stash), *stash = NULL, NULL);
	br = 1;
	while (!ft_strchr_gnl(*stash, '\n') && br > 0)
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br <= 0)
			break ;
		buf[br] = '\0';
		tmp = ft_strjoin_gnl(*stash, buf);
		free(*stash);
		*stash = tmp;
	}
	free(buf);
	if (br < 0 || !*stash)
		return (free(*stash), *stash = NULL, NULL);
	return (*stash);
}

static char	*ft_get_line(const char *stash)
{
	size_t	len;
	size_t	i;
	char	*line;

	len = 0;
	i = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

static void	ft_update_stash(char **stash, size_t len)
{
	char	*rest;

	if ((*stash)[len])
	{
		rest = ft_strdup_gnl(*stash + len);
		free(*stash);
		*stash = rest;
	}
	else
	{
		free(*stash);
		*stash = NULL;
	}
}

static char	*ft_readline(int fd, char **stash)
{
	char	*line;

	if (!*stash || !ft_strchr_gnl(*stash, '\n'))
	{
		if (!ft_fill_stash(fd, stash))
			return (NULL);
	}
	if (!*stash || !**stash)
		return (free(*stash), *stash = NULL, NULL);
	line = ft_get_line(*stash);
	if (!line)
		return (free(*stash), *stash = NULL, NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	line = ft_readline(fd, &stash);
	if (!line)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	ft_update_stash(&stash, len);
	return (line);
}
