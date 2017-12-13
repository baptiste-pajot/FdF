/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 14:30:27 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 17:35:06 by bpajot      ###    #+. /#+    ###.fr     */
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

static void		fill_line(int ***tab, t_size *size, t_env e, t_ij ij)
{
	t_line	line;

	line.x1 = tab[ij.i][ij.j][2];
	line.y1 = tab[ij.i][ij.j][3];
	line.color1 = tab[ij.i][ij.j][1];
	if (ij.j < size->len_x - 1)
	{
		line.x2 = tab[ij.i][ij.j + 1][2];
		line.y2 = tab[ij.i][ij.j + 1][3];
		line.color2 = tab[ij.i][ij.j + 1][1];
		ft_line(e, line);
	}
	if (ij.i < size->len_y - 1)
	{
		line.x2 = tab[ij.i + 1][ij.j][2];
		line.y2 = tab[ij.i + 1][ij.j][3];
		line.color2 = tab[ij.i + 1][ij.j][1];
		ft_line(e, line);
	}
}

static void		display_line(int ***tab, t_size *size, t_env e)
{
	t_ij	ij;

	ij.i = -1;
	while (++ij.i < size->len_y)
	{
		ij.j = -1;
		while (++ij.j < size->len_x)
			fill_line(tab, size, e, ij);
	}
}

static void		display_separator(t_env e)
{
	t_line	line;

	line.x1 = 300;
	line.y1 = 0;
	line.color1 = 0xFFFFFF;
	line.x2 = line.x1;
	line.y2 = e.height - 1;
	line.color2 = line.color1;
	ft_line(e, line);
}

int				display(int ***tab, t_size *size)
{
	t_env	e;

	e.width = 2400;
	e.height = 1200;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.width, e.height, "FDF bpajot");
	tab_proj(tab, size, e);
	ft_putstr("projection OK \n");
	display_line(tab, size, e);
	if (e.width >= 1000)
		display_separator(e);
	mlx_key_hook(e.win, my_key_funct, 0);
	mlx_loop(e.mlx);
	return (0);
}
