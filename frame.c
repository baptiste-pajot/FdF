/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   frame.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 16:03:04 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 17:30:58 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		display_x(t_all *all)
{
	all->line.x1 = all->e.width - 150;
	all->line.y1 = all->e.height - 150;
	all->line.x2 = all->line.x1 + sqrt(2) / 2 * 100 * (cos(all->size.rot_z *
		M_PI / 180) + sin(all->size.rot_z * M_PI / 180));
	all->line.y2 = all->line.y1 + 1 / sqrt(6) * 100 * (cos(all->size.rot_z *
		M_PI / 180) - sin(all->size.rot_z * M_PI / 180));
	all->line.color1 = 0xFF0000;
	all->line.color2 = 0xFF0000;
	ft_line(all);
}

static void		display_y(t_all *all)
{
	all->line.x1 = all->e.width - 150;
	all->line.y1 = all->e.height - 150;
	all->line.x2 = all->line.x1 + sqrt(2) / 2 * 100 * (-cos(all->size.rot_z *
		M_PI / 180) + sin(all->size.rot_z * M_PI / 180));
	all->line.y2 = all->line.y1 + 1 / sqrt(6) * 100 * (cos(all->size.rot_z *
		M_PI / 180) + sin(all->size.rot_z * M_PI / 180));
	all->line.color1 = 0xFF00;
	all->line.color2 = 0xFF00;
	ft_line(all);
}

static void		display_z(t_all *all)
{
	all->line.x1 = all->e.width - 150;
	all->line.y1 = all->e.height - 150;
	all->line.x2 = all->line.x1;
	all->line.y2 = all->line.y1 - sqrt(2.0 / 3.0) * 100;
	all->line.color1 = 0xFF;
	all->line.color2 = 0xFF;
	ft_line(all);
}

void			display_frame(t_all *all)
{
	if (all->e.width == 2400 && all->e.height >= 1200)
	{
		display_z(all);
		display_x(all);
		display_y(all);
	}
}
