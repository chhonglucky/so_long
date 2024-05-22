/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:50:54 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/22 23:56:02 by hongchanhye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "./includes/so_long.h"
#include "./Libft/ft_printf.h"
#include "./Libft/libft.h"
#include "./Libft/get_next_line.h"
#include "csfunc.h"
#include <stdbool.h>


int		key_hook(int keycode, t_game *game);
void	move(t_game *game, int x, int y);
void	close_win(t_game *game);
// int		is_collision(t_game *game, int dir);
static	int	is_ber_file(const char *argv);
void	check_map(char *filename);
void	read_map(t_game *game, char *filename);
char	*ft_strdup_without_newline(char *str);
char	*ft_strjoin_without_newline(char *str1, char *str2);
void	init_img(t_game *game);
void	init_flag(t_game *game);
void	setting_img(t_game *game);
void	char_xy_init(t_game *game, int row, int col);

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		unix_error("Input format : ./so_long [MAP_FILE.ber]\n");
	game.img = (t_img *)shell_malloc(sizeof(t_img));
	game.map = (t_map *)shell_malloc(sizeof(t_map));
	game.char_xy = (t_char_xy *)shell_malloc(sizeof(t_char_xy));
	game.flag = (t_flag *)shell_malloc(sizeof(t_flag));
	// check_map(argv[1]);
	read_map(&game, argv[1]);
	init_img(&game);
	init_flag(&game);
	setting_img(&game);
	mlx_hook(game.win_ptr, X_EVENT_KEY_EXIT, 0, &key_hook, &game);
	mlx_key_hook(game.win_ptr, key_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == W)
		move(game, 0, -1);
	else if (keycode == S)
		move(game, 0, 1);
	else if (keycode == A)
		move(game, -1, 0);
	else if (keycode == D)
		move(game, 1, 0);
	else if (keycode == ESC)
		close_win(game);
	setting_img(game);
	return (keycode);
}

void	move(t_game *game, int x, int y)
{
	game->char_xy->x += x;
	game->char_xy->y += y;
}

void	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
}

// int	is_collision(t_game *game, int dir)
// {
// 	int		x;
// 	int		y;
// 	char	c;

// 	x = game->dir2coord[dir].x;
// 	y = game->dir2coord[dir].y;
// 	c = game->map->data[col * game->map->row + row];
// 	if (c == '1')
// 		return (true);
// 	else if (c == 'E' && !game->flag->collect_all_coin)
// 		return (true);
// 	return (false);
// }

static	int	is_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(argv, '.');
	if (string)
		return (ft_strcmp(string, ".ber") == 0);
	return (0);
}

void	check_map(char *filename)
{
	
}

void	read_map(t_game *game, char *filename)
{
	int  fd;
	char *line;

	fd = shell_open(filename, O_RDONLY, 0777);
	line = get_next_line(fd);
	game->map->col = 0;
	game->map->row = ft_strlen(line) - 1;
	game->map->data = ft_strdup_without_newline(line);
	free(line);
	while (line)
	{
		game->map->col++;
		line = get_next_line(fd);
		if (line)
		{
			game->map->data = ft_strjoin_without_newline(game->map->data, line);
		}
	}
	close(fd);
	printf("read_map input data : %s\n", game->map->data);
	printf("read_map row : %d, col : %d\n", game->map->row, game->map->col);
}

char	*ft_strdup_without_newline(char *str)
{
	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = '\0';
	return (ft_strdup(str));
}

char	*ft_strjoin_without_newline(char *str1, char *str2)
{
	if (str2[ft_strlen(str2) - 1] == '\n')
		str2[ft_strlen(str2) - 1] = '\0';
	return (ft_strjoin(str1, str2));
}

void	init_img(t_game *game)
{
	int	img_height;
	int	img_width;

	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 64 * game->map->row, 64 * game->map->col, "so_long_chanhhon");
	// game->win_ptr = mlx_new_window(game->mlx_ptr, 2000, 2000, "so_long_chanhhon");
	game->img->ball = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/ball.xpm", &img_width, &img_height);
	game->img->ladder = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/ladder.xpm", &img_width, &img_height);
	game->img->player_E = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player_E.xpm", &img_width, &img_height);
	game->img->player_N = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player_N.xpm", &img_width, &img_height);
	game->img->player_S = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player_S.xpm", &img_width, &img_height);
	game->img->player_W = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player_W.xpm", &img_width, &img_height);
	game->img->tile0 = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/tile00.xpm", &img_width, &img_height);
	game->img->tile1 = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/tile01.xpm", &img_width, &img_height);
}

void	init_flag(t_game *game)
{
	game->flag->collect_all_coin = false;
	game->flag->game_start = true;
}

// int		print_map(t_game *game)
// {
// 	int	row;
// 	int	col;

	
// }


void	setting_img(t_game *game)
{
	int		col;
	int		row;

	col = 0;
	while (col < game->map->col)
	{
		row = 0;
		while (row < game->map->row)
		{
			if (game->map->data[col * game->map->row + row] == '1')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile1, row * 64, col * 64);
			}
			else if (game->map->data[col * game->map->row + row] == 'C')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile0, row * 64, col * 64);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->ball, row * 64, col * 64);
			}
			else if (game->map->data[col * game->map->row + row] == 'P')
			{
				if (game->flag->game_start == true)
					char_xy_init(game, row, col);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile0, row * 64, col * 64);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->player_S, game->char_xy->x * 64, (game->char_xy->y - 1) * 64);
			}
			else if (game->map->data[col * game->map->row + row] == 'E')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile0, row * 64, col * 64);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->ladder, row * 64, col * 64);
			}
			else
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile0, row * 64, col * 64);
			}
			row++;
		}
		col++;
	}
}

void	char_xy_init(t_game *game, int row, int col)
{
	game->char_xy->x = row;
	game->char_xy->y = col;
	game->flag->game_start = false;
	
}
