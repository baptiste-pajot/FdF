/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proj.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 10:06:39 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 19:45:25 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static double		tab_scale_xy(t_all *all)
{
	double		width_proj;
	double		height_proj;
	double		scale_xy;

	width_proj = sqrt(2) / 2 * (all->size.len_y + all->size.len_x - 2);
	if (width_proj == 0)
		return (1);
	height_proj = 1 / sqrt(6) * (all->size.len_y + all->size.len_x - 2);
	if (all->e.width >= 1000 && all->e.height >= 600)
		scale_xy = (all->e.width - all->e.sep_width) / width_proj * 0.8;
	else
		scale_xy = all->e.width / width_proj * 0.8;
	if (scale_xy > all->e.height / height_proj * 0.8)
		scale_xy = all->e.height / height_proj * 0.8;
	return (scale_xy);
}

static double		tab_scale_z(t_all *all)
{
	double		height_proj;
	double		scale_z;
	double		c2;
	double		c3;

	c2 = sqrt(2.0 / 3.0);
	c3 = 1 / sqrt(6) * all->size.scale_xy;
	height_proj = (all->size.max_z >= -all->size.min_z) ? all->size.max_z :
		-all->size.min_z;
	height_proj *= 2 * c2;
	if (height_proj != 0)
		scale_z = (all->e.height - c3 * (all->size.len_x + all->size.len_y - 2))
			/ height_proj * 0.8;
	else
		scale_z = 1;
	return (scale_z);
}

static double		*constante(t_all *all)
{
	double		*cst;

	if ((cst = (double*)malloc(sizeof(double) * 5)) == NULL)
		return (NULL);
	cst[0] = sqrt(2) / 2 * all->size.scale_xy;
	cst[2] = 1 / sqrt(6) * all->size.scale_xy;
	cst[1] = sqrt(2.0 / 3.0) * all->size.scale_z;
	cst[3] = cos(all->size.rot_z * M_PI / 180);
	cst[4] = sin(all->size.rot_z * M_PI / 180);
	return (cst);
}

static void			set_param(t_all *all)
{
	if (all->size.modify == 0)
		all->size.rot_z = 0;
	if (all->size.scale_xy_ini == -1 && all->size.modify == 0)
		all->size.scale_xy = tab_scale_xy(all);
	else if (all->size.modify == 0)
		all->size.scale_xy = all->size.scale_xy_ini;
	if (all->size.scale_z_ini == -1 && all->size.modify == 0)
		all->size.scale_z = tab_scale_z(all);
	else if (all->size.modify == 0)
		all->size.scale_z = all->size.scale_z_ini;
	if (all->size.modify == 0)
	{
		if (all->e.width >= 1000 && all->e.height >= 600)
			all->size.center_x = (all->e.width - all->e.sep_width) / 2 +
				all->e.sep_width;
		else
			all->size.center_x = all->e.width / 2;
		all->size.center_y = all->e.height / 2;
	}
}

int					tab_proj(t_all *all)
{
	int			i;
	int			j;
	double		*c;

	set_param(all);
	c = constante(all);
	if (c == NULL)
		return (-1);
	i = -1;
	while (++i < all->size.len_y)
	{
		j = -1;
		while (++j < all->size.len_x)
		{
			all->tab[i][j][2] = all->size.center_x - c[0] * (c[3] *
				(all->size.len_x - all->size.len_y) + c[4] * (all->size.len_x
				+ all->size.len_y - 2)) / 2 + c[0] * (c[3] * (j - i) +
				c[4] * (i + j));
			all->tab[i][j][3] = all->size.center_y - c[2] * ((all->size.len_x +
				all->size.len_y - 2) * c[3] + c[4] * (all->size.len_y -
				all->size.len_x)) / 2 - c[1] * all->tab[i][j][0] + c[2] *
				(c[3] * (i + j) + c[4] * (i - j));
		}
	}
	return (0);
}
