/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:12:52 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/25 15:26:26 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>

# define IMG_SIZE			50
# define WND_NAME			"so_long"

# define KEY_UP				65362
# define KEY_DOWN			65364
# define KEY_LEFT			65361
# define KEY_RIGHT			65363

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_Q				113
# define KEY_ESC			65307

typedef enum e_tile
{
	WALL		= '1',
	FLOOR		= '0',
	COLLECTIBLE	= 'C',
	PLAYER		= 'P',
	EXIT		= 'E',
}	t_tile;

typedef struct s_player
{
	int	y;
	int	x;
}	t_player;

typedef struct s_img
{
	void	*empty;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*move_up1;
	void	*move_up2;
	void	*move_down1;
	void	*move_down2;
	void	*move_left1;
	void	*move_left2;
	void	*move_right1;
	void	*move_right2;
}	t_img;

typedef struct s_map
{
	int			fd;
	char		*line;
	char		*file;
	char		**array;
	char		**copy;
	char		*file_name;
	int			y;
	int			x;
	int			e;
	int			c;
	int			c_check;
	int			e_check;
	int			p;
	int			exit;
	int			moves;
	void		*mlx;
	void		*wnd;
	t_img		img;
	t_player	player;
}	t_map;

void	error_filename(void);
void	error_wall(t_map *map);
void	error_open_file(void);
void	error_size(t_map *map);
void	error_map_elements(t_map *map);

void	initialize_map(t_map *map, char **argv);
void	file_to_image(t_map *map);
void	file_to_image_player(t_map *map);
void	generate_map_array(t_map *map);
void	ft_exit_free(t_map *map);
int		ft_free_array(char **ret, int i);
void	validate_path(t_map *map);
void	validate_map(t_map *map);
void	locate_player(t_map *map);
void	map_printer(t_map *map);
void	print_movements(t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);
int		key_hook(int key, t_map *map);
int		ft_close(t_map *map);
void	ft_win(t_map *map);

#endif