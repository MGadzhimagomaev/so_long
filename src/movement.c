/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:08:51 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/25 14:41:38 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	handle_input(t_map *map, int x, int y, int key)
{
	if (key == KEY_UP)
		y -= 1;
	if (key == KEY_DOWN)
		y += 1;
	if (key == KEY_LEFT)
		x -= 1;
	if (key == KEY_RIGHT)
		x += 1;
	if (map->array[y][x] == EXIT && map->c == 0)
		return (ft_win(map));
	if (map->array[y][x] == COLLECTIBLE)
	{
		map->array[y][x] = FLOOR;
		map->c--;
	}
}

void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y > 0 && map->array[y - 1][x] != WALL)
	{
		handle_input(map, x, y, KEY_UP);
		if (map->array[y - 1][x] == EXIT && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_SIZE, y * IMG_SIZE);
		map->array[y][x] = FLOOR;
		y--;
		print_movements(map);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_SIZE, y * IMG_SIZE);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.move_up1,
			x * IMG_SIZE, y * IMG_SIZE);
		map->array[y][x] = PLAYER;
		map->player.x = x;
	}
}

void	move_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x > 0 && map->array[y][x - 1] != WALL)
	{
		handle_input(map, x, y, KEY_LEFT);
		if (map->array[y][x - 1] == EXIT && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_SIZE, y * IMG_SIZE);
		map->array[y][x] = FLOOR;
		x--;
		print_movements(map);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_SIZE, y * IMG_SIZE);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.move_left1,
			x * IMG_SIZE, y * IMG_SIZE);
		map->array[y][x] = PLAYER;
		map->player.y = y;
	}
}

void	move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->y && map->array[y + 1][x] != WALL)
	{
		handle_input(map, x, y, KEY_DOWN);
		if (map->array[y + 1][x] == EXIT && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_SIZE, y * IMG_SIZE);
		map->array[y][x] = FLOOR;
		y++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_SIZE, y * IMG_SIZE);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.move_down1,
			x * IMG_SIZE, y * IMG_SIZE);
		map->array[y][x] = PLAYER;
		print_movements(map);
		map->player.y = y;
	}
}

void	move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x && map->array[y][x + 1] != WALL)
	{
		handle_input(map, x, y, KEY_RIGHT);
		if (map->array[y][x + 1] == EXIT && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_SIZE, y * IMG_SIZE);
		map->array[y][x] = FLOOR;
		x++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_SIZE, y * IMG_SIZE);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.move_right1,
			x * IMG_SIZE, y * IMG_SIZE);
		map->array[y][x] = PLAYER;
		print_movements(map);
	}
	map->player.x = x;
}
