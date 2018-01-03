/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   legend2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 13:26:25 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 13:32:31 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		display_legend(t_all *all)
{
	display_seprarator(all, 0xFFFFFF);
	display_file(all->e, all->size, 0xFFFFFF);
	display_view(all->e, all->size, 0xFFFFFF);
	display_view2(all->e, all->size, 0xFFFFFF);
	display_com(all->e, 0xFFFFFF);
}

void		display_seprarator(t_all *all, int color)
{
	all->line.x1 = all->e.sep_width - 1;
	all->line.y1 = 0;
	all->line.color1 = color;
	all->line.x2 = all->line.x1;
	all->line.y2 = all->e.height - 1;
	all->line.color2 = all->line.color1;
	ft_line(all, 1);
	all->line.x1 = 0;
	all->line.y1 = 7 * all->e.height / 30;
	all->line.x2 = all->e.sep_width - 1;
	all->line.y2 = all->line.y1;
	ft_line(all, 1);
	all->line.x1 = 0;
	all->line.y1 = 16 * all->e.height / 30;
	all->line.x2 = all->e.sep_width - 1;
	all->line.y2 = all->line.y1;
	ft_line(all, 1);
}
