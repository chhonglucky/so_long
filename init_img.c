/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:14:23 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 19:14:50 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_img(t_game *game)
{
	int	img_height;
	int	img_width;

	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 63 * game->map->row,
			63 * game->map->col, "so_long_chanhhon");
	game->img->ball = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/ball.xpm", &img_width, &img_height);
	game->img->ladder = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/ladder.xpm", &img_width, &img_height);
	game->img->player_E = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/player_E.xpm", &img_width, &img_height);
	game->img->player_N = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/player_N.xpm", &img_width, &img_height);
	game->img->player_S = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/player_S.xpm", &img_width, &img_height);
	game->img->player_W = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/player_W.xpm", &img_width, &img_height);
	game->img->player = game->img->player_S;
	game->img->tile0 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/tile00.xpm", &img_width, &img_height);
	game->img->tile1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/tile01.xpm", &img_width, &img_height);
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
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img->tile1, row * 63, col * 63);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img->tile0, row * 63, col * 63);
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
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img->ball, row * 63, col * 63);
			else if (game->map->data2[col][row] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img->ladder, row * 63, col * 63);
			row++;
		}
		col++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->player,
		game->char_xy->x * 63, (game->char_xy->y - 1) * 63);
	check_end(game);
}
