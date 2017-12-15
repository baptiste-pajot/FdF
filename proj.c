/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proj.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 10:06:39 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 14:21:40 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static double	tab_scale_xy(t_size *size, t_env e)
{
	double		width_proj;
	double		scale_xy;

	width_proj = sqrt(2) / 2 * (size->len_y + size->len_x - 2);
	printf("width_proj = %lf\n", width_proj);
	if (e.width >= 1000)
		scale_xy = (e.width - 300) / width_proj * 0.5;
	else
		scale_xy = e.width / width_proj * 0.5;
	printf("scale_xy = %lf\n", scale_xy);
	return (scale_xy);
}

static double	tab_scale_z(t_size *size, t_env e)
{
	double		height_proj;
	double		scale_z;
	double		c2;
	double		c3;

	c2 = sqrt(2.0 / 3.0);
	c3 = 1 / sqrt(6);
	height_proj = -c2 * size->min_z + c3 * (size->len_x + size->len_y - 2)
		+ c2 * size->max_z;
	printf("height_proj = %lf\n", height_proj);
	scale_z = e.height / height_proj * 0.5;
	printf("scale_z = %lf\n", scale_z);
	return (scale_z);
}

void			tab_proj(int ***tab, t_size *size, t_env e)
{
	int			i;
	int			j;
	double		c1;
	double		c2;
	double		c3;

	if (size->scale_xy_ini == -1)
		size->scale_xy = tab_scale_xy(size, e);
	else
		size->scale_xy = size->scale_xy_ini;
	if (size->scale_z_ini == -1)
		size->scale_z = tab_scale_z(size, e);
	else
		size->scale_z = size->scale_z_ini;
	c1 = sqrt(2) / 2 * size->scale_xy;
	c3 = 1 / sqrt(6) * size->scale_xy;
	c2 = sqrt(2.0 / 3.0) * size->scale_z;
	i = -1;
	if (size->center_modify == 0)
	{
		if (e.width >= 1000 && e.height >= 600)
			size->center_x = (e.width - 300) / 2 + 300;
		else
			size->center_x = e.width / 2;
		size->center_y = e.height / 2;
	}
	while (++i < size->len_y)
	{
		j = -1;
		while (++j < size->len_x)
		{
			tab[i][j][2] = size->center_x - c1 * (size->len_x - size->len_y)
				/ 2 + c1 * (j - i);
			tab[i][j][3] = size->center_y + ((size->max_z - size->min_z) * c2
					- c3 * (size->len_x + size->len_y - 2)) / 2
				- c2 * tab[i][j][0] + c3 * (i + j);
		}
	}
}
