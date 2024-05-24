/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:11:50 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 19:18:17 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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
