/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:22:42 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 17:12:29 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define X_EVENT_EXIT		17
# define ESC				53
# define W					13
# define A					0
# define S					1
# define D					2

# include <stdbool.h>

typedef struct s_map {
	int		row;
	int		col;
	int		coin_cnt;
	int		player_cnt;
	int		exit_cnt;
	char	*data;
	char	**data2;
}				t_map;

typedef struct s_img {
	void	*ball;
	void	*ladder;
	void	*player_N;
	void	*player_E;
	void	*player_S;
	void	*player_W;
	void	*player;
	void	*tile0;
	void	*tile1;
}				t_img;

typedef struct s_char_xy {
	int	x;
	int	y;
	int distance;
	int	char_coin;
}				t_char_xy;

typedef struct s_game {
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_img		*img;
	t_char_xy	*char_xy;
}				t_game;



#endif