/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 16:01:42 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 17:13:49 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		***ft_read2(int fd, t_all *all)
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
	if (close(fd) < 0)
	{
		ft_putstr("Impossible to close fill\n");
		return (NULL);
	}
	if (all->size.color_tab != NULL)
		fill_tab_color_palette(all);
	return (all->tab);
}

int				***ft_read(char *name, t_all *all)
{
	int		fd;

	if (name != NULL && ((fd = open(name, O_RDONLY)) > 2))
	{
		if (size_tab(fd, all) == -1)
			return (NULL);
		if (close(fd) < 0)
		{
			ft_putstr("Impossible to close fill\n");
			return (NULL);
		}
		if ((fd = open(name, O_RDONLY)) > 2)
			return (ft_read2(fd, all));
		else
			ft_putstr("Impossible to reopen file\n");
	}
	else
		ft_putstr(ft_strjoin(ft_strjoin("Impossible to open file \"", name),
			"\" \t This file exist ?\n"));
	return (NULL);
}
