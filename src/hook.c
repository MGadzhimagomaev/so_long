/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:08:51 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/24 17:20:47 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	locate_player(t_map *map)
{
	map->player.y = 0;
	map->player.x = 0;
	while (map->player.y < map->y)
	{
		while (map->player.x < map->x)
		{
			if (map->array[map->player.y][map->player.x] == PLAYER)
				break ;
			map->player.x++;
		}
		if (map->array[map->player.y][map->player.x] == PLAYER)
			break ;
		map->player.x = 0;
		map->player.y++;
	}
}

int	key_hook(int key, t_map *map)
{
	locate_player(map);
	if (key == KEY_ESC || key == KEY_Q)
		return (ft_close(map));
	else if (map->exit == 1)
		return (0);
	else if (key == KEY_UP || key == KEY_W)
		move_up(map);
	else if (key == KEY_DOWN || key == KEY_S)
		move_down(map);
	else if (key == KEY_LEFT || key == KEY_A)
		move_left(map);
	else if (key == KEY_RIGHT || key == KEY_D)
		move_right(map);
	return (0);
}
