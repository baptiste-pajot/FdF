/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 17:30:49 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 17:13:33 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		mlx_pixel_image(t_all *all, int x, int y, int xory, int imorleg)
{
	int		min;
	int		max;
	int		cur;

	if (xory == 0)
	{
		min = all->line.x1;
		max = all->line.x2;
		cur = x;
	}
	else
	{
		min = all->line.y1;
		max = all->line.y2;
		cur = y;
	}
	if (imorleg == 0)
	{
		if ( x >= 0 && x < all->e.width && y >= 0 && y < all->e.height)
		{
			all->e.char_image[y * all->e.size_line + x * 4] = all->line.color1 % 256
				+ 100 * (cur - min) / (max - min) * (all->line.color2 % 256 -
				all->line.color1 % 256) / 100;
			all->e.char_image[y * all->e.size_line + x * 4 + 1] = all->line.color1 %
				65536 / 256 + 100 * (cur - min) / (max - min) * (all->line.color2 %
				65536 / 256 - all->line.color1 % 65536 / 256) / 100;
			all->e.char_image[y * all->e.size_line + x * 4 + 2] = all->line.color1 %
				16777216 / 65536 + 100 * (cur - min) * (all->line.color2 % 16777216
				/ 65536 - all->line.color1 % 16777216 / 65536) / 100 /(max - min);
		}
	}
	else
	{
		if ( x >= 0 && x < all->e.sep_width && y >= 0 && y < all->e.height)
		{
			all->e.char_legend[(y * all->e.sep_width + x) * 4] = all->line.color1 % 256
				+ 100 * (cur - min) / (max - min) * (all->line.color2 % 256 -
				all->line.color1 % 256) / 100;
			all->e.char_legend[(y * all->e.sep_width + x) * 4 + 1] = all->line.color1 %
				65536 / 256 + 100 * (cur - min) / (max - min) * (all->line.color2 %
				65536 / 256 - all->line.color1 % 65536 / 256) / 100;
			all->e.char_legend[(y * all->e.sep_width + x) * 4 + 2] = all->line.color1 %
				16777216 / 65536 + 100 * (cur - min) * (all->line.color2 % 16777216
				/ 65536 - all->line.color1 % 16777216 / 65536) / 100 /(max - min);
		}
	}
}

static int		ft_line2(t_all *all, int imorleg)
{
	int		x;

	if (all->line.x1 > all->line.x2)
	{
		ft_swap(&(all->line.y1), &(all->line.y2));
		ft_swap(&(all->line.x1), &(all->line.x2));
		ft_swap(&(all->line.color1), &(all->line.color2));
	}
	if (all->line.y1 != all->line.y2 && all->line.x1 != all->line.x2)
	{
		x = all->line.x1 - 1;
		while (++x <= all->line.x2)
			mlx_pixel_image(all, x, all->line.y1 +
				(all->line.y2 - all->line.y1) * (x - all->line.x1) /
				(all->line.x2 - all->line.x1), 0, imorleg);
	}
	else if (all->line.x1 != all->line.x2)
	{
		x = all->line.x1 - 1;
		while (++x <= all->line.x2)
			mlx_pixel_image(all, x, all->line.y1, 0, imorleg);
	}
	return (0);
}

static int		ft_line1(t_all *all, int imorleg)
{
	int		y;

	if (all->line.y1 > all->line.y2)
	{
		ft_swap(&(all->line.y1), &(all->line.y2));
		ft_swap(&(all->line.x1), &(all->line.x2));
		ft_swap(&(all->line.color1), &(all->line.color2));
	}
	if (all->line.x1 != all->line.x2 && all->line.y1 != all->line.y2)
	{
		y = all->line.y1 - 1;
		while (++y <= all->line.y2)
			mlx_pixel_image(all, all->line.x1 + (all->line.x2
				- all->line.x1) * (y - all->line.y1) / (all->line.y2 -
				all->line.y1), y, 1, imorleg);
	}
	else if (all->line.y1 != all->line.y2)
	{
		y = all->line.y1 - 1;
		while (++y <= all->line.y2)
			mlx_pixel_image(all, all->line.x1, y, 1, imorleg);
	}
	return (0);
}

int				ft_line(t_all *all, int imorleg)
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
		ft_line1(all, imorleg);
	else
		ft_line2(all, imorleg);
	return (0);
}
