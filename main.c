/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 15:15:19 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 18:00:42 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		usage(void)
{
	ft_putstr("Usage : ./fdf <filename> [ xy_scale z_scale color0 color1");
	ft_putendl(" color2 ...]");
	ft_putendl("if just filename => scale auto && color in file");
	ft_putendl("if xyscale = -1 => xyscale auto ");
	ft_putendl("if yscale = -1 => zscale auto ");
	ft_putendl("if color0 = -1 => color auto, else 10 max colors");
	ft_putendl("if color0 = 0 => color auto for geographic map");
	ft_putendl("(blue if z <= 0  and other color for z > 0)");
	return (-1);
}

int				main(int argc, char *argv[])
{
	t_all	all;
	int		ret;

	all.tab = NULL;
	all.size.len_x = -1;
	all.size.len_y = -1;
	all.size.min_z = 0;
	all.size.max_z = 0;
	all.size.color_tab = NULL;
	all.size.scale_xy_ini = -1;
	all.size.scale_z_ini = -1;
	if (argc > 1 && argc < 30)
	{
		if (argc > 2 && (ret = ft_atoi(argv[2])) > 0 && ret <= 10000)
			all.size.scale_xy_ini = ret;
		if (argc > 3 && (ret = ft_atoi(argv[3])) > 0 && ret <= 10000)
			all.size.scale_z_ini = ret;
		if (argc > 4 && (color_palette(argc, argv, &all) < 0))
			return (-1);
		if ((all.tab = ft_read(argv[1], &all)) == NULL)
			return (-1);
		return (display(&all, argv[1]));
	}
	else
		return (usage());
}
