/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:08:51 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/25 15:26:31 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	file_to_image(t_map *map)
{
	int	a;

	a = IMG_SIZE;
	map->img.empty = mlx_xpm_file_to_image(map->mlx,
			"textures/floor.xpm", &a, &a);
	map->img.wall = mlx_xpm_file_to_image(map->mlx,
			"textures/wall.xpm", &a, &a);
	map->img.exit = mlx_xpm_file_to_image(map->mlx,
			"textures/door.xpm", &a, &a);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
			"textures/collectible.xpm", &a, &a);
	file_to_image_player(map);
}

void	file_to_image_player(t_map *map)
{
	int	a;

	a = IMG_SIZE;
	map->img.move_up1 = mlx_xpm_file_to_image(map->mlx,
			"textures/player/up-1.xpm", &a, &a);
	map->img.move_up2 = mlx_xpm_file_to_image(map->mlx,
			"textures/player/up-2.xpm", &a, &a);
	map->img.move_down1 = mlx_xpm_file_to_image(map->mlx,
			"textures/player/down-1.xpm", &a, &a);
	map->img.move_down2 = mlx_xpm_file_to_image(map->mlx,
			"textures/player/down-2.xpm", &a, &a);
	map->img.move_left1 = mlx_xpm_file_to_image(map->mlx,
			"textures/player/left-1.xpm", &a, &a);
	map->img.move_left2 = mlx_xpm_file_to_image(map->mlx,
			"textures/player/left-2.xpm", &a, &a);
	map->img.move_right1 = mlx_xpm_file_to_image(map->mlx,
			"textures/player/right-1.xpm", &a, &a);
	map->img.move_right2 = mlx_xpm_file_to_image(map->mlx,
			"textures/player/right-2.xpm", &a, &a);
}
