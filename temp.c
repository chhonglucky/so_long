/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:44:52 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/19 22:28:07 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "./mlx/mlx.h"


int main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	unsigned int *data;

	int img_width;
	int img_height;
	// int bpp;
	// int size_l;
	// int endian;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./textures/tile01.xpm", &img_width, &img_height);
	// data = (unsigned int *)mlx_get_data_addr(img_ptr, &bpp, &size_l, &endian);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 64, 64);
	mlx_loop(mlx_ptr);
}
