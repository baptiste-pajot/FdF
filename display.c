/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 14:30:27 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 13:22:12 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

int		my_key_funct(int keycode, void *param)
{
	param++;
	printf("key code : %d\n", keycode);
	if (keycode == 53 || keycode == 12)
		exit(0);
	return (0);
}

int		display(void)
{
	t_env	e;
	int		x;
	int		y;


	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 400, 400, "mlx bpajot");
	x = 100;
	while (x < 200)
	{
		y = 100;
		while (y < 200)
		{
			mlx_pixel_put(e.mlx, e.win, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
	mlx_key_hook(e.win, my_key_funct, 0);
	mlx_loop(e.mlx);
	return (0);
}
