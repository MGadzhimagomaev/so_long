#include "../include/so_long.h"

void    generate_map_array(t_map *map)
{
    int fd;

	map->y = 0;
	map->line = "";
	map->file = NULL;
    fd = open(map->file_name, O_RDONLY);
    if (fd == -1)
        error_open_file();
    while (map->line)
    {
        map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
        map->file = ft_strjoin_free(map->file, map->line);
        free(map->line);
        if(!map->file)
            ft_exit_free(map);
        map->y++;
    }
    close(fd);
    map->array = ft_split(map->file, '\n');
    map->copy = ft_split(map->file, '\n');
    if(!map->array || !map->copy)
        ft_exit_free(map);
    free(map->file);
}

void    initialize_map(t_map *map, char **argv)
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