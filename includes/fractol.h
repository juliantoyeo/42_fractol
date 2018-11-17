/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:14:20 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/11 18:14:22 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include <math.h>
# include <pthread.h>
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# define THREADS 16
# define ITER 50
# define RED 255
# define GREEN 255
# define BLUE 255
# define BRIGHT 1.0

typedef	struct		s_move
{
	int				x;
	int				y;
	int				click_x;
	int				click_y;
}					t_move;

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef	struct		s_double
{
	double			x;
	double			y;
}					t_double;

typedef	struct		s_bot
{
	double			re;
	double			im;
}					t_bot;

typedef	struct		s_opt
{
	int				x;
	int				y;
	int				max_x;
	int				max_y;
}					t_opt;

typedef	struct		s_img
{
	void			*img;
	int				*i_data;
	int				bp;
	int				sl;
	int				edn;
}					t_img;

typedef	struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	double			l;
}					t_color;

typedef	struct		s_win
{
	int				c_x;
	int				c_y;
	int				x;
	int				y;
	int				opt;
	double			zoom;
	int				iter;
	int				mouse_press;
	int				color_press;
	int				mouse_lock;
	t_move			i;
	t_point			mouse;
	t_opt			opt1;
	t_opt			opt2;
	t_opt			opt3;
	t_opt			col1;
	t_opt			col2;
	t_opt			col3;
	t_opt			col4;
	t_color			col;
	t_double		move;
	t_bot			c;
	int				bot;
	double			adj;
	t_double		adj_spd;
	void			*mlx;
	void			*win;
	t_img			img;
	t_img			m;
	t_img			j;
	t_img			b;
	int				col_x;
}					t_win;

typedef	struct		s_thr
{
	int				y;
	int				y_max;
	t_win			*p;
	t_img			img;
}					t_thr;

int					mouse_hook(int bt, int x, int y, t_win *p);
int					mouse_hookup(int bt, int x, int y, t_win *p);
int					key_hook(int keycode, t_win *p);
int					mouse_move(int x, int y, t_win *p);
int					ft_back_to_normal(t_win *p);
int					ft_redraw(t_win *p);
int					ft_free_exit(t_win *p);
int					ft_draw_fractol(t_win *p);
int					ft_draw_option(t_win *p);
int					ft_zoom(int bt, int x, int y, t_win *p);
int					rgb(int r, int g, int b);
void				*mandel_thr(void *arg);
void				*julia_thr(void *arg);
void				*ship_thr(void *arg);
int					ft_draw_fractol(t_win *p);
int					ft_preview(t_win *p, t_img *img, int bot);

#endif
