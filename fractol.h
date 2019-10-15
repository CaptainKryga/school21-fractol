/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 12:07:58 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/13 12:08:02 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "libftprintf/ft_printf.h"
# include "libftprintf/libft/libft.h"
# include "libftprintf/libft/get_next_line.h"
# include "keycode.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define SIZE 900

//cr = dy
//ci = dy2
//zr = dx
//zi = dx2

typedef struct		s_var
{
	int				y;//верхняя итерация
	int				max_y;//верхняя итерация
	int				x;//нижняя итерация

	double			dx;//числа формулы фрактала
	double			dy2;//числа формулы фрактала
	double			dy;//числа формулы фрактала
	double			dx2;//числа формулы фрактала

	double			zoom;
	double			x1;
	double			y1;

	int				iteration;//итерация просчета Fractol
	int				iterations_max;//максимальная итерация

	int				colour;
}					t_var;

typedef struct		s_window
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int 			i;
	int				typeFractol;
	int 			flag_zoom;
	int 			flag_mouse;
	t_var			var;
}					t_window;

t_var			init_julia();
t_var			init_mandelbrot();
t_var			init_burning_ship();
t_var			init_chameleon();
t_window		*init_win(char *name);

void			usage();
int 			check_name(char *name);

int				key_press(int key, void *fdf);
int				expose();

void			mandelbrot(t_window *win);
void			julia(t_window *win);
void			chameleon(t_window *win);
void			burningship(t_window *win);

void			fractol_loop(t_window *win);
void			fractol_while(t_window *win);
void			fractol_paint(t_window *win);
void			fractol_init(t_window *win);
int				main(int argc, char **argv);

void			mouse_key(int keys, int x, int y, t_window *win);
void			mouse_julia(int x, int y, t_window *win);


#endif
