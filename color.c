/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 16:30:10 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 18:48:47 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		color_palette2(int argc, char *argv[], t_all *all)
{
	char	*p;
	int		i;

	i = 3;
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) >= 0)
			all->size.nb_color++;
	}
	i = 3;
	p = NULL;
	all->size.color_tab = (int*)ft_memalloc(sizeof(*(all->size.color_tab))
		* all->size.nb_color);
	while (++i < argc)
	{
		if ((p = ft_strstr(argv[i], "0x")) != NULL)
			all->size.color_tab[i - 4] = ft_atoi_base(p + 2, 16);
		else
			all->size.color_tab[i - 4] = ft_atoi(argv[i]);
	}
}

int				*color_palette(int argc, char *argv[], t_all *all)
{
	int		i;

	all->size.nb_color = 0;
	i = 3;
	if (ft_atoi(argv[4]) <= 0 && ft_strstr(argv[4], "0x") == NULL)
	{
		all->size.color_tab = (int*)ft_memalloc(sizeof(*(all->size.color_tab))
			* 7);
		all->size.color_tab[0] = 0x0000FF;
		all->size.color_tab[1] = 0x00FF00;
		all->size.color_tab[2] = 0x008800;
		all->size.color_tab[3] = 0xA95906;
		all->size.color_tab[4] = 0x783F04;
		all->size.color_tab[5] = 0x8A8A8A;
		all->size.color_tab[6] = 0xFFFFFF;
		all->size.nb_color = 7;
		if (ft_atoi(argv[4]) == 0)
			all->size.nb_color = -1;
	}
	else
		color_palette2(argc, argv, all);
	return (all->size.color_tab);
}

static void		fill_tab_color_palette2(t_all *all, int i, int j)
{
	int		color_ind;

	if (all->size.nb_color < 0 && all->tab[i][j][0] <= 0)
		all->tab[i][j][1] = all->size.color_tab[0];
	else if (all->size.nb_color < 0 && all->size.max_z < 7)
		all->tab[i][j][1] = all->size.color_tab[all->tab[i][j][0]];
	else if (all->size.nb_color < 0)
	{
		color_ind = all->tab[i][j][0] * 6 / all->size.max_z;
		all->tab[i][j][1] = (color_ind == 6) ? all->size.color_tab[6] :
			all->size.color_tab[color_ind + 1];
	}
	else if (all->size.max_z - all->size.min_z < all->size.nb_color)
		all->tab[i][j][1] = all->size.color_tab[all->tab[i][j][0] -
			all->size.min_z];
	else
	{
		color_ind = (all->tab[i][j][0] - all->size.min_z) * all->size.nb_color
			/ (all->size.max_z - all->size.min_z);
		all->tab[i][j][1] = (color_ind == all->size.nb_color) ?
			all->size.color_tab[all->size.nb_color - 1] :
			all->size.color_tab[color_ind];
	}
}

void			fill_tab_color_palette(t_all *all)
{
	int		i;
	int		j;

	i = -1;
	while (++i < all->size.len_y)
	{
		j = -1;
		while (++j < all->size.len_x)
			fill_tab_color_palette2(all, i, j);
	}
}
