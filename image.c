/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 11:12:33 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 15:11:20 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		*new_image(t_all *all)
{
	void	*image;

	image = NULL;
	image = mlx_new_image(all->e.mlx, all->e.width, all->e.height);
	return (image);
}

static void		*new_image_black_legend(t_all *all)
{
	void	*image;

	image = NULL;
	if (all->e.width >= 1000 && all->e.height >= 600)
		image = mlx_new_image(all->e.mlx, all->e.sep_width, all->e.height);
	return (image);
}

void			image_black(t_all *all)
{
	all->e.image_black_legend = new_image_black_legend(all);
	all->e.image = new_image(all);
	all->e.char_legend = mlx_get_data_addr(all->e.image_black_legend,
		&(all->e.bpp), &(all->e.size_line), &(all->e.endian));
	all->e.char_image = mlx_get_data_addr(all->e.image, &(all->e.bpp),
		&(all->e.size_line), &(all->e.endian));
}

void			mlx_pixel_image(t_all *all, int x, int y, int xory)
{
	int		min;
	int		max;
	int		cur;

	min = (xory) ? all->line.y1 : all->line.x1;
	max = (xory) ? all->line.y2 : all->line.x2;
	cur = (xory) ? y : x;
	if (x >= 0 && x < all->e.width && y >= 0 && y < all->e.height)
	{
		all->e.char_image[y * all->e.size_line + x * 4] = all->line.color1
			% 256 + 100 * (cur - min) / (max - min) * (all->line.color2 %
			256 - all->line.color1 % 256) / 100;
		all->e.char_image[y * all->e.size_line + x * 4 + 1] =
			all->line.color1 % 65536 / 256 + 100 * (cur - min) / (max - min)
			* (all->line.color2 % 65536 / 256 - all->line.color1 % 65536 /
			256) / 100;
		all->e.char_image[y * all->e.size_line + x * 4 + 2] =
			all->line.color1 % 16777216 / 65536 + 100 * (cur - min) *
			(all->line.color2 % 16777216 / 65536 - all->line.color1 %
			16777216 / 65536) / 100 / (max - min);
	}
}
