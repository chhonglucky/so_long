/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:10:08 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 19:12:51 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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

int	is_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(argv, '.');
	if (string)
		return (ft_strcmp(string, ".ber") == 0);
	return (0);
}

int	check_component(char *str)
{
	int	i;
	int	component_cnt;

	i = 0;
	component_cnt = 0;
	while (str[i])
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
