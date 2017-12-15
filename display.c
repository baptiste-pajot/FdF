/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 11:51:06 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 12:04:09 by bpajot      ###    #+. /#+    ###.fr     */
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

static void		display_legend(t_env e, t_size *size)
{
	t_line	line;
	int		sep_width;

	sep_width = 300;
	line.x1 = sep_width;
	line.y1 = 0;
	line.color1 = 0xFFFFFF;
	line.x2 = line.x1;
	line.y2 = e.height - 1;
	line.color2 = line.color1;
	ft_line(e, line);
	line.x1 = 0;
	line.y1 = e.height / 2;
	line.x2 = sep_width;
	line.y2 = line.y1;
	ft_line(e, line);
	mlx_string_put(e.mlx, e.win, sep_width/2 -20, 20, line.color1,
		"FILE");
	mlx_string_put(e.mlx, e.win, sep_width/2 - 130, 2 * e.height / 20,
		line.color1, "name :");
	mlx_string_put(e.mlx, e.win, sep_width/2 - 60, 2* e.height / 20,
		line.color1, e.name);
	mlx_string_put(e.mlx, e.win, sep_width/2 - 130, 3 * e.height / 20,
		line.color1, "len_x :");
	mlx_string_put(e.mlx, e.win, sep_width/2 - 40, 3 * e.height / 20,
		line.color1, ft_itoa(size->len_x));
	mlx_string_put(e.mlx, e.win, sep_width/2 - 130, 4 * e.height / 20,
		line.color1, "len_y :");
	mlx_string_put(e.mlx, e.win, sep_width/2 - 40, 4 * e.height / 20,
		line.color1, ft_itoa(size->len_y));
	mlx_string_put(e.mlx, e.win, sep_width/2 - 130, 5 * e.height / 20,
		line.color1, "max_z :");
	mlx_string_put(e.mlx, e.win, sep_width/2 - 40, 5 * e.height / 20,
		line.color1, ft_itoa(size->max_z));
	mlx_string_put(e.mlx, e.win, sep_width/2 - 130, 6 * e.height / 20,
		line.color1, "min_z :");
	mlx_string_put(e.mlx, e.win, sep_width/2 - 40, 6 * e.height / 20,
		line.color1, ft_itoa(size->min_z));
	mlx_string_put(e.mlx, e.win, sep_width/2 -20, e.height / 2 + 20, 
		line.color1, "VIEW");
	mlx_string_put(e.mlx, e.win, sep_width/2 - 130, 12 * e.height / 20,
		line.color1, "projection :");
	mlx_string_put(e.mlx, e.win, sep_width/2 , 12* e.height / 20,
		line.color1, "iso");
	mlx_string_put(e.mlx, e.win, sep_width/2 - 130, 13 * e.height / 20,
		line.color1, "scale_xy :");
	mlx_string_put(e.mlx, e.win, sep_width/2 , 13 * e.height / 20,
		line.color1, ft_itoa(size->scale_xy));
	mlx_string_put(e.mlx, e.win, sep_width/2 - 130, 14 * e.height / 20,
		line.color1, "scale_z :");
	mlx_string_put(e.mlx, e.win, sep_width/2 , 14 * e.height / 20,
		line.color1, ft_itoa(size->scale_z));
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
