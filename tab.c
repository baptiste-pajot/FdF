/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 13:41:56 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 18:34:45 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int				size_tab(int fd, t_all *all)
{
	char	*line;
	int		ret;
	int		i;

	all->size.len_y = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		i = ft_count_nb_words(line, ' ');
		if (all->size.len_x == -1)
			all->size.len_x = i;
		else if (all->size.len_x != i)
		{
			ft_putendl("Found wrong line length. Exiting");
			return (-1);
		}
		(all->size.len_y)++;
	}
	if (all->size.len_y > 200)
		ft_putendl("check size OK");
	return (0);
}

int				***make_tab(t_all *all)
{
	int		i;
	int		j;

	if (!(all->tab = (int***)ft_memalloc(sizeof(*(all->tab)) *
					(all->size.len_y))))
		return (NULL);
	i = -1;
	while (++i < all->size.len_y)
	{
		if (!(all->tab[i] = (int**)ft_memalloc(sizeof(**(all->tab)) *
						(all->size.len_x))))
			return (NULL);
		j = -1;
		while (++j < all->size.len_x)
		{
			if (!(all->tab[i][j] = (int*)ft_memalloc(sizeof(***(all->tab) *
								4))))
				return (NULL);
		}
	}
	if (all->size.len_y > 200)
		ft_putendl("tab creation OK");
	return (all->tab);
}

static void		fill_tab_conv(t_all *all, int i, int j, char **tab_txt)
{
	char	*p;

	all->tab[i][j][0] = ft_atoi(tab_txt[j]);
	if (all->size.color_tab == NULL)
	{
		if ((p = ft_strstr(tab_txt[j], ",0x")) != 0)
			all->tab[i][j][1] = ft_atoi_base(p + 3, 16);
		else if ((p = ft_strchr(tab_txt[j], ',')) != 0)
			all->tab[i][j][1] = ft_atoi(p);
		else
			all->tab[i][j][1] = 0xFFFFFF;
	}
	if (all->tab[i][j][0] > all->size.max_z)
		all->size.max_z = all->tab[i][j][0];
	if (all->tab[i][j][0] < all->size.min_z)
		all->size.min_z = all->tab[i][j][0];
	ft_memdel((void**)&tab_txt[j]);
}

int				***fill_tab(int fd, t_all *all)
{
	int		i;
	int		j;
	char	*line;
	char	**tab_txt;

	i = -1;
	while (++i < all->size.len_y)
	{
		if (get_next_line(fd, &line) < 0)
			return (NULL);
		tab_txt = ft_strsplit(line, ' ');
		j = -1;
		while (++j < all->size.len_x)
			fill_tab_conv(all, i, j, tab_txt);
	}
	ft_memdel((void**)&tab_txt);
	if (all->size.len_y > 200)
		ft_putendl("tab fill OK");
	return (all->tab);
}
