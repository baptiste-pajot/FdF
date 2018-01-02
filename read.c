/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 16:01:42 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 18:04:01 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include <stdio.h>
#include <unistd.h>

static int		size_tab(int fd, t_all *all)
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
	printf("len_x = %d\nlen_y = %d\n", all->size.len_x, all->size.len_y);
	return (0);
}

static int		***make_tab(t_all *all)
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

static int		***fill_tab(int fd, t_all *all)
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
	printf("max_z = %d\n", all->size.max_z);
	printf("min_z = %d\n", all->size.min_z);
	return (all->tab);
}

int				***ft_read(char *name, t_all *all)
{
	int		fd;

	if (name != NULL && ((fd = open(name, O_RDONLY)) > 2))
	{
		if (size_tab(fd, all) == -1)
			return (NULL);
		close(fd);
		if ((fd = open(name, O_RDONLY)) > 2)
		{
			if ((all->tab = make_tab(all)) == NULL)
			{
				ft_putstr("Impossible to build tab\n");
				return (NULL);
			}
			if ((all->tab = fill_tab(fd, all)) == NULL)
			{
				ft_putstr("Impossible to fill tab\n");
				return (NULL);
			}
			close(fd);
			if (all->size.color_tab != NULL)
				fill_tab_color_palette(all);
			return (all->tab);
		}
		else
			ft_putstr("Impossible to reopen file\n");
	}
	else
		ft_putstr(ft_strjoin(ft_strjoin("Impossible to open file \"", name),
			"\" \t This file exist ?\n"));
	return (NULL);
}
