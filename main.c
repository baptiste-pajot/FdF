/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 15:15:19 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 15:03:25 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char *argv[])
{
	int		***tab;
	int		ret_read;
	int		len_x;
	int		len_y;

	tab = NULL;
	if (argc > 1 && argc < 4)
	{
		len_x = -1;
		len_y = -1;
		if ((ret_read = ft_read(argv[1], tab, &len_x, &len_y)) < 0)
		{
			return (-1);
		}
	}
	else
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	display();
	return (0);
}
