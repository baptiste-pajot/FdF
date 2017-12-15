/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   legend.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 12:18:04 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 19:28:17 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		display_seprarator(t_env e, int sep_width, int color)
{
	t_line	line_separator;

	line_separator.x1 = sep_width;
	line_separator.y1 = 0;
	line_separator.color1 = color;
	line_separator.x2 = line_separator.x1;
	line_separator.y2 = e.height - 1;
	line_separator.color2 = line_separator.color1;
	ft_line(e, line_separator);
	line_separator.x1 = 0;
	line_separator.y1 = e.height / 2;
	line_separator.x2 = sep_width;
	line_separator.y2 = line_separator.y1;
	ft_line(e, line_separator);
}

static void		display_file(t_env e, t_size size, int sep_width, int color_txt)
{
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 20, 20, color_txt,
		"FILE");
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 130, 2 * e.height / 20,
		color_txt, "name :");
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 60, 2 * e.height / 20,
		color_txt, e.name);
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 130, 3 * e.height / 20,
		color_txt, "len_x :");
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 40, 3 * e.height / 20,
		color_txt, ft_itoa(size.len_x));
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 130, 4 * e.height / 20,
		color_txt, "len_y :");
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 40, 4 * e.height / 20,
		color_txt, ft_itoa(size.len_y));
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 130, 5 * e.height / 20,
		color_txt, "max_z :");
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 40, 5 * e.height / 20,
		color_txt, ft_itoa(size.max_z));
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 130, 6 * e.height / 20,
		color_txt, "min_z :");
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 40, 6 * e.height / 20,
		color_txt, ft_itoa(size.min_z));
}

static void		display_view(t_env e, t_size size, int sep_width, int color_txt)
{
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 20, e.height / 2 + 20,
		color_txt, "VIEW");
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 130, 12 * e.height / 20,
		color_txt, "projection :");
	mlx_string_put(e.mlx, e.win, sep_width / 2, 12 * e.height / 20,
		color_txt, "iso");
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 130, 13 * e.height / 20,
		color_txt, "scale_xy :");
	mlx_string_put(e.mlx, e.win, sep_width / 2, 13 * e.height / 20,
		color_txt, ft_strjoin(ft_strjoin(ft_itoa(size.scale_xy), "."),
		ft_itoa((int)(size.scale_xy * 100) % 100)));
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 130, 14 * e.height / 20,
		color_txt, "scale_z :");
	mlx_string_put(e.mlx, e.win, sep_width / 2, 14 * e.height / 20,
		color_txt, ft_strjoin(ft_strjoin(ft_itoa(size.scale_z), "."),
		ft_itoa((int)(size.scale_z * 100) % 100)));
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 130, 15 * e.height / 20,
		color_txt, "center_x :");
	mlx_string_put(e.mlx, e.win, sep_width / 2, 15 * e.height / 20,
		color_txt, ft_itoa(size.center_x));
	mlx_string_put(e.mlx, e.win, sep_width / 2 - 130, 16 * e.height / 20,
		color_txt, "center_y :");
	mlx_string_put(e.mlx, e.win, sep_width / 2, 16 * e.height / 20,
		color_txt, ft_itoa(size.center_y));
}

void			display_legend(t_all *all)
{
	int		sep_width;

	sep_width = 300;
	display_seprarator(all->e, sep_width, 0xFFFFFF);
	display_file(all->e, all->size, sep_width, 0xFFFFFF);
	display_view(all->e, all->size, sep_width, 0xFFFFFF);
}
