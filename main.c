/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 15:15:19 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 19:25:50 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char *argv[])
{
	t_all	all;
	int		ret;

	all.tab = NULL;
	if (argc > 1 && argc < 5)
	{
		all.size.len_x = -1;
		all.size.len_y = -1;
		all.size.min_z = 0;
		all.size.max_z = 0;
		all.size.scale_xy_ini = -1;
		if (argc > 2 && (ret = ft_atoi(argv[2])) > 0)
			all.size.scale_xy_ini = ret;
		all.size.scale_z_ini = -1;
		if (argc > 3 && (ret = ft_atoi(argv[3])) > 0)
			all.size.scale_z_ini = ret;
		if ((all.tab = ft_read(argv[1], &all)) == NULL)
			return (-1);
//		print_tab(tab, &size, 0);
		ret = display(&all, argv[1]);
		return (ret);
	}
	else
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	return (-1);
}
