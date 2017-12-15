/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 17:49:06 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 18:46:37 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int				print_tab(t_all *all, int indice)
{
	int		i;
	int		j;

	ft_putstr("display tab[i][j][");
	ft_putnbr(indice);
	ft_putstr("] :\n");
	i = -1;
	while (++i < all->size.len_y)
	{
		j = -1;
		while (++j < all->size.len_x)
		{
			ft_putstr(" ");
			ft_putnbr(all->tab[i][j][indice]);
		}
		ft_putstr("\n");
	}
	ft_putstr("\n");
	return (0);
}
