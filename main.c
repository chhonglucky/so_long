/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:50:54 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 18:43:14 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "./includes/so_long.h"
#include "./Libft/ft_printf.h"
#include "./Libft/libft.h"
#include "./Libft/get_next_line.h"
#include "csfunc.h"
#include <stdbool.h>

void	init_struct(t_game *game);
int		key_hook(int keycode, t_game *game);
void	move(t_game *game, int x, int y);
void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
int		close_game(t_game *game);
void	free_map_struct(t_map *map);
void	free_img_struct(void *mlx_ptr, t_img *img);
void	free_double_array(char **temp_map);
int		is_ber_file(const char *argv);
void	check_map_basic(t_game *game, char *filename);
int		check_component(char *str);
int		is_rectangle(t_map *map);
int		is_surronded(t_map *map);
int 	dfs(int x, int y, char **map, char c);
int		check_map_dfs(t_game *game);
void	read_map(t_game *game, char *filename);
char	**ft_split_size(char *str, int col, int row);
char	*ft_strdup_without_newline(char *str);
char	*ft_strjoin_without_newline(char *str1, char *str2);
void	init_img(t_game *game);
void	setting_img(t_game *game);
void	setting_img_item(t_game *game);
void	check_end(t_game *game);
void	char_xy_init(t_game *game);

void	f()
{
	system("leaks a.out");
}

int	main(int argc, char *argv[])
{
	atexit(f);
	t_game	game;

	if (argc != 2)
		unix_error("Input format : ./so_long [MAP_FILE.ber]\n");
	game.img = (t_img *)shell_malloc(sizeof(t_img));
	game.map = (t_map *)shell_malloc(sizeof(t_map));
	game.char_xy = (t_char_xy *)shell_malloc(sizeof(t_char_xy));
	init_struct(&game);
	read_map(&game, argv[1]);
	check_map_basic(&game, argv[1]);
	char_xy_init(&game);
	if (check_map_dfs(&game) == false)
		close_game(&game);
	init_img(&game);
	setting_img(&game);
	mlx_hook(game.win_ptr, X_EVENT_EXIT, 0, close_game, &game);
	mlx_key_hook(game.win_ptr, &key_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (1);
}

void	init_struct(t_game *game)
{
	game->mlx_ptr = 0;
	game->win_ptr = 0;
	game->img->ball = 0;
	game->img->ladder = 0;
	game->img->player = 0;
	game->img->player_E = 0;
	game->img->player_S = 0;
	game->img->player_N = 0;
	game->img->player_W = 0;
	game->img->tile0 = 0;
	game->img->tile1 = 0;
	game->map->data2 = 0;
	game->map->data = 0;
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
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		ft_printf("character movement : %d\n", game->char_xy->distance);
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
			game->map->data2[temp_y][temp_x] = 0;
		}
		move(game, 1, 0);
	}
}

int	close_game(t_game *game)
{
	if (game->char_xy != 0)
		free(game->char_xy);
	if (game->map != 0)
		free_map_struct(game->map);
	if (game->mlx_ptr != 0)
	{
		if (game->img != 0)
			free_img_struct(game->mlx_ptr, game->img);
		if (game->win_ptr != 0)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	exit(0);
}

void	free_map_struct(t_map *map)
{
	free_double_array(map->data2);
	free(map->data);
	free(map);
}

void	free_img_struct(void *mlx_ptr, t_img *img)
{
	if (img->ball == 0)
		mlx_destroy_image(mlx_ptr, img->ball);
	if (img->ladder == 0)
		mlx_destroy_image(mlx_ptr, img->ladder);
	if (img->player == 0)
		mlx_destroy_image(mlx_ptr, img->player);
	if (img->player_E == 0)
		mlx_destroy_image(mlx_ptr, img->player_E);
	if (img->player_N == 0)
		mlx_destroy_image(mlx_ptr, img->player_N);
	if (img->player_S == 0)
		mlx_destroy_image(mlx_ptr, img->player_S);
	if (img->player_W == 0)
		mlx_destroy_image(mlx_ptr, img->player_W);
	if (img->tile0 == 0)
		mlx_destroy_image(mlx_ptr, img->tile0);
	if (img->tile1 == 0)
		mlx_destroy_image(mlx_ptr, img->tile1);
	free(img);
}

int	is_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(argv, '.');
	if (string)
		return (ft_strcmp(string, ".ber") == 0);
	return (0);
}

