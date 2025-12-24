/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:08:51 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/24 17:16:31 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	map_type(t_map *map, int x, int y)
{
	int	type;

	type = map->array[y / IMG_SIZE][x / IMG_SIZE];
	if (type == COLLECTIBLE || type == PLAYER || type == EXIT || type == FLOOR)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x, y);
	if (type == COLLECTIBLE)
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.collectible, x, y);
	else if (type == PLAYER)
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.move_down1, x + 8, y);
	else if (type == EXIT)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.exit, x, y);
	else if (type == WALL)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall, x, y);
}

void	map_printer(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			map_type(map, x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		x = 0;
		y++;
	}
}

void	print_movements(t_map *map)
{
	char	*move;

	move = ft_itoa(map->moves);
	write(1, "\r", 1);
	write(1, "\x1b[33;01m", 9);
	write(1, move, ft_strlen(move));
	write(1, "\x1b[0m", 5);
	write(1, " movements", 11);
	free(move);
}
