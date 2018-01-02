/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   legend.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 12:18:04 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 15:33:25 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		display_seprarator(t_all *all, int color)
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

static void		display_file(t_env e, t_size size, int color_txt)
{
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 20, 20, color_txt,
		"FILE");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 2 * e.height / 30,
		color_txt, "name :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 60, 2 * e.height / 30,
		color_txt, e.name);
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 3 * e.height / 30,
		color_txt, "len_x :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 40, 3 * e.height / 30,
		color_txt, ft_itoa(size.len_x));
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 4 * e.height / 30,
		color_txt, "len_y :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 40, 4 * e.height / 30,
		color_txt, ft_itoa(size.len_y));
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 5 * e.height / 30,
		color_txt, "max_z :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 40, 5 * e.height / 30,
		color_txt, ft_itoa(size.max_z));
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 6 * e.height / 30,
		color_txt, "min_z :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 40, 6 * e.height / 30,
		color_txt, ft_itoa(size.min_z));
}

static void		display_view(t_env e, t_size size, int color_txt)
{
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 20, 7 * e.height / 30 + 20,
		color_txt, "VIEW");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 9 * e.height / 30,
		color_txt, "projection :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2, 9 * e.height / 30,
		color_txt, "iso");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 10 * e.height / 30,
		color_txt, "scale_xy :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2, 10 * e.height / 30,
		color_txt, ft_strjoin(ft_strjoin(ft_itoa(size.scale_xy), "."),
		ft_itoa((int)(size.scale_xy * 100) % 100)));
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 11 * e.height / 30,
		color_txt, "scale_z :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2, 11 * e.height / 30,
		color_txt, ft_strjoin(ft_strjoin(ft_itoa(size.scale_z), "."),
		ft_itoa((int)(size.scale_z * 100) % 100)));
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 12 * e.height / 30,
		color_txt, "center_x :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2, 12 * e.height / 30,
		color_txt, ft_itoa(size.center_x));
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 13 * e.height / 30,
		color_txt, "center_y :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2, 13 * e.height / 30,
		color_txt, ft_itoa(size.center_y));
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 14 * e.height / 30,
		color_txt, "rot_z :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 40, 14 * e.height / 30,
		color_txt, ft_itoa(size.rot_z));
}

static void		display_com(t_env e, int color_txt)
{
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 90, 16 * e.height / 30 + 20,
		color_txt, "KEYBOARD SHORTCUT");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 18 * e.height / 30,
		color_txt, "<- : left");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 19 * e.height / 30,
		color_txt, "-> : right");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 20 * e.height / 30,
		color_txt, "/|\\ : up");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 21 * e.height / 30,
		color_txt, "\\|/ : down");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 22 * e.height / 30,
		color_txt, "1(!) / 2(@) : zoom     -/+");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 23 * e.height / 30,
		color_txt, "3(#) / 4($) : zoom xy  -/+");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 24 * e.height / 30,
		color_txt, "5(%) / 6(^) : zoom z   -/+");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 25 * e.height / 30,
		color_txt, "7(&) / 8(*) : rotate z -/+");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 28 * e.height / 30,
		color_txt, "Esc or Q : Close Window");
}

void			display_legend_line(t_all *all)
{
	display_seprarator(all, 0xFFFFFF);
}

void			display_legend(t_all *all)
{
	display_seprarator(all, 0xFFFFFF);
	display_file(all->e, all->size, 0xFFFFFF);
	display_view(all->e, all->size, 0xFFFFFF);
	display_com(all->e, 0xFFFFFF);
}
