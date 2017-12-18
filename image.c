/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 11:12:33 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 15:50:05 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		*new_image_black_back(t_all *all)
{
	void	*image;

	image = NULL;
	if (all->e.width >= 1000 && all->e.height >= 600)
		image = mlx_new_image(all->e.mlx, all->e.width - all->e.sep_width,
			all->e.height);
	else
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

/*static char		*image_string(void *image)
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*image_string;

	image_string = mlx_get_data_addr(image, &bpp, &size_line, &endian);
	return (image_string);
}
*/
void		image_black(t_all *all)
{
	all->e.image_black_back = new_image_black_back(all);
	all->e.image_black_legend = new_image_black_legend(all);
}
