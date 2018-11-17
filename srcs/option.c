/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 07:59:53 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/17 07:59:55 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_draw_box(t_win *p, t_opt *opt, char *str)
{
	int		x;
	int		y;
	int		n_x;
	int		n_y;
	int		color;

	x = 0;
	n_x = (*opt).x;
	n_y = (*opt).y;
	color = rgb(p->col.r, p->col.g, p->col.b);
	while (x < 150)
	{
		y = 0;
		while (y < 50)
			mlx_pixel_put(p->mlx, p->win, n_x + x, n_y + y++, color);
		x++;
	}
	(*opt).max_x = n_x + x;
	(*opt).max_y = n_y + y;
	mlx_string_put(p->mlx, p->win, n_x + 10, n_y + 12, rgb(50, 50, 50), str);
	return (0);
}

static int	get_color(int *color, char c)
{
	if (c == 'R')
		(*color) = rgb(255, 100, 100);
	else if (c == 'G')
		(*color) = rgb(100, 255, 100);
	else if (c == 'B')
		(*color) = rgb(100, 100, 255);
	else if (c == 'L')
		(*color) = rgb(255, 255, 255);
	return (0);
}

static int	ft_draw_rgb(t_win *p, t_opt *col, char *str)
{
	int		x;
	int		y;
	int		n_x;
	int		n_y;
	int		color;

	x = 0;
	n_x = (*col).x;
	n_y = (*col).y;
	get_color(&color, *str);
	while (x++ < 255)
		mlx_pixel_put(p->mlx, p->win, p->col_x + x, n_y + 10, color);
	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 20)
			mlx_pixel_put(p->mlx, p->win, n_x + x, n_y + y++, color);
		x++;
	}
	(*col).max_x = n_x + x;
	(*col).max_y = n_y + y;
	mlx_string_put(p->mlx, p->win, p->col_x - 20, n_y, color, str);
	return (0);
}

int			ft_draw_option(t_win *p)
{
	p->opt1.x = p->x / 10;
	p->opt1.y = p->y / 10;
	ft_draw_box(p, &p->opt1, "Mandelbrot");
	p->opt2.x = p->x / 10;
	p->opt2.y = p->opt1.max_y + 10;
	ft_draw_box(p, &p->opt2, "Julia");
	p->opt3.x = p->x / 10;
	p->opt3.y = p->opt2.max_y + 10;
	ft_draw_box(p, &p->opt3, "Burning ship");
	p->col1.y = p->y / 1.3;
	ft_draw_rgb(p, &p->col1, "R");
	p->col2.y = p->col1.max_y + 10;
	ft_draw_rgb(p, &p->col2, "G");
	p->col3.y = p->col2.max_y + 10;
	ft_draw_rgb(p, &p->col3, "B");
	p->col4.y = p->col3.max_y + 10;
	ft_draw_rgb(p, &p->col4, "L");
	return (0);
}
