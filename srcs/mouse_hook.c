/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 08:11:46 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/17 08:11:47 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_option_color(int x, int y, t_win *p)
{
	p->i.click_x = x;
	if (x > p->col1.x && x < p->col1.max_x &&
		y > p->col1.y && y < p->col1.max_y)
		p->color_press = 1;
	else if (x > p->col2.x && x < p->col2.max_x &&
		y > p->col2.y && y < p->col2.max_y)
		p->color_press = 2;
	else if (x > p->col3.x && x < p->col3.max_x &&
		y > p->col3.y && y < p->col3.max_y)
		p->color_press = 3;
	else if (x > p->col4.x && x < p->col4.max_x &&
		y > p->col4.y && y < p->col4.max_y)
		p->color_press = 4;
	else
	{
		p->opt = 0;
		ft_redraw(p);
	}
	return (0);
}

static int	ft_option(int x, int y, t_win *p)
{
	if (x > p->opt1.x && x < p->opt1.max_x &&
		y > p->opt1.y && y < p->opt1.max_y)
	{
		p->bot = 0;
		ft_back_to_normal(p);
	}
	else if (x > p->opt2.x && x < p->opt2.max_x &&
		y > p->opt2.y && y < p->opt2.max_y)
	{
		p->bot = 1;
		ft_back_to_normal(p);
	}
	else if (x > p->opt3.x && x < p->opt3.max_x &&
		y > p->opt3.y && y < p->opt3.max_y)
	{
		p->bot = 2;
		ft_back_to_normal(p);
	}
	else
		ft_option_color(x, y, p);
	return (0);
}

int			mouse_hook(int bt, int x, int y, t_win *p)
{
	if (bt == 4 || bt == 5)
		ft_zoom(bt, x, y, p);
	if (bt == 2)
	{
		if (p->opt == 0)
			p->opt = 1;
		else
			p->opt = 0;
		ft_redraw(p);
	}
	if (bt == 1 && p->opt == 1)
		ft_option(x, y, p);
	if (bt == 1)
	{
		p->mouse_press = 1;
		p->i.click_x = x;
		p->i.click_y = y;
	}
	return (0);
}

int			mouse_hookup(int bt, int x, int y, t_win *p)
{
	x = 0;
	y = 0;
	if (bt == 1)
	{
		p->mouse_press = 0;
		if (p->opt == 1)
			p->color_press = 0;
	}
	return (0);
}
