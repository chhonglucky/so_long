/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:20:15 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/19 16:33:18 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "./includes/so_long.h"
#include "csfunc.h"
#include "./Libft/ft_printf.h"
#include "./Libft/libft.h"


void	map_parsing(t_game game, char *filename)
{
	count_max_rows_cols(&game, filename);
	
}

void	count_max_rows_cols(t_game *game, int fd)
{
	int		tmp_cols;
	char	c;

	game->map->row = 0;
	game->map->col = 0;
	tmp_cols = 0;
	while (shell_read(fd, &c, 1) > 0)
	{
		if (game->map->col < tmp_cols)
			game->map->col = tmp_cols;
		if (c == '\n')
		{
			game->map->row++;
			tmp_cols = 0;
		}
		else
			tmp_cols++;
	}
}