/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   legend.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 12:18:04 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 11:23:34 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		display_seprarator(t_env e, int color)
{
	t_line	line_separator;

	line_separator.x1 = e.sep_width;
	line_separator.y1 = 0;
	line_separator.color1 = color;
	line_separator.x2 = line_separator.x1;
	line_separator.y2 = e.height - 1;
	line_separator.color2 = line_separator.color1;
	ft_line(e, line_separator);
	line_separator.x1 = 0;
	line_separator.y1 = e.height / 3;
	line_separator.x2 = e.sep_width;
	line_separator.y2 = line_separator.y1;
	ft_line(e, line_separator);
	line_separator.x1 = 0;
	line_separator.y1 = 2 * e.height / 3;
	line_separator.x2 = e.sep_width;
	line_separator.y2 = line_separator.y1;
	ft_line(e, line_separator);
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
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 20, e.height / 3 + 20,
		color_txt, "VIEW");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 12 * e.height / 30,
		color_txt, "projection :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2, 12 * e.height / 30,
		color_txt, "iso");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 13 * e.height / 30,
		color_txt, "scale_xy :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2, 13 * e.height / 30,
		color_txt, ft_strjoin(ft_strjoin(ft_itoa(size.scale_xy), "."),
		ft_itoa((int)(size.scale_xy * 100) % 100)));
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 14 * e.height / 30,
		color_txt, "scale_z :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2, 14 * e.height / 30,
		color_txt, ft_strjoin(ft_strjoin(ft_itoa(size.scale_z), "."),
		ft_itoa((int)(size.scale_z * 100) % 100)));
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 15 * e.height / 30,
		color_txt, "center_x :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2, 15 * e.height / 30,
		color_txt, ft_itoa(size.center_x));
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 16 * e.height / 30,
		color_txt, "center_y :");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2, 16 * e.height / 30,
		color_txt, ft_itoa(size.center_y));
}

static void		display_com(t_env e, int color_txt)
{
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 90, 2 * e.height / 3 + 20,
		color_txt, "KEYBOARD SHORTCUT");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 22 * e.height / 30,
		color_txt, "<- : left");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 23 * e.height / 30,
		color_txt, "-> : right");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 24 * e.height / 30,
		color_txt, "/|\\ : up");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 25 * e.height / 30,
		color_txt, "\\|/ : down");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 26 * e.height / 30,
		color_txt, "1(!) / 2(@) : zoom    -/+");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 27 * e.height / 30,
		color_txt, "3(#) / 4($) : zoom xy -/+");
	mlx_string_put(e.mlx, e.win, e.sep_width / 2 - 130, 28 * e.height / 30,
		color_txt, "5(%) / 6(^) : zoom z  -/+");
}

void			display_legend(t_all *all)
{
	display_seprarator(all->e, 0xFFFFFF);
	display_file(all->e, all->size, 0xFFFFFF);
	display_view(all->e, all->size, 0xFFFFFF);
	display_com(all->e, 0xFFFFFF);
}
