/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keyboard.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 15:17:23 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 17:07:40 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		keyboard_funct2(int keycode, t_all *all)
{
	if (keycode == 126)
		all->size.center_y -= 50;
	if (keycode == 125)
		all->size.center_y += 50;
	if (keycode == 123)
		all->size.center_x -= 50;
	if (keycode == 124)
		all->size.center_x += 50;
	if (keycode == 20 || keycode == 18)
		all->size.scale_xy /= 1.2;
	if (keycode == 21 || keycode == 19)
		all->size.scale_xy *= 1.2;
	if (keycode == 23 || keycode == 18)
		all->size.scale_z /= 1.2;
	if (keycode == 22 || keycode == 19)
		all->size.scale_z *= 1.2;
	if (keycode == 26)
		all->size.rot_z = (all->size.rot_z > -180) ? all->size.rot_z - 10 : 170;
	if (keycode == 28)
		all->size.rot_z = (all->size.rot_z < 180) ? all->size.rot_z + 10 :
			-170;
}

int				keyboard_funct(int keycode, t_all *all)
{
	if (keycode == 53 || keycode == 12)
		exit(0);
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
