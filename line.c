/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 17:30:49 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 18:53:29 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_color(t_line line, int min, int max, int x)
{
	int		red;
	int		green;
	int		blue;

	if (line.color1 == line.color2 || min == max)
		return (line.color1);
	else
	{
		red = line.color1 % 16777216 / 65536 + 100 * (x - min) / (max - min) *
			(line.color2 % 16777216 / 65536 - line.color1 % 16777216 / 65536)
			/ 100;
		green = line.color1 % 65536 / 256 + 100 * (x - min) / (max - min) *
			(line.color2 % 65536 / 256 - line.color1 % 65536 / 256) / 100;
		blue = line.color1 % 256 + 100 * (x - min) / (max - min) *
			(line.color2 % 256 - line.color1 % 256) / 100;
		return (red * 65536 + green * 256 + blue);
	}
}

static int		ft_line2(t_env e, t_line line)
{
	int		x;

	if (line.x1 > line.x2)
	{
		ft_swap(&line.x1, &line.x2);
		ft_swap(&line.y1, &line.y2);
	}
	if (line.y1 != line.y2)
	{
		x = line.x1 - 1;
		while (++x <= line.x2)
			mlx_pixel_put(e.mlx, e.win, x, line.y1 + (line.y2 - line.y1) *
				(x - line.x1) / (line.x2 - line.x1), ft_color(line, line.x1,
				line.x2, x));
	}
	else
	{
		x = line.x1 - 1;
		while (++x <= line.x2)
			mlx_pixel_put(e.mlx, e.win, x, line.y1, ft_color(line, line.x1,
				line.x2, x));
	}
	return (0);
}

static int		ft_line1(t_env e, t_line line)
{
	int		y;

	if (line.y1 > line.y2)
	{
		ft_swap(&line.y1, &line.y2);
		ft_swap(&line.x1, &line.x2);
	}
	if (line.x1 != line.x2)
	{
		y = line.y1 - 1;
		while (++y <= line.y2)
			mlx_pixel_put(e.mlx, e.win, line.x1 + (line.x2 - line.x1) *
				(y - line.y1) / (line.y2 - line.y1), y, ft_color(line, line.y1,
				line.y2, y));
	}
	else
	{
		y = line.y1 - 1;
		while (++y <= line.y2)
			mlx_pixel_put(e.mlx, e.win, line.x1, y, ft_color(line, line.y1,
				line.y2, y));
	}
	return (0);
}

int				ft_line(t_env e, t_line line)
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
