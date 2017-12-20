/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 11:12:33 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 19:21:25 by bpajot      ###    #+. /#+    ###.fr     */
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
	printf("bpp = %d\n", all->e.bpp);
	printf("size_line = %d\n", all->e.size_line);
	printf("endian = %d\n", all->e.endian);
	all->e.char_image = mlx_get_data_addr(all->e.image, &(all->e.bpp),
		&(all->e.size_line), &(all->e.endian));
	printf("bpp = %d\n", all->e.bpp);
	printf("size_line = %d\n", all->e.size_line);
	printf("endian = %d\n", all->e.endian);
}
