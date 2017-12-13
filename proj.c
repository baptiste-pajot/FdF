/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proj.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 10:06:39 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 13:42:02 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void		tab_scale(int ***tab, t_size *size, t_env e)
{
	int		height_proj;
	int		width_proj;

	width_proj = tab[size->len_x][0][2] - tab[0][size->len_y - 1][2];
	printf("width_proj = %d\n", width_proj);



}

void			tab_proj_ini(int ***tab, t_size *size, t_env e)
{
	int		i;
	int		j;
	double	c1;
	double	c2;
	double	c3;

	c1 = sqrt(2) / 2 * 100;
	c2 = sqrt(2.0 / 3.0) * 100;
	c3 = 1 / sqrt(6) * 100;
	i = -1;
	while (++i < size->len_y)
	{
		j = -1;
		while (++j < size->len_x)
		{
			tab[i][j][2] = c1 * (j - i);
			tab[i][j][3] = - c2 * tab[i][j][0] + c3 * (i + j);
		}
	}
	
}

void			tab_proj(int ***tab, t_size *size, t_env e)
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
			tab[i][j][2] = c1 * (j - i);
			tab[i][j][3] = - c2 * tab[i][j][0] + c3 * (i + j);
		}
	}
	
}
