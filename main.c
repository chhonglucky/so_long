/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:50:54 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 02:36:35 by hongchanhye      ###   ########.fr       */
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
void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
int		close_game(t_game *game);
int		is_ber_file(const char *argv);
void	check_map_basic(char *filename);
int		check_map_dfs(t_game *game);
void	read_map(t_game *game, char *filename);
char	**ft_split_size(char *str, int col, int row)
char	*ft_strdup_without_newline(char *str);
char	*ft_strjoin_without_newline(char *str1, char *str2);
void	init_img(t_game *game);
void	init_flag(t_game *game);
void	setting_img(t_game *game);
void	setting_img_item(t_game *game);
void	check_end(t_game *game);
void	char_xy_init(t_game *game, int row, int col);

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		unix_error("Input format : ./so_long [MAP_FILE.ber]\n");
	check_map_basic(argv[1]);
	game.img = (t_img *)shell_malloc(sizeof(t_img));
	game.map = (t_map *)shell_malloc(sizeof(t_map));
	game.char_xy = (t_char_xy *)shell_malloc(sizeof(t_char_xy));
	game.flag = (t_flag *)shell_malloc(sizeof(t_flag));
	read_map(&game, argv[1]);
	check_map_dfs(&game);
	init_img(&game);
	init_flag(&game);
	setting_img(&game);
	mlx_hook(game.win_ptr, X_EVENT_EXIT, 0, close_game, &game);
	mlx_key_hook(game.win_ptr, &key_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == W)
		move_w(game);
	else if (keycode == S)
		move_s(game);
	else if (keycode == A)
		move_a(game);
	else if (keycode == D)
		move_d(game);
	else if (keycode == ESC)
		close_game(game);
	printf("character movement : %d\n", game->char_xy->distance);
	setting_img(game);
	return (keycode);
}

void	move(t_game *game, int x, int y)
{
	game->char_xy->x += x;
	game->char_xy->y += y;
	game->char_xy->distance += ft_abs(x) + ft_abs(y);
}

void	move_w(t_game *game)
{
	int	temp_x;
	int	temp_y;

	temp_x = game->char_xy->x + 0;
	temp_y = game->char_xy->y - 1;
	game->img->player = game->img->player_N;
	if (game->map->data2[temp_y][temp_x] == '1')
		move(game, 0, 0);
	else
	{
		if (game->map->data2[temp_y][temp_x] == 'C')
		{
			game->char_xy->char_coin++;
			printf("game->char_xy->char_coin : %d\n", game->char_xy->char_coin);
			game->map->data2[temp_y][temp_x] = 0;
		}
		move(game, 0, -1);
	}
}

void	move_a(t_game *game)
{
	int	temp_x;
	int	temp_y;

	temp_x = game->char_xy->x - 1;
	temp_y = game->char_xy->y + 0;
	game->img->player = game->img->player_W;
	if (game->map->data2[temp_y][temp_x] == '1')
		move(game, 0, 0);
	else
	{
		if (game->map->data2[temp_y][temp_x] == 'C')
		{
			game->char_xy->char_coin++;
			printf("game->char_xy->char_coin : %d\n", game->char_xy->char_coin);
			game->map->data2[temp_y][temp_x] = 0;
		}
		move(game, -1, 0);
	}
}

void	move_s(t_game *game)
{
	int	temp_x;
	int	temp_y;

	temp_x = game->char_xy->x + 0;
	temp_y = game->char_xy->y + 1;
	game->img->player = game->img->player_S;
	if (game->map->data2[temp_y][temp_x] == '1')
		move(game, 0, 0);
	else
	{
		if (game->map->data2[temp_y][temp_x] == 'C')
		{
			game->char_xy->char_coin++;
			printf("game->char_xy->char_coin : %d\n", game->char_xy->char_coin);
			game->map->data2[temp_y][temp_x] = 0;
		}
		move(game, 0, 1);
	}
}

void	move_d(t_game *game)
{
	int	temp_x;
	int	temp_y;

	temp_x = game->char_xy->x + 1;
	temp_y = game->char_xy->y + 0;
	game->img->player = game->img->player_E;
	if (game->map->data2[temp_y][temp_x] == '1')
		move(game, 0, 0);
	else
	{
		if (game->map->data2[temp_y][temp_x] == 'C')
		{
			game->char_xy->char_coin++;
			printf("game->char_xy->char_coin : %d\n", game->char_xy->char_coin);
			game->map->data2[temp_y][temp_x] = 0;
		}
		move(game, 1, 0);
	}
}

int	close_game(t_game *game)
{
	// free_game(game);
	exit(0);
}

int	is_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(argv, '.');
	if (string)
		return (ft_strcmp(string, ".ber") == 0);
	return (0);
}

void	check_map_basic(char *filename)
{
}

