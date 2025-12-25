/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:08:51 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/25 12:39:18 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	validate_file_name(t_map *map)
{
	size_t	len;

	len = ft_strlen(map->file_name);
	if (len <= 4 || ft_strncmp(map->file_name + (len - 4), ".ber", 4) != 0)
		error_filename();
}

static void	validate_size(t_map *map)
{
	int	y;
	int	x;
	int	first_row_len;

	y = 0;
	x = 0;
	first_row_len = ft_strlen(map->array[0]);
	while (y < map->y)
	{
		x = ft_strlen(map->array[y]);
		if (first_row_len != x)
			error_size(map);
		y++;
	}
	map->x = first_row_len;
}

static void	validate_wall(t_map *map)
{
	int	y;
	int	x;

	x = 0;
	while (map->array[0][x] == WALL && map->array[1][x])
		x++;
	if (map->array[0][x] != '\0')
		error_wall(map);
	y = 1;
	while (y < map->y)
	{
		if (map->array[y][0] != WALL ||
				map->array[y][map->x - 1] != WALL)
			error_wall(map);
		y++;
	}
	x = 0;
	while (map->array[map->y - 1][x] == WALL)
		x++;
	if (map->array[map->y - 1][x] != '\0')
		error_wall(map);
}

static void	validate_params(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->array[y][x] == COLLECTIBLE)
				map->c++;
			else if (map->array[y][x] == PLAYER)
				map->p++;
			else if (map->array[y][x] == EXIT)
				map->e++;
			else if (map->array[y][x] != FLOOR && map->array[y][x] != WALL)
				error_map_elements(map);
			x++;
		}
		y++;
	}
	if (map->c < 1 || map->p != 1 || map->e != 1)
		error_map_elements(map);
}

void	validate_map(t_map *map)
{
	validate_file_name(map);
	generate_map_array(map);
	validate_size(map);
	validate_wall(map);
	validate_params(map);
	validate_path(map);
	ft_free_array(map->copy, map->y);
}
