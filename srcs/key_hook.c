/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 07:55:41 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/17 07:55:43 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_move(t_win *p, int keycode)
{
	if (keycode == 126)
		p->move.y -= 1 / p->zoom;
	if (keycode == 125)
		p->move.y += 1 / p->zoom;
	if (keycode == 124)
		p->move.x += 1 / p->zoom;
	if (keycode == 123)
		p->move.x -= 1 / p->zoom;
	ft_redraw(p);
	return (0);
}

int			key_hook(int keycode, t_win *p)
{
	if (keycode == 53 || keycode == 82)
		ft_free_exit(p);
	if (keycode == 8)
		ft_back_to_normal(p);
	if (keycode == 49)
	{
		if (p->mouse_lock == 0)
			p->mouse_lock = 1;
		else
			p->mouse_lock = 0;
	}
	if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
		ft_move(p, keycode);
	if (keycode == 31)
	{
		if (p->opt == 0)
			p->opt = 1;
		else
			p->opt = 0;
		ft_redraw(p);
	}
	return (0);
}
