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
# define SIZEX 800
# define SIZEY 800
#include <stdio.h>

typedef struct              s_color
{
	int                     red;
	int                     green;
	int                     blue;
}                           t_color;

typedef struct		s_var
{
	int				x;
	int				y;
	double			complex_x;
	double			complex_y;
	double			Zx;
	double			Zy;
	double			Zx2;
	double			Zy2;
	int				i;
	double			zoom_min_x;
	double			zoom_max_x;
	double			zoom_min_y;
	double			zoom_max_y;
	double			pixel_width;
	double			pixel_height;
	int				iteration;
	int				iterations_max;
	double 			EscapeRadius;
	double 			ER2;
}					t_var;

typedef struct		s_window
{
	void			*mlx;
	void			*win;
	void			*img;
	int 			img_x;
	int 			img_y;
	int				*data;
	t_var			var;
}					t_window;

/*
 * malloc
 */
t_window			*inicialization_win();
t_var				inicialization_var();
t_var		restart_var(t_window *win);

/*
 * support
 */
void				ft_error(int error);
void				ft_usage();

/*
 * fractol
 */
int					main(int argc, char **argv);

/*
 * options
 */
void				controls(t_window *win);
int					key_press(int key, void *fdf);

/*
 * fractals
 */
void		mandelbrot(t_window *win);


#endif
