/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 15:15:51 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 15:19:48 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
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
int				size_tab(int fd, t_all *all);
int				***make_tab(t_all *all);
int				***fill_tab(int fd, t_all *all);
int				display(t_all *all, char *name);
int				ft_line(t_all *all);
int				print_tab(t_all *all, int indice);
int				tab_proj(t_all *all);
void			display_legend(t_all *all);
void			display_legend_line(t_all *all);
void			display_seprarator(t_all *all, int color);
void			display_file(t_env e, t_size size, int color_txt);
void			display_view(t_env e, t_size size, int color_txt);
void			display_view2(t_env e, t_size size, int color_txt);
void			display_com(t_env e, int color_txt);
void			image_black(t_all *all);
int				*color_palette(int argc, char *argv[], t_all *all);
void			display_seprarator(t_all *all, int color);
void			fill_tab_color_palette(t_all *all);
void			mlx_pixel_image(t_all *all, int x, int y, int xory);
int				keyboard_funct(int keycode, t_all *all);
void			display_line(t_all *all);

#endif
