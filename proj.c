/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proj.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 10:06:39 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 10:08:35 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		tab_proj(int ***tab, t_size *size)
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
}
