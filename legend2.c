/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   legend2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 13:26:25 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 16:53:35 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void			display_legend(t_all *all)
{
	display_seprarator(all, 0xFFFFFF);
	display_file(all->e, all->size, 0xFFFFFF);
	display_view(all->e, all->size, 0xFFFFFF);
	display_view2(all->e, all->size, 0xFFFFFF);
	display_com(all->e, 0xFFFFFF);
	display_frame_txt(all);
}

static void		mlx_pixel_image_leg(t_all *all, int x, int y)
{
	if (x >= 0 && x < all->e.sep_width && y >= 0 && y < all->e.height)
	{
		all->e.char_legend[(y * all->e.sep_width + x) * 4] =
			all->line.color1 % 256;
		all->e.char_legend[(y * all->e.sep_width + x) * 4 + 1] =
			all->line.color1 % 65536 / 256;
		all->e.char_legend[(y * all->e.sep_width + x) * 4 + 2] =
			all->line.color1 % 16777216 / 65536;
	}
}

static int		ft_line2(t_all *all)
{
	int		x;

	x = all->line.x1 - 1;
	while (++x <= all->line.x2)
		mlx_pixel_image_leg(all, x, all->line.y1);
	return (0);
}

static int		ft_line1(t_all *all)
{
	int		y;

	y = all->line.y1 - 1;
	while (++y <= all->line.y2)
		mlx_pixel_image_leg(all, all->line.x1, y);
	return (0);
}

void			display_seprarator(t_all *all, int color)
{
	all->line.x1 = all->e.sep_width - 1;
	all->line.y1 = 0;
	all->line.color1 = color;
	all->line.x2 = all->line.x1;
	all->line.y2 = all->e.height - 1;
	ft_line1(all);
	all->line.x1 = 0;
	all->line.y1 = 7 * all->e.height / 30;
	all->line.x2 = all->e.sep_width - 1;
	all->line.y2 = all->line.y1;
	ft_line2(all);
	all->line.x1 = 0;
	all->line.y1 = 16 * all->e.height / 30;
	all->line.x2 = all->e.sep_width - 1;
	all->line.y2 = all->line.y1;
	ft_line2(all);
}
