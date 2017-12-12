/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 16:01:42 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 17:53:32 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include <stdio.h>
#include <unistd.h>

static size_t	ft_count_nb_words(char const *s, char c)
{
	size_t	i;
	size_t	nb_word;

	if (s != NULL && ft_strlen(s) > 0)
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (i == 0)
			{
				if (s[i] == c)
					nb_word = 0;
				else
					nb_word = 1;
			}
			else if ((s[i - 1] == c) && s[i] != c)
			{
				nb_word++;
			}
			i++;
		}
		return (nb_word);
	}
	return (0);
}

static int		size_tab(int fd, t_size *size)
{
	char	*line;
	int		ret;
	int		i;

	size->len_y = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		i = ft_count_nb_words(line, ' ');
		if (size->len_x == -1)
			size->len_x = i;
		else if (size->len_x != i)
		{
			ft_putendl("Found wrong line length. Exiting");
			return (-1);
		}
		(size->len_y)++;
	}
	printf("len_x = %d\nlen_y = %d\n", size->len_x, size->len_y);
	return (0);
}

static int		***make_tab(int ***tab, t_size *size)
{
	int		i;
	int		j;

	if (!(tab = (int***)ft_memalloc(sizeof(*tab) * (size->len_y))))
		return (NULL);
	i = -1;
	while (++i < size->len_y)
	{
		if (!(tab[i] = (int**)ft_memalloc(sizeof(**tab) * (size->len_x))))
			return (NULL);
		j = -1;
		while (++j < size->len_x)
		{
			if (!(tab[i][j] = (int*)ft_memalloc(sizeof(***tab) * 4)))
				return (NULL);
		}
	}
	return (tab);
}

static int		***fill_tab(int ***tab, int fd, t_size *size)
{
	char	*line;
	char	**tab_txt;
	int		i;
	int		j;

	i = -1;
	while (++i < size->len_y)
	{
		if (get_next_line(fd, &line) < 0)
			return (NULL);
		tab_txt = ft_strsplit(line, ' ');
		j = -1;
		while (++j < size->len_x)
		{
			tab[i][j][0] = ft_atoi(tab_txt[j]);
			tab[i][j][1] = 0xFFFFFF;
			if (tab[i][j][0] > size->max_z)
				size->max_z = tab[i][j][0];
			if (tab[i][j][0] < size->min_z)
				size->min_z = tab[i][j][0];
			ft_memdel((void**)&tab_txt[j]);
		}
	}
	ft_memdel((void**)&tab_txt);
	return (tab);
}

int				***ft_read(char *name, int ***tab, t_size *size)
{
	int		fd;

	if (name != NULL && ((fd = open(name, O_RDONLY)) > 2))
	{
		if (size_tab(fd, size) == -1)
			return (NULL);
		close(fd);
		if ((fd = open(name, O_RDONLY)) > 2)
		{
			if ((tab = make_tab(tab, size)) == NULL)
				return (NULL);
			if ((tab = fill_tab(tab, fd, size)) == NULL)
				return (NULL);
			close(fd);
			return (tab);
		}
	}
	else
	{
		ft_putstr("Impossible to open file \"");
		ft_putstr(name);
		ft_putendl("\" \t This file exist ?");
	}
	return (NULL);
}
