/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keyboard.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 15:17:23 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 18:08:14 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		keyboard_funct2(int keycode, t_all *all)
{
	if (keycode == 126 && all->size.center_y >= -10000)
		all->size.center_y -= 50;
	if (keycode == 125 && all->size.center_y <= 10000)
		all->size.center_y += 50;
	if (keycode == 123 && all->size.center_x >= -10000)
		all->size.center_x -= 50;
	if (keycode == 124 && all->size.center_x <= 10000)
		all->size.center_x += 50;
	if ((keycode == 20 || keycode == 18) && all->size.scale_xy >= 0.00001)
		all->size.scale_xy /= 1.2;
	if ((keycode == 21 || keycode == 19) && all->size.scale_xy <= 10000)
		all->size.scale_xy *= 1.2;
	if ((keycode == 23 || keycode == 18) && all->size.scale_xy >= 0.00001)
		all->size.scale_z /= 1.2;
	if ((keycode == 22 || keycode == 19) && all->size.scale_xy <= 10000)
		all->size.scale_z *= 1.2;
	if (keycode == 26)
		all->size.rot_z = (all->size.rot_z > -180) ? all->size.rot_z - 10 : 170;
	if (keycode == 28)
		all->size.rot_z = (all->size.rot_z < 180) ? all->size.rot_z + 10 :
			-170;
}

static void		free_tab(t_all *all)
{
	int		i;
	int		j;

	mlx_destroy_image(all->e.mlx, all->e.image);
	mlx_destroy_image(all->e.mlx, all->e.image_black_legend);
	ft_memdel((void**)&all->size.color_tab);
	i = -1;
	while (++i < all->size.len_y)
	{
		j = -1;
		while (++j < all->size.len_x)
			ft_memdel((void**)&all->tab[i][j]);
		ft_memdel((void**)&all->tab[i]);
	}
	ft_memdel((void**)&all->tab);
}

int				keyboard_funct(int keycode, t_all *all)
{
	if (keycode == 53 || keycode == 12)
	{
		free_tab(all);
		exit(0);
	}
	if ((keycode >= 123 && keycode <= 126) || (keycode >= 18 && keycode <= 23)
			|| keycode == 26 || keycode == 28)
	{
		keyboard_funct2(keycode, all);
		all->size.modify = 1;
		tab_proj(all);
		ft_bzero(all->e.char_image, all->e.size_line * all->e.height - 1);
		display_line(all);
		display_frame(all);
		mlx_put_image_to_window(all->e.mlx, all->e.win, all->e.image, 0, 0);
		if (all->e.width >= 1000 && all->e.height >= 600)
		{
			mlx_put_image_to_window(all->e.mlx, all->e.win,
					all->e.image_black_legend, 0, 0);
			display_legend(all);
		}
	}
	return (0);
}
