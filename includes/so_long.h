/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:22:42 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/17 13:12:51 by hongchanhye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_info {
    t_map *map;

}   t_info;

typedef struct s_map {
    int row;
    int col;
    int error;
}   t_map;

# define KEY_ESC		53
# define W_KEY			13
# define A_KEY			0
# define S_KEY			1
# define D_KEY			2

#endif