/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 15:15:51 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 14:13:39 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define WIN_HEIGHT 1200;
# define WIN_WIDTH 2400;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		*name;
}				t_env;

typedef struct	s_size
{
	int			len_x;
	int			len_y;
	int			max_z;
	int			min_z;
	int			center_x;
	int			center_y;
	int			center_modify;
	double		scale_xy_ini;
	double		scale_xy;
	double		scale_z_ini;
	double		scale_z;
}				t_size;

typedef struct	s_ij
{
	int			i;
	int			j;
}				t_ij;

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
	t_size		*size;
	t_env		e;
	int			***tab;
}				t_all;

int				***ft_read(char *name, int ***tab, t_size *size);
int				display(int ***tab, t_size *size, char	*name);
int				ft_line(t_env e, t_line line);
int				print_tab(int ***tab, t_size *size, int indice);
void			tab_proj(int ***tab, t_size *size, t_env e);
void			tab_proj_ini(int ***tab, t_size *size, t_env e);
void			display_legend(t_env e, t_size *size);

#endif
