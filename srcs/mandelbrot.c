/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 09:04:47 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/17 09:04:50 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_fill(int inside, double bright, t_point cor, t_thr *t)
{
	if (!(inside))
	{
		t->img.i_data[cor.y * t->p->x + cor.x] =
		rgb(bright * t->p->col.r, bright * t->p->col.g, bright * t->p->col.b);
	}
	else
		t->img.i_data[cor.y * t->p->x + cor.x] = 0x0;
	return (0);
}

static int	ft_iter(t_thr *t, t_bot new, t_bot pix, t_point cor)
{
	int			i;
	int			inside;
	int			max;
	double		bright;
	t_bot		old;

	i = 0;
	inside = 1;
	max = t->p->iter;
	while (i < max)
	{
		old.re = new.re;
		old.im = new.im;
		new.re = old.re * old.re - old.im * old.im + pix.re;
		new.im = 2 * old.re * old.im + pix.im;
		if ((new.re * new.re + new.im * new.im) > 4)
		{
			inside = 0;
			break ;
		}
		i++;
	}
	bright = ((double)i / max * t->p->col.l);
	ft_fill(inside, bright, cor, t);
	return (0);
}

static int	ft_mandel(t_thr *t, t_point cor, t_double zoom, t_double move)
{
	t_bot		pix;
	t_bot		new;

	cor.x = 0;
	while (cor.x < t->p->x)
	{
		pix.re = (cor.x - t->p->x / 2) / zoom.x + move.x;
		pix.im = (cor.y - t->p->y / 2) / zoom.y + move.y;
		new.re = 0;
		new.im = 0;
		ft_iter(t, new, pix, cor);
		cor.x++;
	}
	return (0);
}

void		*mandel_thr(void *arg)
{
	t_thr		*t;
	t_double	move;
	t_double	zoom;
	t_point		cor;

	t = (t_thr *)arg;
	move.x = -0.5 + t->p->move.x;
	move.y = 0 + t->p->move.y;
	zoom.x = 0.334 * t->p->zoom * t->p->x;
	zoom.y = 0.334 * t->p->zoom * t->p->y;
	cor.y = t->y;
	while (cor.y < t->y_max)
	{
		ft_mandel(t, cor, zoom, move);
		cor.y++;
	}
	return (NULL);
}
