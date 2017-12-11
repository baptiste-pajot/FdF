/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 17:49:06 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 18:41:57 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int				print_tab(int ***tab, t_size *size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size->len_y)
	{
		j = -1;
		while (++j < size->len_x)
		{
			ft_putstr(" ");
			ft_putnbr(tab[i][j][0]);
		}
		ft_putstr("\n");
	}
	return (0);
}