int dfs(int x, int y, char **map, char c)
{
	int	count;

	if (map[y][x] == '1')
		return (0);
	if (map[y][x] != 'V')
	{
		if (map[y][x] == c)
		{
			map[y][x] = 'V';
			return (1);
		}
		map[y][x] = 'V';
		count = 0;
		count += dfs(x - 1, y, map, c);
		count += dfs(x, y + 1, map, c);
		count += dfs(x + 1, y, map, c);
		count += dfs(x, y - 1, map, c);
		return (count);
	}
	return (0);
}

int	check_map_dfs(t_game *game)
{
	int		c_access;
	int		e_access;
	char	**map_temp_c;
	char	**map_temp_e;

	c_access = dfs(game->char_xy->x, game->char_xy->y, map_temp_c, 'C');
	e_access = dfs(game->char_xy->x, game->char_xy->y, map_temp_e, 'E');
	if (c_access != game->map->coin_cnt)
		return (false);
	if (e_access != 1)
		return (false);
	return (true);
}

void	read_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;

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
			game->map->data = ft_strjoin_without_newline(game->map->data, line);
	}
	game->map->coin_cnt = ft_count(game->map->data, 'C');
	game->map->player_cnt = ft_count(game->map->data, 'P');
	game->map->data2 = ft_split_size(game->map->data, game->map->col, game->map->row);
	close(fd);
}

char	**ft_split_size(char *str, int col, int row)
{
	int		i;
	int		x;
	int		y;
	char	**return_str;

	i = 0;
	x = 0;
	y = 0;
	return_str = (char **)shell_malloc((col + 1) * sizeof(char *));
	while (i < ft_strlen(str))
	{
		
	}
		
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
	game->img->ball = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/ball.xpm", &img_width, &img_height);
	game->img->ladder = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/ladder.xpm", &img_width, &img_height);
	game->img->player_E = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player_E.xpm", &img_width, &img_height);
	game->img->player_N = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player_N.xpm", &img_width, &img_height);
	game->img->player_S = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player_S.xpm", &img_width, &img_height);
	game->img->player_W = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player_W.xpm", &img_width, &img_height);
	game->img->player = game->img->player_S;
	game->img->tile0 = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/tile00.xpm", &img_width, &img_height);
	game->img->tile1 = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/tile01.xpm", &img_width, &img_height);
}

void	init_flag(t_game *game)
{
	game->flag->collect_all_coin = false;
	game->flag->game_start = true;
}

// void	setting_img(t_game *game)
// {
// 	int		col;
// 	int		row;
// 	col = 0;
// 	while (col < game->map->col)
// 	{
// 		row = 0;
// 		while (row < game->map->row)
// 		{
// 			if (game->map->data2[col][row] == '1')
// 			{
// 				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile1, row * 64, col * 64);
// 			}
// 			else if (game->map->data2[col][row] == 'C')
// 			{
// 				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile0, row * 64, col * 64);
// 				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->ball, row * 64, col * 64);
// 			}
// 			else if (game->map->data2[col][row] == 'P')
// 			{
// 				if (game->flag->game_start == true)
// 					char_xy_init(game, row, col);
// 				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile0, row * 64, col * 64);
// 				// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->player_S, game->char_xy->x * 64, (game->char_xy->y - 1) * 64);
// 			}
// 			else if (game->map->data2[col][row] == 'E')
// 			{
// 				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile0, row * 64, col * 64);
// 				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->ladder, row * 64, col * 64);
// 			}
// 			else
// 			{
// 				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile0, row * 64, col * 64);
// 			}
// 			row++;
// 		}
// 		col++;
// 	}
// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->player, game->char_xy->x * 64, (game->char_xy->y - 1) * 64);
// 	check_end(game);
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
			if (game->map->data2[col][row] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile1, row * 64, col * 64);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile0, row * 64, col * 64);
			row++;
		}
		col++;
	}
	setting_img_item(game);
}

void	setting_img_item(t_game *game)
{
	int	row;
	int	col;

	col = 0;
	while (col < game->map->col)
	{
		row = 0;
		while (row < game->map->row)
		{
			if (game->map->data2[col][row] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->ball, row * 64, col * 64);
			else if (game->map->data2[col][row] == 'P')
			{
				if (game->flag->game_start == true)
					char_xy_init(game, row, col);
			}
			else if (game->map->data2[col][row] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->ladder, row * 64, col * 64);
			row++;
		}
		col++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->player, game->char_xy->x * 64, (game->char_xy->y - 1) * 64);
	check_end(game);
}

void	check_end(t_game *game)
{
	int	char_x;
	int	char_y;

	char_x = game->char_xy->x;
	char_y = game->char_xy->y;
	if (game->map->data2[char_y][char_x] == 'E' && (game->map->coin_cnt == game->char_xy->char_coin))
	{
		printf("game clear!\n");
		close_game(game);
	}
}

void	char_xy_init(t_game *game, int row, int col)
{
	game->char_xy->x = row;
	game->char_xy->y = col;
	game->char_xy->distance = 0;
	game->char_xy->char_coin = 0;
	game->flag->game_start = false;
}
