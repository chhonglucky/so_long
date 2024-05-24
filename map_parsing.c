/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:20:15 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 19:18:36 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	read_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = shell_open(filename, O_RDONLY, 0777);
	line = get_next_line(fd);
	game->map->col = 0;
	game->map->row = ft_strlen(line) - 1;
	game->map->data = ft_strdup_without_newline(line);
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
	game->map->data2 = ft_split_size(game->map->data,
			game->map->col, game->map->row);
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
