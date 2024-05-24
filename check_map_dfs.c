/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_dfs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:11:05 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 19:11:37 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	dfs(int x, int y, char **map, char c)
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
