/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 14:30:27 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 17:19:33 by bpajot      ###    #+. /#+    ###.fr     */
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

int				display(int ***tab, t_size *size)
{
	t_env	e;
	t_line	line;
	int		i;
	int		j;

	line.color1 = 0xFFFFFF;
	line.color2 = 0xFFFFFF;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2500, 1300, "mlx bpajot");
	tab_proj(tab, size);
	i = -1;
	while (++i < size->len_y)
	{
		j = -1;
		while (++j < size->len_x)
		{
			if (j < size->len_x - 1)
			{
				line.x1 = tab[i][j][2];
				line.y1 = tab[i][j][3];
				line.x2 = tab[i][j + 1][2];
				line.y2 = tab[i][j + 1][3];
				ft_line(e, line);
			}
			if (i < size->len_y - 1)
			{
				line.x1 = tab[i][j][2];
				line.y1 = tab[i][j][3];
				line.x2 = tab[i + 1][j][2];
				line.y2 = tab[i + 1][j][3];
				ft_line(e, line);
			}
		}
	}
	mlx_key_hook(e.win, my_key_funct, 0);
	mlx_loop(e.mlx);
	return (0);
}
