/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:08:51 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/24 17:16:42 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move_spill_fill(int y, int x, t_map *map)
{
	char	element;

	element = map->copy[y][x];
	if (element == COLLECTIBLE)
	{
		map->c_check--;
		map->copy[y][x] = WALL;
	}
	else if (element == EXIT)
	{
		map->e_check--;
		map->copy[y][x] = WALL;
	}
	else if (element == PLAYER || element == FLOOR)
		map->copy[y][x] = WALL;
	else
		return ;
	move_spill_fill(y + 1, x, map);
	move_spill_fill(y - 1, x, map);
	move_spill_fill(y, x + 1, map);
	move_spill_fill(y, x - 1, map);
}

void	validate_path(t_map *map)
{
	map->c_check = map->c;
	map->e_check = map->e;
	locate_player(map);
	move_spill_fill(map->player.y, map->player.x, map);
	if (map->c_check != 0 || map->e_check >= map->e)
	{
		write(2, "\033[1;31m🛑ERROR: ", 19);
		write(2, "no valid path found\n\033[0m", 25);
		ft_free_array(map->array, map->y);
		ft_free_array(map->copy, map->y);
		exit(EXIT_FAILURE);
	}
}
