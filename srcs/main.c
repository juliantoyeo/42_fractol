/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:14:36 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/11 18:14:38 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_init_2(t_win **p)
{
	(*p)->opt = 0;
	(*p)->iter = ITER;
	(*p)->mouse_lock = 0;
	(*p)->zoom = 1;
	(*p)->adj = 0.0;
	(*p)->c.re = 0;
	(*p)->c.im = 0;
	(*p)->move.x = 0;
	(*p)->move.y = 0;
	(*p)->mouse.x = 0;
	(*p)->mouse.y = 0;
	(*p)->col.r = RED;
	(*p)->col.g = GREEN;
	(*p)->col.b = BLUE;
	(*p)->col.l = BRIGHT;
	(*p)->col_x = (*p)->x / 10;
	(*p)->col1.x = (*p)->col_x + (*p)->col.r;
	(*p)->col2.x = (*p)->col_x + (*p)->col.g;
	(*p)->col3.x = (*p)->col_x + (*p)->col.b;
	(*p)->col4.x = (*p)->col_x + (*p)->col.l + 104;
	return (0);
}

static int	ft_init(t_win **p, char **av)
{
	ERROR((*p = (t_win *)malloc(sizeof(t_win))) == NULL, -1);
	(*p)->x = ft_atoi(av[1]);
	(*p)->y = ft_atoi(av[2]);
	(*p)->c_x = (*p)->x / 2;
	(*p)->c_y = (*p)->y / 2;
	(*p)->mlx = mlx_init();
	(*p)->win = mlx_new_window((*p)->mlx, (*p)->x, (*p)->y, "fractol");
	(*p)->img.img = mlx_new_image((*p)->mlx, (*p)->x, (*p)->y);
	(*p)->img.i_data = (int *)mlx_get_data_addr((*p)->img.img, &((*p)->img.bp),
		&((*p)->img.sl), &((*p)->img.edn));
	if (ft_strcmp(av[0], "Mandelbrot") == 0)
		(*p)->bot = 0;
	else if (ft_strcmp(av[0], "Julia") == 0)
		(*p)->bot = 1;
	else if (ft_strcmp(av[0], "Burning_ship") == 0)
		(*p)->bot = 2;
	ft_init_2(p);
	ft_preview((*p), &(*p)->m, 0);
	ft_preview((*p), &(*p)->j, 1);
	ft_preview((*p), &(*p)->b, 2);
	return (0);
}

static int	ft_check(int ac, char **av)
{
	if (ac == 1 || ac == 2)
	{
		av[1] = "1000";
		av[2] = "1000";
	}
	if (ac == 0 || ac > 3 || (ft_strcmp(av[0], "Mandelbrot") != 0 &&
		ft_strcmp(av[0], "Julia") != 0 &&
		ft_strcmp(av[0], "Burning_ship") != 0) || ft_valid_int(av[1]) != 0
		|| ft_valid_int(av[2]) != 0 || ft_atoi(av[1]) > 3000
		|| ft_atoi(av[2]) > 3000 || ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0)
	{
		ft_printf("usage : ./fractol [fractol]\nfractols :\n");
		ft_printf("\tMandelbrot\n");
		ft_printf("\tJulia\n");
		ft_printf("\tBurning_ship\n");
		ft_printf("or\n\t./fractol [fractol] [width] [height]\n");
		ft_printf("\tdefault width = 1000 height = 1000\n");
		return (-1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_win	*p;

	ac--;
	av++;
	if ((ft_check(ac, av)) == -1)
		return (0);
	ERROR(ft_init(&p, av) == -1, 0);
	ft_draw_fractol(p);
	mlx_key_hook(p->win, key_hook, (void *)p);
	mlx_mouse_hook(p->win, mouse_hook, (void *)p);
	mlx_hook(p->win, 5, 1L << 3, mouse_hookup, (void *)p);
	mlx_hook(p->win, 6, 1L << 6, mouse_move, (void *)p);
	mlx_hook(p->win, 17, 1L << 17, ft_free_exit, (void *)p);
	mlx_loop(p->mlx);
	return (0);
}
