/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 16:01:42 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 19:36:16 by bpajot      ###    #+. /#+    ###.fr     */
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

static int		size_tab(int fd, int *len_x, int *len_y)
{
	char	*line;
	int		ret;
	int		i;

	*len_y = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		i = ft_count_nb_words(line, ' ');
		if (*len_x == -1)
			*len_x = i;
		else if (*len_x != i)
		{
			ft_putendl("Found wrong line length. Exiting");
			return (-1);
		}
		(*len_y)++;
	}
	printf("len_x = %d\nlen_y = %d\n", *len_x, *len_y);
	return (0);
}

static int		make_tab(int ***tab, int *len_x, int *len_y)
{
	int		i;
	int		j;

	if (!(tab = (int***)ft_memalloc(sizeof(*tab) * (*len_y))))
		return (-1);
	i = -1;
	while (++i < *len_y)
	{
		if (!(tab[i] = (int**)ft_memalloc(sizeof(**tab) * (*len_x))))
			return (-1);
		j = -1;
		while (++j < *len_x)
		{
			if (!(tab[i][j] = (int*)ft_memalloc(sizeof(***tab) * 2)))
				return (-1);
		}
	}
	return (0);
}

static int		fill_tab(int ***tab, int fd, int *len_x, int *len_y)
{
	char	*line;
	int		ret;
	char	**tab_txt;
	int		i;
	int		j;

	i = -1;
	while (++i < *len_y)
	{
		if ((ret = get_next_line(fd, &line)) < 0)
			return (-1);
		tab_txt = ft_strsplit(line, ' ');
		ft_putstr("OK");
		j = -1;
		while (++j < *len_x)
		{
			tab[i][j][0] = ft_atoi(tab_txt[j]);
			ft_memdel((void**)&tab_txt[j]);
		}
	}
	ft_memdel((void**)&tab_txt);
	return (0);
}

int				ft_read(char *name, int ***tab, int *len_x, int *len_y)
{
	int		fd;

	if (name != NULL)
	{
		if ((fd = open(name, O_RDONLY)) > 2)
		{
			if (size_tab(fd, len_x, len_y) == -1)
				return (-1);
			close(fd);
		}
		else
		{
			ft_putstr("Impossible to open file \"");
			ft_putstr(name);
			ft_putendl("\" \t This file exist ?");
		}
		if ((fd = open(name, O_RDONLY)) > 2)
		{
			if ((make_tab(tab, len_x, len_y) == -1) ||
					(fill_tab(tab, fd, len_x, len_y) == -1))
				return (-1);
			close(fd);
		}
	}
	return (0);
}
