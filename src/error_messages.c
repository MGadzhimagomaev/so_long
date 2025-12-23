#include "../include/so_long.h"

void	error_open_file(void)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "failed to open\n\033[0m", 20);
	exit(EXIT_FAILURE);
}

void	error_filename(void)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "filename should be .ber\n\033[0m", 29);
	exit(EXIT_FAILURE);
}

void	error_wall(t_map *map)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "failed wall\n\033[0m", 17);
	ft_free_array(map->array, map->y);
	ft_free_array(map->copy, map->y);
	exit(EXIT_FAILURE);
}

void	error_size(t_map *map)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "wrong size\n\033[0m", 16);
	ft_free_array(map->array, map->y);
	ft_free_array(map->copy, map->y);
	exit(EXIT_FAILURE);
}

void	error_map_elements(t_map *map)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "failed elements\n\033[0m", 21);
	ft_free_array(map->array, map->y);
	ft_free_array(map->copy, map->y);
	exit(EXIT_FAILURE);
}