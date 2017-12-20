/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 15:15:19 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 17:16:52 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char *argv[])
{
	t_all	all;
	int		ret;

	all.tab = NULL;
	if (argc > 1 && argc < 30)
	{
		all.size.len_x = -1;
		all.size.len_y = -1;
		all.size.min_z = 0;
		all.size.max_z = 0;
		all.size.scale_xy_ini = -1;
		all.size.color_tab = NULL;
		if (argc > 2 && (ret = ft_atoi(argv[2])) > 0)
			all.size.scale_xy_ini = ret;
		all.size.scale_z_ini = -1;
		if (argc > 3 && (ret = ft_atoi(argv[3])) > 0)
			all.size.scale_z_ini = ret;
		if (argc > 4)
			all.size.color_tab = color_palette(argc, argv, &all);
		if ((all.tab = ft_read(argv[1], &all)) == NULL)
			return (-1);
//		print_tab(&all, 0);
		ret = display(&all, argv[1]);
		return (ret);
	}
	else
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
}