void	check_map_basic(t_game *game, char *filename)
{
	if (is_ber_file(filename) == 0)
		unix_error("Is not .ber file");
	if (check_component(game->map->data) == false)
		unix_error("Component error");
	game->map->coin_cnt = ft_count(game->map->data, 'C');
	game->map->player_cnt = ft_count(game->map->data, 'P');
	game->map->exit_cnt = ft_count(game->map->data, 'E');
	if (game->map->coin_cnt < 1)
		unix_error("No coins");
	if (game->map->exit_cnt != 1)
		unix_error("One Exit is needed");
	if (game->map->player_cnt != 1)
		unix_error("One Player is needed");
	if (is_rectangle(game->map) == false)
		unix_error("Map must be rectangular");
	if (is_surronded(game->map) == false)
		unix_error("Map must be surronded by wall");
}

int	check_component(char *str)
{
	int	i;
	int	component_cnt;

	i = 0;
	component_cnt = 0;
	while(str[i])
	{
		if (str[i] == 'P' || str[i] == 'E' || str[i] == 'C'
				|| str[i] == '1' || str[i] == '0')
			component_cnt++;
		i++;
	}
	if (i != component_cnt)
		return (false);
	return (true);
}

int	is_rectangle(t_map *map)
{
	if (map->row * map->col != ft_strlen(map->data))
		return (false);
	return (true);
}

int	is_surronded(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map->row)
	{
		if (map->data2[0][x] != '1')
			return (false);
		if (map->data2[map->col - 1][x] != '1')
			return (false);
		x++;
	}
	while (y < map->col)
	{
		if (map->data2[y][0] != '1')
			return (false);
		if (map->data2[y][map->row - 1] != '1')
			return (false);
		y++;
	}
	return (true);
}

int dfs(int x, int y, char **map, char c)
{
	int	count;

	count = 0;
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] != 'V')
	{
		if (map[y][x] == c)
		{
			map[y][x] = 'V';
			count++;
		}
		map[y][x] = 'V';
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
	
	map_temp_c = ft_split_size(game->map->data, game->map->col, game->map->row);
	map_temp_e = ft_split_size(game->map->data, game->map->col, game->map->row);
	c_access = dfs(game->char_xy->x, game->char_xy->y, map_temp_c, 'C');
	e_access = dfs(game->char_xy->x, game->char_xy->y, map_temp_e, 'E');
	free_double_array(map_temp_c);
	free_double_array(map_temp_e);
	if (c_access != game->map->coin_cnt)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("map error : unaccesible coin present\n", 2);
		return (false);
	}
	if (e_access != 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("map error : unaccesible exit present\n", 2);
		return (false);
	}
	return (true);
}

void	free_double_array(char **temp_map)
{
	int	i;

	i = 0;
	while (temp_map[i])
	{
		free(temp_map[i]);
		i++;
	}
	free(temp_map);
}

void	read_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = shell_open(filename, O_RDONLY, 0777);
	line = get_next_line(fd);
	game->map->col = 0;
	game->map->row = ft_strlen(line) - 1;
	game->map->data = ft_strdup_without_newline(line);;
	while (line)
	{
		free(line);
		game->map->col++;
		line = get_next_line(fd);
		if (line)
		{
			temp = ft_strjoin_without_newline(game->map->data, line);
			free(game->map->data);
			game->map->data = temp;
		}
	}
	game->map->data2 = ft_split_size(game->map->data, game->map->col, game->map->row);
	close(fd);
}

char	**ft_split_size(char *str, int col, int row)
{
	int		x;
	int		y;
	char	**return_str;

	y = 0;
	return_str = (char **)shell_malloc((col + 1) * sizeof(char *));
	while (y < col)
	{
		x = 0;
		return_str[y] = (char *)shell_malloc(row + 1);
		while (x < row)
		{
			return_str[y][x] = str[y * row + x];
			x++;
		}
		if (x == row)
			return_str[y][x] = '\0';
		y++;
	}
	return_str[y] = 0;
	return (return_str);
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
	game->win_ptr = mlx_new_window(game->mlx_ptr, 63 * game->map->row, 63 * game->map->col, "so_long_chanhhon");
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
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile1, row * 63, col * 63);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile0, row * 63, col * 63);
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
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->ball, row * 63, col * 63);
			else if (game->map->data2[col][row] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->ladder, row * 63, col * 63);
			row++;
		}
		col++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->player, game->char_xy->x * 63, (game->char_xy->y - 1) * 63);
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
		ft_printf("game clear!\n");
		close_game(game);
	}
}

void	char_xy_init(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->col)
	{
		x = 0;
		while (x < game->map->row)
		{
			if (game->map->data[y * game->map->row + x] == 'P')
			{
				game->char_xy->x = x;
				game->char_xy->y = y;
				game->char_xy->distance = 0;
				game->char_xy->char_coin = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}
