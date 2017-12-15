/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 11:51:06 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 17:14:18 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

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

static int		keyboard_funct(int keycode, t_all *all)
{
	if (keycode == 53 || keycode == 12)
		exit(0);
	if (keycode >= 123 && keycode <= 126)
	{
		if (keycode == 126)
			all->size->center_y -= 50;
		if (keycode == 125)
			all->size->center_y += 50;
		if (keycode == 123)
			all->size->center_x -= 50;
		if (keycode == 124)
			all->size->center_x += 50;
		all->size->center_modify = 1;
		tab_proj(all->tab, all->size, all->e);
		ft_putstr("projection OK \n");
		display_line(all->tab, all->size, all->e);
	}
	return (0);
}

int				display(int ***tab, t_size *size, char *name)
{
	t_all	all;
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
	e.width = WIN_WIDTH;
	e.height = WIN_HEIGHT;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.width, e.height, "FDF bpajot");
	size->center_modify = 0;
	all.tab = tab;
	all.e = e;
	all.size = size;
	tab_proj(tab, size, e);
	ft_putstr("projection OK \n");
	display_line(tab, size, e);
	if (e.width >= 1000 && e.height >= 600)
		display_legend(e, size);
	mlx_key_hook(e.win, keyboard_funct, &all);
	mlx_loop(e.mlx);
	return (0);
}
