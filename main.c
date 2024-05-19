/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:50:54 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/19 22:40:39 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "./includes/so_long.h"
#include "./Libft/ft_printf.h"
#include "./Libft/libft.h"
#include "./Libft/get_next_line.h"
#include "csfunc.h"


static	int	is_ber_file(const char *argv);
void	read_map(t_game *game, char *filename);
char	*ft_strdup_without_newline(char *str);
char	*ft_strjoin_without_newline(char *str1, char *str2);
void	init_img(t_game *game);
void	setting_img(t_game *game);


int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		unix_error("Input format : ./so_long [MAP_FILE.ber]\n");
	game.img = (t_img *)shell_malloc(sizeof(t_img));
	game.map = (t_map *)shell_malloc(sizeof(t_map));
	read_map(&game, argv[1]);
	init_img(&game);
	setting_img(&game);
	mlx_loop(game.mlx_ptr);
}

static	int	is_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(argv, '.');
	if (string)
		return (ft_strcmp(string, ".ber") == 0);
	return (0);
}

void	read_map(t_game *game, char *filename)
{
	int  fd;
	char *line;

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
		{
			game->map->data = ft_strjoin_without_newline(game->map->data, line);
		}
	}
	close(fd);
}

char	*ft_strdup_without_newline(char *str)
{
	if (str[ft_strlen(str) - 2] == '\n')
		str[ft_strlen(str) - 2] = '\0';
	return (ft_strdup(str));
}

char	*ft_strjoin_without_newline(char *str1, char *str2)
{
	if (str2[ft_strlen(str2) - 2] == '\n')
		str2[ft_strlen(str2) - 2] = '\0';
	return (ft_strjoin(str1, str2));
}

void	init_img(t_game *game)
{
	int	img_height;
	int	img_width;

	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1200, 1200, "my_mlx");
	game->img->ball = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/ball.xpm", &img_width, &img_height);
	game->img->ladder = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/ladder.xpm", &img_width, &img_height);
	game->img->player_E = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player_E.xpm", &img_width, &img_height);
	game->img->player_N = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player_N.xpm", &img_width, &img_height);
	game->img->player_S = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player_S.xpm", &img_width, &img_height);
	game->img->player_W = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player_W.xpm", &img_width, &img_height);
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
			if (game->map->data[col * game->map->row + row] == '1')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile0, row * 64, col * 64);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile1, row * 64, col * 64);
			}
			else if (game->map->data[col * game->map->row + row] == 'C')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->ball, row * 64, col * 64);
			}
			else if (game->map->data[col * game->map->row + row] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->player_S, row * 64, col * 64);
			}
			else if (game->map->data[col * game->map->row + row] == 'E')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->ladder, row * 64, col * 64);
			}
			else
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->tile0, row * 64, col * 64);
			}
			row++;
		}
		col++;
	}
}
