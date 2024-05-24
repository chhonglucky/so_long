/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:22:42 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 19:01:18 by chanhhon         ###   ########.fr       */
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
#include "./mlx/mlx.h"
#include "./Libft/ft_printf.h"
#include "./Libft/libft.h"
#include "./Libft/get_next_line.h"
#include "csfunc.h"

void	init_struct(t_game *game);
int		key_hook(int keycode, t_game *game);
void	move(t_game *game, int x, int y);
void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
int		close_game(t_game *game);
void	free_map_struct(t_map *map);
void	free_img_struct(void *mlx_ptr, t_img *img);
void	free_double_array(char **temp_map);
int		is_ber_file(const char *argv);
void	check_map_basic(t_game *game, char *filename);
int		check_component(char *str);
int		is_rectangle(t_map *map);
int		is_surronded(t_map *map);
int 	dfs(int x, int y, char **map, char c);
int		check_map_dfs(t_game *game);
void	read_map(t_game *game, char *filename);
char	**ft_split_size(char *str, int col, int row);
char	*ft_strdup_without_newline(char *str);
char	*ft_strjoin_without_newline(char *str1, char *str2);
void	init_img(t_game *game);
void	setting_img(t_game *game);
void	setting_img_item(t_game *game);
void	check_end(t_game *game);
void	char_xy_init(t_game *game);

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