/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 11:51:06 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 19:22:55 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		fill_line(t_all *all, int i, int j)
{
	all->line.x1 = all->tab[i][j][2];
	all->line.y1 = all->tab[i][j][3];
	all->line.color1 = all->tab[i][j][1];
	if (j < all->size.len_x - 1)
	{
		all->line.x2 = all->tab[i][j + 1][2];
		all->line.y2 = all->tab[i][j + 1][3];
		all->line.color2 = all->tab[i][j + 1][1];
		ft_line(all->e, all->line);
	}
	if (i < all->size.len_y - 1)
	{
		all->line.x2 = all->tab[i + 1][j][2];
		all->line.y2 = all->tab[i + 1][j][3];
		all->line.color2 = all->tab[i + 1][j][1];
		ft_line(all->e, all->line);
	}
}

static void		display_line(t_all *all)
{
	int		i;
	int		j;

	i = -1;
	while (++i < all->size.len_y)
	{
		j = -1;
		while (++j < all->size.len_x)
			fill_line(all, i, j);
	}
}

static void		display_black(t_all *all)
{
	int		i;

	i = -1;
	while (++i < all->e.width)
	{
		all->line.color1 = 0;
		all->line.color2 = 0;
		all->line.x1 = i;
		all->line.x2 = i;
		all->line.y1 = 0;
		all->line.y2 = all->e.height;
		ft_line(all->e, all->line);
	}
}

static int		keyboard_funct(int keycode, t_all *all)
{
	if (keycode == 53 || keycode == 12)
		exit(0);
	if (keycode >= 123 && keycode <= 126)
	{
		if (keycode == 126)
			all->size.center_y -= 50;
		if (keycode == 125)
			all->size.center_y += 50;
		if (keycode == 123)
			all->size.center_x -= 50;
		if (keycode == 124)
			all->size.center_x += 50;
		all->size.center_modify = 1;
		tab_proj(all);
		ft_putstr("projection OK \n");
		display_black(all);
		display_line(all);
		if (all->e.width >= 1000 && all->e.height >= 600)
			display_legend(all);
	}
	return (0);
}

int				display(t_all *all, char *name)
{
	if ((ft_strrchr(name, '/')) != NULL)
		all->e.name = ft_strrchr(name, '/') + 1;
	else
		all->e.name = name;
	if (ft_strlen(all->e.name) > 20)
		all->e.name = ft_strjoin(ft_strsub(name, 0, 17), "...");
	all->e.width = WIN_WIDTH;
	all->e.height = WIN_HEIGHT;
	all->e.mlx = mlx_init();
	all->e.win = mlx_new_window(all->e.mlx, all->e.width, all->e.height,
		"FDF bpajot");
	all->size.center_modify = 0;
	tab_proj(all);
	ft_putstr("projection OK \n");
	display_line(all);
	if (all->e.width >= 1000 && all->e.height >= 600)
		display_legend(all);
	mlx_key_hook(all->e.win, keyboard_funct, all);
	mlx_loop(all->e.mlx);
	return (0);
}
