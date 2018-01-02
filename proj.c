/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proj.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 10:06:39 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 17:29:32 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static double	tab_scale_xy(t_all *all)
{
	double		width_proj;
	double		scale_xy;

	width_proj = sqrt(2) / 2 * (all->size.len_y + all->size.len_x - 2);
	printf("width_proj = %lf\n", width_proj);
	if (all->e.width >= 1000 && all->e.height >= 600)
		scale_xy = (all->e.width - all->e.sep_width) / width_proj * 0.5;
	else
		scale_xy = all->e.width / width_proj * 0.5;
	printf("scale_xy = %lf\n", scale_xy);
	return (scale_xy);
}

static double	tab_scale_z(t_all *all)
{
	double		height_proj;
	double		scale_z;
	double		c2;
	double		c3;

	c2 = sqrt(2.0 / 3.0);
	c3 = 1 / sqrt(6);
	height_proj = -c2 * all->size.min_z + c3 * (all->size.len_x +
		all->size.len_y - 2) + c2 * all->size.max_z;
	printf("height_proj = %lf\n", height_proj);
	scale_z = all->e.height / height_proj * 0.5;
	printf("scale_z = %lf\n", scale_z);
	return (scale_z);
}

void			tab_proj(t_all *all)
{
	int			i;
	int			j;
	double		c1;
	double		c2;
	double		c3;
	double		cos_z;
	double		sin_z;

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
	c1 = sqrt(2) / 2 * all->size.scale_xy;
	c3 = 1 / sqrt(6) * all->size.scale_xy;
	c2 = sqrt(2.0 / 3.0) * all->size.scale_z;
	cos_z = cos(all->size.rot_z * M_PI / 180);
	sin_z = sin(all->size.rot_z * M_PI / 180);
	if (all->size.modify == 0)
	{
		if (all->e.width >= 1000 && all->e.height >= 600)
			all->size.center_x = (all->e.width - all->e.sep_width) / 2 +
				all->e.sep_width;
		else
			all->size.center_x = all->e.width / 2;
		all->size.center_y = all->e.height / 2;
	}
	i = -1;
	while (++i < all->size.len_y)
	{
		j = -1;
		while (++j < all->size.len_x)
		{
			all->tab[i][j][2] = all->size.center_x - c1 * (cos_z *
				(all->size.len_x - all->size.len_y) + sin_z * (all->size.len_x
				+ all->size.len_y - 2)) / 2 + c1 * (cos_z * (j - i) +
				sin_z * (i + j));
			all->tab[i][j][3] = all->size.center_y - c3 * ((all->size.len_x +
				all->size.len_y - 2) * cos_z + sin_z * (all->size.len_y -
				all->size.len_x)) / 2 - c2 * all->tab[i][j][0] + c3 * (cos_z *
				(i + j) + sin_z * (i - j));
		}
	}
}
