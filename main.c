/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:50:54 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/11 21:06:21 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
    int		i;
    int		j;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
    
    i = 50;
	while (i < 100)
	{
		j = 50;
		while (j < 100)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00999999);
			j++;
		}
		i++;
	}
}