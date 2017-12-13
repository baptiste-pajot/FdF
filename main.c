/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 15:15:19 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 10:45:24 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char *argv[])
{
	int		***tab;
	t_size	size;
	int		ret;

	tab = NULL;
	if (argc > 1 && argc < 5)
	{
		size.len_x = -1;
		size.len_y = -1;
		size.min_z = 0;
		size.max_z = 0;
		size.scale_xy = 10;
		if (argc > 2 && (ret = ft_atoi(argv[2])) > 0)
			size.scale_xy = ret;
		size.scale_z = 10;
		if (argc > 3 && (ret = ft_atoi(argv[3])) > 0)
			size.scale_z = ret;
		if ((tab = ft_read(argv[1], tab, &size)) == NULL)
			return (-1);
		print_tab(tab, &size, 0);
		ret = display(tab, &size);
		return (ret);
	}
	else
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	return (-1);
}
