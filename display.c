/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 14:30:27 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 19:15:50 by bpajot      ###    #+. /#+    ###.fr     */
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

int				display(t_size *size)
{
	t_env	e;
	t_line	line;
	int		x;
	int		y;
	

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2500, 1300, "mlx bpajot");
	x = -1;
	while (++x < size->len_x)
	{
		y = -1;
		while (++y < size->len_y)
		{
			line.x1 = x * 10 + 10;
			line.y1 = y * 10 + 10 ;
			line.x2 = line.x1 + 10;
			line.y2 = line.y1;
			line.color1 = 0x00FF00;
			ft_line(e, line);
			line.x1 = x * 10 + 10;
			line.y1 = y * 10 + 10 ;
			line.x2 = line.x1;
			line.y2 = line.y1 + 10;
			line.color1 = 0x00FF00;
			ft_line(e, line);
		}
	}
	mlx_key_hook(e.win, my_key_funct, 0);
	mlx_loop(e.mlx);
	return (0);
}
