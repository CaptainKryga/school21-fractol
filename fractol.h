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
# define SIZE 1000
#include <stdio.h>

typedef struct              s_color
{
	int                     red;
	int                     green;
	int                     blue;
}                           t_color;

typedef struct		s_var
{
	int				y;//верхняя итерация
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
}					t_var;

typedef struct		s_window
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int 			i;
	int				typeFractol;
	t_var			var;
}					t_window;

/*
 * malloc
 */
t_var			init_julia();
t_var			init_malderbrot();
t_window		*inicialization_win(char *name);

/*
 * support
 */
void			ft_error(int error);
void			ft_usage();
int 			check_name(char *name);
/*
 * fractol
 */
int				main(int argc, char **argv);

/*
 * options
 */
void			controls(t_window *win);
int				key_press(int key, void *fdf);

/*
 * fractals
 */
void			mandelbrot(t_window *win);
void			julia(t_window *win);


#endif
