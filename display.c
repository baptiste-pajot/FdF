/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 14:30:27 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 18:30:55 by bpajot      ###    #+. /#+    ###.fr     */
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

static int		***tab_proj(int ***tab, t_size *size)
{
	int		i;
	int		j;
	double	c1;
	double	c2;
	double	c3;

	c1 = sqrt(2) / 2 * size->scale_xy;
	c2 = sqrt(2.0 / 3.0) * size->scale_z;
	c3 = 1 / sqrt(6) * size->scale_xy;
	i = -1;
	while (++i < size->len_y)
	{
		j = -1;
		while (++j < size->len_x)
		{
			tab[i][j][2] = 1250 + c1 * (j - i);
			tab[i][j][3] = 400 - c2 * tab[i][j][0] + c3 * (i + j);
		}
	}
	return (tab);
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

int				display(int ***tab, t_size *size)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2500, 1300, "mlx bpajot");
	tab_proj(tab, size);
	display_line(tab, size, e);
	mlx_key_hook(e.win, my_key_funct, 0);
	mlx_loop(e.mlx);
	return (0);
}
