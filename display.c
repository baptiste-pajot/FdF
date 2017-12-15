/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 11:51:06 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 12:19:03 by bpajot      ###    #+. /#+    ###.fr     */
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

int				display(int ***tab, t_size *size, char *name)
{
	t_env	e;

	if ((ft_strrchr(name, '/')) != NULL)
		e.name = ft_strrchr(name, '/') + 1;
	else
		e.name = name;
	if (ft_strlen(e.name) > 20)
	{
		e.name[17] = '.';
		e.name[18] = '.';
		e.name[19] = '.';
		e.name[20] = '\0';
	}
	e.width = 2400;
	e.height = 1200;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.width, e.height, "FDF bpajot");
	tab_proj(tab, size, e);
	ft_putstr("projection OK \n");
	display_line(tab, size, e);
	if (e.width >= 1000 && e.height >= 600)
		display_legend(e, size);
	mlx_key_hook(e.win, my_key_funct, 0);
	mlx_loop(e.mlx);
	return (0);
}
