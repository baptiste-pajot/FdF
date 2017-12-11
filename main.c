/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 15:15:19 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 18:41:28 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char *argv[])
{
	int		***tab;
//	int		ret_read;
	t_size	size;

	tab = NULL;
	if (argc > 1 && argc < 4)
	{
		size.len_x = -1;
		size.len_y = -1;
		size.min_z = 0;
		size.max_z = 0;
		if ((tab = ft_read(argv[1], tab, &size)) == NULL)
			return (-1);
	}
	else
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	print_tab(tab, &size);
	display(&size);
	return (0);
}
