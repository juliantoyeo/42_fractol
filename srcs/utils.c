/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 07:57:52 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/17 07:57:54 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		rgb(int r, int g, int b)
{
	return ((r & 255) << 16) + ((g & 255) << 8) + (b & 255);
}

int		ft_back_to_normal(t_win *p)
{
	p->move.y = 0;
	p->move.x = 0;
	p->zoom = 1;
	p->c.re = 0;
	p->c.im = 0;
	p->adj = 0;
	p->iter = ITER;
	ft_redraw(p);
	return (0);
}

int		ft_redraw(t_win *p)
{
	ft_draw_fractol(p);
	if (p->opt == 1)
		ft_draw_option(p);
	return (0);
}

int		ft_free_exit(t_win *p)
{
	mlx_destroy_window(p->mlx, p->win);
	mlx_destroy_image(p->mlx, p->img.img);
	mlx_destroy_image(p->mlx, p->m.img);
	mlx_destroy_image(p->mlx, p->j.img);
	mlx_destroy_image(p->mlx, p->b.img);
	FREE(p);
	exit(0);
	return (0);
}
