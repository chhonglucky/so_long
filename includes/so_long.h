/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:22:42 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/13 20:23:11 by chanhhon         ###   ########.fr       */
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

#define W_KEY 


#endif