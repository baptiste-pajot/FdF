/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 14:30:27 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 16:28:56 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		my_key_funct(int keycode, void *param)
{
	param++;
	if (keycode == 53 || keycode == 12)
		exit(0);
	return (0);
}

int				display(void)
{
	t_env	e;
	t_line	line;
	int		x;
	int		y;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "mlx bpajot");
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
	line.x1 = 50;
	line.y1 = 80;
	line.x2 = 50;
	line.y2 = 80;
	line.color1 = 0x00FF00;
	ft_line(e, line);
	mlx_key_hook(e.win, my_key_funct, 0);
	mlx_loop(e.mlx);
	return (0);
}
