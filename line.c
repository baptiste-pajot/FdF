/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 17:30:49 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 14:11:48 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_swap_line(t_all *all)
{
	ft_swap(&(all->line.y1), &(all->line.y2));
	ft_swap(&(all->line.x1), &(all->line.x2));
	ft_swap(&(all->line.color1), &(all->line.color2));
	return (1);
}

static int		ft_line2(t_all *all)
{
	int		x;
	int		reverse;

	reverse = 0;
	if (all->line.x1 > all->line.x2)
		reverse = ft_swap_line(all);
	if (all->line.y1 != all->line.y2 && all->line.x1 != all->line.x2)
	{
		x = all->line.x1 - 1;
		while (++x <= all->line.x2)
			mlx_pixel_image(all, x, all->line.y1 +
				(all->line.y2 - all->line.y1) * (x - all->line.x1) /
				(all->line.x2 - all->line.x1), 0);
	}
	else if (all->line.x1 != all->line.x2)
	{
		x = all->line.x1 - 1;
		while (++x <= all->line.x2)
			mlx_pixel_image(all, x, all->line.y1, 0);
	}
	if (reverse == 1)
		ft_swap_line(all);
	return (0);
}

static int		ft_line1(t_all *all)
{
	int		y;
	int		reverse;

	reverse = 0;
	if (all->line.y1 > all->line.y2)
		reverse = ft_swap_line(all);
	if (all->line.x1 != all->line.x2 && all->line.y1 != all->line.y2)
	{
		y = all->line.y1 - 1;
		while (++y <= all->line.y2)
			mlx_pixel_image(all, all->line.x1 + (all->line.x2
				- all->line.x1) * (y - all->line.y1) / (all->line.y2 -
				all->line.y1), y, 1);
	}
	else if (all->line.y1 != all->line.y2)
	{
		y = all->line.y1 - 1;
		while (++y <= all->line.y2)
			mlx_pixel_image(all, all->line.x1, y, 1);
	}
	if (reverse == 1)
		ft_swap_line(all);
	return (0);
}

int				ft_line(t_all *all)
{
	int		delta_x;
	int		delta_y;

	if ((all->line.x2 - all->line.x1) >= 0)
		delta_x = all->line.x2 - all->line.x1;
	else
		delta_x = all->line.x1 - all->line.x2;
	if ((all->line.y2 - all->line.y1) >= 0)
		delta_y = all->line.y2 - all->line.y1;
	else
		delta_y = all->line.y1 - all->line.y2;
	if (delta_x <= delta_y)
		ft_line1(all);
	else
		ft_line2(all);
	return (0);
}
