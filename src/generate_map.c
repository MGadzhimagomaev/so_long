/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:08:51 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/25 15:09:37 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*read_file_to_str(t_map *map, int fd)
{
	char	*file;
	char	*line;
	char	*tmp;

	file = NULL;
	map->y = 0;
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin_free(file, line);
		free(line);
		if (!tmp)
			ft_exit_free(map);
		file = tmp;
		line = get_next_line(fd);
		map->y++;
	}
	return (file);
}

void	generate_map_array(t_map *map)
{
	int	fd;

	fd = open(map->file_name, O_RDONLY);
	if (fd == -1)
		error_open_file();
	map->file = read_file_to_str(map, fd);
	close(fd);
	map->array = ft_split(map->file, '\n');
	map->copy = ft_split(map->file, '\n');
	if (!map->array || !map->copy)
		ft_exit_free(map);
	free(map->file);
}

void	initialize_map(t_map *map, char **argv)
{
	map->file_name = argv[1];
	map->moves = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->y = 0;
	map->player.y = 0;
	map->player.x = 0;
	map->exit = 0;
}
