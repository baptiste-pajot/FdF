/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 16:30:10 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 17:34:32 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			*color_palette(int argc, char *argv[], t_all *all)
{
	int		i;
	char	*p;

	all->size.nb_color = 0;
	i = 3;
	if ((ft_atoi(argv[4])) < 0)
	{
		all->size.color_tab = (int*)ft_memalloc(sizeof(*(all->size.color_tab))
			* 4);
		all->size.color_tab[0] = 0x0000FF;
		all->size.color_tab[1] = 0x00FF00;
		all->size.color_tab[2] = 0x783F04;
		all->size.color_tab[3] = 0xFFFFFF;
		all->size.nb_color = 4;
	}
	else
	{
		while (++i < argc)
		{
			if (ft_atoi(argv[i]) >= 0)
				all->size.nb_color++;
			else
				i = argc;
		}
		i = 3;
		p = NULL;
		all->size.color_tab = (int*)ft_memalloc(sizeof(*(all->size.color_tab))
			* all->size.nb_color);
		while (++i < argc)
		{
			if ((p = ft_strstr(argv[i], "0x")) != NULL)
				all->size.color_tab[i - 4] = ft_atoi_base(p + 3, 16);
			else
				all->size.color_tab[i - 4] = ft_atoi(argv[i]);
		}
	}
	i = -1;
	while (++i < all->size.nb_color)
		printf("color%d = %d\n", i, all->size.color_tab[i]);
	return (all->size.color_tab);
}
