/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 11:51:06 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 15:14:22 by bpajot      ###    #+. /#+    ###.fr     */
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
		ft_line(all);
	}
	if (i < all->size.len_y - 1)
	{
		all->line.x2 = all->tab[i + 1][j][2];
		all->line.y2 = all->tab[i + 1][j][3];
		all->line.color2 = all->tab[i + 1][j][1];
		ft_line(all);
	}
}

static void		display_line(t_all *all)
{
	int		i;
	int		j;

	if (all->size.rot_z >= -45 && all->size.rot_z < 45)
	{
		i = -1;
		while (++i < all->size.len_y)
		{
			j = -1;
			while (++j < all->size.len_x)
				fill_line(all, i, j);
		}
	}
	else if (all->size.rot_z >= 45 && all->size.rot_z < 135)
	{
		j = all->size.len_x;
		while (--j >= 0)
		{
			i = -1;
			while (++i < all->size.len_y)
				fill_line(all, i, j);
		}
	}
	else if (all->size.rot_z >= -135 && all->size.rot_z < -45)
	{
		j = -1;
		while (++j < all->size.len_x)
		{
			i = all->size.len_y;
			while (--i >= 0)
				fill_line(all, i, j);
		}
	}
	else
	{
		i = all->size.len_y;
		while (--i >= 0)
		{
			j = all->size.len_x;
			while (--j >= 0)
				fill_line(all, i, j);
		}
	}
}

static int		keyboard_funct(int keycode, t_all *all)
{
	if (keycode == 53 || keycode == 12)
		exit(0);
	if ((keycode >= 123 && keycode <= 126) || (keycode >= 18 && keycode <= 23)
		|| keycode == 26 || keycode == 28)
	{
		if (keycode == 126)
			all->size.center_y -= 50;
		if (keycode == 125)
			all->size.center_y += 50;
		if (keycode == 123)
			all->size.center_x -= 50;
		if (keycode == 124)
			all->size.center_x += 50;
		if (keycode == 18)
		{
			all->size.scale_xy /= 1.2;
			all->size.scale_z /= 1.2;
		}
		if (keycode == 19)
		{
			all->size.scale_xy *= 1.2;
			all->size.scale_z *= 1.2;
		}
		if (keycode == 20)
			all->size.scale_xy /= 1.2;
		if (keycode == 21)
			all->size.scale_xy *= 1.2;
		if (keycode == 23)
			all->size.scale_z /= 1.2;
		if (keycode == 22)
			all->size.scale_z *= 1.2;
		if (keycode == 26)
		{
			if (all->size.rot_z > -180)
				all->size.rot_z -= 10;
			else
				all->size.rot_z = 170;
		}
		if (keycode == 28)
		{
			if (all->size.rot_z < 180)
				all->size.rot_z += 10;
			else
				all->size.rot_z = -170;
		}
		all->size.modify = 1;
		tab_proj(all);
		ft_bzero(all->e.char_image, all->e.size_line * all->e.height - 1);
		display_line(all);
		mlx_put_image_to_window(all->e.mlx, all->e.win, all->e.image, 0, 0);
		if (all->e.width >= 1000 && all->e.height >= 600)
		{
			mlx_put_image_to_window(all->e.mlx, all->e.win,
				all->e.image_black_legend, 0, 0);
			display_legend(all);
		}
	}
	return (0);
}

int				display(t_all *all, char *name)
{
	all->e.sep_width = 300;
	if ((ft_strrchr(name, '/')) != NULL)
		all->e.name = ft_strrchr(name, '/') + 1;
	else
		all->e.name = name;
	if (ft_strlen(all->e.name) > 20)
		all->e.name = ft_strjoin(ft_strsub(all->e.name, 0, 17), "...");
	if (W_WIDTH > 99 && W_WIDTH < 2401 && W_HEIGHT > 99 && W_HEIGHT < 1201)
	{
		all->e.width = W_WIDTH;
		all->e.height = W_HEIGHT;
	}
	else
	{
		all->e.width = 2400;
		all->e.height = 1200;
	}
	all->e.mlx = mlx_init();
	image_black(all);
	all->e.win = mlx_new_window(all->e.mlx, all->e.width, all->e.height,
		"FDF bpajot");
	all->size.modify = 0;
	tab_proj(all);
	display_line(all);
	mlx_put_image_to_window(all->e.mlx, all->e.win, all->e.image, 0, 0);
	if (all->e.width >= 1000 && all->e.height >= 600)
	{
		display_seprarator(all, 0xFFFFFF);
		mlx_put_image_to_window(all->e.mlx, all->e.win,
				all->e.image_black_legend, 0, 0);
		display_legend(all);
	}
	mlx_key_hook(all->e.win, keyboard_funct, all);
	mlx_loop(all->e.mlx);
	return (0);
}
