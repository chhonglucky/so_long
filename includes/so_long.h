/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:22:42 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/20 18:06:23 by chanhhon         ###   ########.fr       */
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

# define ESC_KEY		53
# define W_KEY			13
# define A_KEY			0
# define S_KEY			1
# define D_KEY			2

#endif