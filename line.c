/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 16:26:06 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 16:26:40 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_line2(t_env e, t_line line)
{
	int		y;

	if (line.y1 > line.y2 || (line.y1 == line.y2 && line.x1 > line.x2))
		ft_swap(&line.x1, &line.x2);
	if (line.y1 > line.y2)
		ft_swap(&line.y1, &line.y2);
	if (line.y1 != line.y2)
	{
		y = line.y1 - 1;
		while (++y <= line.y2)
			mlx_pixel_put(e.mlx, e.win, line.x1 + (line.x2 - line.x1)
				* (y - line.y1) / (line.y2 - line.y1), y, line.color1);
	}
	else
	{
		y = line.x1 - 1;
		while (++y <= line.x2)
			mlx_pixel_put(e.mlx, e.win, y, line.y1, line.color1);
	}
	return (0);
}

static int		ft_line1(t_env e, t_line line)
{
	int		x;

	if (line.x1 > line.x2 || (line.x1 == line.x2 && line.y1 > line.y2))
		ft_swap(&line.y1, &line.y2);
	if (line.x1 > line.x2)
		ft_swap(&line.x1, &line.x2);
	if (line.x1 != line.x2)
	{
		x = line.x1 - 1;
		while (++x <= line.x2)
			mlx_pixel_put(e.mlx, e.win, x, line.y1 + (line.y2 - line.y1)
					* (x - line.x1) / (line.x2 - line.x1), line.color1);
	}
	else
	{
		x = line.y1 - 1;
		while (++x <= line.y2)
			mlx_pixel_put(e.mlx, e.win, line.x1, x, line.color1);
	}
	return (0);
}

int		ft_line(t_env e, t_line line)
{
	int		delta_x;
	int		delta_y;

	if ((line.x2 - line.x1) >= 0)
		delta_x = line.x2 - line.x1;
	else
		delta_x = line.x1 - line.x2;
	if ((line.y2 - line.y1) >= 0)
		delta_y = line.y2 - line.y1;
	else
		delta_y = line.y1 - line.y2;
	if (delta_x <= delta_y)
		ft_line1(e, line);
	else
		ft_line2(e, line);
	return (0);
}
