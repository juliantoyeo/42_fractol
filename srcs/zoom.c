/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 08:30:43 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/17 08:30:51 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		ft_zoom_in(t_double inc, double mag, t_win *p)
{
	p->zoom = p->zoom * 1.1;
	p->iter += 3;
	p->adj += 0.01;
	p->adj_spd.x = fabs((20 - p->adj) - (mag / ((p->x / 25) + p->adj)));
	p->adj_spd.y = fabs((20 - p->adj) - (mag / ((p->y / 25) + p->adj)));
	p->move.y += (inc.y / p->zoom) / p->adj_spd.x;
	p->move.x += (inc.x / p->zoom) / p->adj_spd.y;
	return (0);
}

static int		ft_zoom_out(t_double inc, double mag, t_win *p)
{
	p->zoom = p->zoom / 1.1;
	p->iter -= 3;
	p->adj -= 0.01;
	p->adj_spd.x = fabs((20 - p->adj) - (mag / ((p->x / 25) + p->adj)));
	p->adj_spd.y = fabs((20 - p->adj) - (mag / ((p->y / 25) + p->adj)));
	p->move.y -= (inc.y / p->zoom) / p->adj_spd.x;
	p->move.x -= (inc.x / p->zoom) / p->adj_spd.y;
	return (0);
}

int				ft_zoom(int bt, int x, int y, t_win *p)
{
	t_double	v;
	t_double	inc;
	double		mag;

	p->mouse.x = x;
	p->mouse.y = y;
	v.x = x - p->c_x;
	v.y = y - p->c_y;
	mag = sqrt((v.x * v.x) + (v.y * v.y));
	inc.x = v.x / mag;
	inc.y = v.y / mag;
	if (bt == 4)
		ft_zoom_in(inc, mag, p);
	if (bt == 5)
		ft_zoom_out(inc, mag, p);
	ft_redraw(p);
	return (0);
}
