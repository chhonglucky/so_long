/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:20:56 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 20:39:08 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	game->img->player = game->img->player_n;
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
	game->img->player = game->img->player_w;
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
	game->img->player = game->img->player_s;
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
	game->img->player = game->img->player_e;
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
