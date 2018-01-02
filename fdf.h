/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 15:15:51 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 15:36:25 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define W_HEIGHT 1200
# define W_WIDTH 2400

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			sep_width;
	char		*name;
	void		*image_black_legend;
	void		*image;
	char		*char_image;
	char		*char_legend;
	int			bpp;
	int			size_line;
	int			endian;
}				t_env;

typedef struct	s_size
{
	int			len_x;
	int			len_y;
	int			max_z;
	int			min_z;
	int			center_x;
	int			center_y;
	int			modify;
	double		scale_xy_ini;
	double		scale_xy;
	double		scale_z_ini;
	double		scale_z;
	int			rot_z;
	int			nb_color;
	int			*color_tab;
}				t_size;

typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			color1;
	int			color2;
}				t_line;

typedef struct	s_all
{
	t_size		size;
	t_env		e;
	int			***tab;
	t_line		line;
}				t_all;

int				***ft_read(char *name, t_all *all);
int				display(t_all *all, char *name);
int				ft_line(t_all *all, int imorleg);
int				print_tab(t_all *all, int indice);
void			tab_proj(t_all *all);
void			display_legend(t_all *all);
void			display_legend_line(t_all *all);
void			image_black(t_all *all);
int				*color_palette(int argc, char *argv[], t_all *all);

#endif
