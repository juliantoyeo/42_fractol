/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 08:39:43 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/17 08:39:44 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_option(int x, int y, t_win *p)
{
	if (x > p->opt1.x && x < p->opt1.max_x &&
		y > p->opt1.y && y < p->opt1.max_y)
	{
		ft_redraw(p);
		mlx_put_image_to_window(p->mlx, p->win, p->m.img,
			p->opt1.x + 50, p->opt1.y);
	}
	else if (x > p->opt2.x && x < p->opt2.max_x &&
		y > p->opt2.y && y < p->opt2.max_y)
	{
		ft_redraw(p);
		mlx_put_image_to_window(p->mlx, p->win, p->j.img,
			p->opt2.x + 50, p->opt2.y);
	}
	else if (x > p->opt3.x && x < p->opt3.max_x &&
		y > p->opt3.y && y < p->opt3.max_y)
	{
		ft_redraw(p);
		mlx_put_image_to_window(p->mlx, p->win, p->b.img,
			p->opt3.x + 50, p->opt3.y);
	}
	return (0);
}

static int	ft_change(t_win *p)
{
	if (p->color_press == 1)
		p->col.r = (p->col1.x - (p->col_x));
	else if (p->color_press == 2)
		p->col.g = (p->col2.x - (p->col_x));
	else if (p->color_press == 3)
		p->col.b = (p->col3.x - (p->col_x));
	else if (p->color_press == 4)
		p->col.l = ((double)p->col4.x - (double)(p->col_x)) / 100;
	return (0);
}

static int	ft_color_press(int x, t_win *p)
{
	t_opt	*col;

	col = NULL;
	if (p->color_press == 1)
		col = &p->col1;
	else if (p->color_press == 2)
		col = &p->col2;
	else if (p->color_press == 3)
		col = &p->col3;
	else if (p->color_press == 4)
		col = &p->col4;
	p->i.x = (x - p->i.click_x);
	if (((*col).x + p->i.x) < p->col_x)
		(*col).x = p->col_x;
	else if (((*col).x + p->i.x) > (p->col_x + 255))
		(*col).x = p->col_x + 255;
	else
		(*col).x += p->i.x;
	ft_change(p);
	ft_redraw(p);
	p->i.click_x = x;
	return (0);
}

int			mouse_move(int x, int y, t_win *p)
{
	if (p->opt == 1)
		ft_option(x, y, p);
	if (p->color_press != 0)
		ft_color_press(x, p);
	if (p->mouse_press == 1 && p->color_press == 0)
	{
		p->i.x = (x - p->i.click_x);
		p->i.y = (y - p->i.click_y);
		p->move.x -= (p->i.x / p->zoom) / 200;
		p->move.y -= (p->i.y / p->zoom) / 200;
		ft_redraw(p);
		p->i.click_x = x;
		p->i.click_y = y;
	}
	if (p->mouse_lock == 0 && p->bot == 1 && p->opt == 0)
	{
		p->c.re = (x - p->c_x) * 0.003;
		p->c.im = (y - p->c_y) * 0.002;
		ft_redraw(p);
	}
	return (0);
}
