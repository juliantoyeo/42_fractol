/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 09:34:06 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/17 09:34:08 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			ft_preview(t_win *p, t_img *img, int bot)
{
	t_thr		t;

	(*img).img = mlx_new_image(p->mlx, p->c_x / 2, p->c_y / 2);
	(*img).i_data = (int *)mlx_get_data_addr((*img).img, &((*img).bp),
		&((*img).sl), &((*img).edn));
	t.p = p;
	t.p->x = p->c_x / 2;
	t.p->y = p->c_y / 2;
	t.p->c.re = -0.726;
	t.p->c.im = 0.27015;
	t.y = 0;
	t.y_max = p->c_y / 2;
	t.img = (*img);
	if (bot == 0)
		mandel_thr(&t);
	else if (bot == 1)
		julia_thr(&t);
	else if (bot == 2)
		ship_thr(&t);
	t.p->x = p->c_x * 2;
	t.p->y = p->c_y * 2;
	t.p->c.re = 0;
	t.p->c.im = 0;
	return (0);
}

int			ft_draw_fractol(t_win *p)
{
	int			i;
	pthread_t	thr[THREADS];
	t_thr		t[THREADS];

	i = 0;
	while (i < THREADS)
	{
		t[i].p = p;
		t[i].y = i * ((p->y / THREADS));
		t[i].y_max = (i + 1) * (p->y / THREADS);
		t[i].img = p->img;
		if (p->bot == 0)
			pthread_create(&thr[i], NULL, mandel_thr, &t[i]);
		else if (p->bot == 1)
			pthread_create(&thr[i], NULL, julia_thr, &t[i]);
		else if (p->bot == 2)
			pthread_create(&thr[i], NULL, ship_thr, &t[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(thr[i++], NULL);
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
	return (0);
}
