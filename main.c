/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:50:54 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/17 14:25:46 by hongchanhye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "./includes/so_long.h"
#include "./Libft/ft_printf.h"
#include "./Libft/libft.h"

static int is_ber_file(const char *argv);
static void init_map(t_game *game, char *filename);
static void	init_game(t_game *game, char *path);

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2 && !(is_ber_file(argv[1])))
		endgame("Can't open file. The format is not supported!", &game, error);
	else if (argc > 2)
		endgame("Can't open multiple files!", &game, error);
	else if (argc == 2 && (is_ber_file(argv[1]))) 
		init_game(&game, argv[1]);
	endgame("Please specify file name!", &game, error);
	return (0);
}

static void	init_game(t_game *game, char *filename)
{ 
	init_map(game, filename);
	init_images(game);
	render_map(game);
	init_hook(game, KEY_RELEASE, KEY_RELEASE_MASK, key_check);
	init_hook(game, DESTROY_NOTIFY, NO_EVENT_MASK, red_cross);
	init_hook(game, EXPOSE, EXPOSURE_MASK, mini_maker);
	mlx_loop(game->mlx_pointer);
}

static void init_map(t_game *game, char *filename)
{

}

static	int	is_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(argv, '.');
	if (string)
		return (ft_strcmp(string, ".ber") == 0);
	return (0);
}