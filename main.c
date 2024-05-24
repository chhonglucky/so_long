/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:50:54 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 19:18:31 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int argc, char *argv[])
{
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

void	check_end(t_game *game)
{
	int	char_x;
	int	char_y;

	char_x = game->char_xy->x;
	char_y = game->char_xy->y;
	if (game->map->data2[char_y][char_x] == 'E'
		&& (game->map->coin_cnt == game->char_xy->char_coin))
	{
		ft_printf("game clear!\n");
		close_game(game);
	}
}
