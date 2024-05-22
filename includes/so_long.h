/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:22:42 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/22 23:50:36 by hongchanhye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 3

# include <stdbool.h>

typedef struct s_map {
	int		row;
	int		col;
	int		error;
	char	*data;
}				t_map;

typedef struct s_img {
	void	*ball;
	void	*ladder;
	void	*player_N;
	void	*player_E;
	void	*player_S;
	void	*player_W;
	void	*tile0;
	void	*tile1;
}				t_img;

typedef struct s_flag {
	bool	collect_all_coin;
	bool	game_start;
}				t_flag;

typedef struct s_char_xy {
	int	x;
	int	y;
}				t_char_xy;

typedef struct s_game {
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_img		*img;
	t_char_xy	*char_xy;
	t_flag		*flag;
}				t_game;

# define ESC		53
# define W			13
# define A			0
# define S			1
# define D			2

#endif