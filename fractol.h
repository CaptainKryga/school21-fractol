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

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libftprintf/ft_printf.h"
# include "libftprintf/libft/libft.h"
# include "libftprintf/libft/get_next_line.h"
# include "keycode.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define SIZE 900

typedef struct	s_var
{
	int			y;
	int			x;

	double		dx;
	double		dy2;
	double		dy;
	double		dx2;

	double		zoom;
	double		x1;
	double		y1;

	int			iteration;
	int			iterations_max;

	int			colour;
}				t_var;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			i;
	int			type_fractol;
	int			flag_mouse;
	t_var		var;
}				t_window;

t_var			init_julia(void);
t_var			init_mandelbrot(void);
t_var			init_burning_ship(void);
t_var			init_chameleon(void);
t_window		*init_win(char *name);

void			usage(void);
int				check_name(char *name);

int				key_press(int key, void *fdf);
void			key_press_two(int key, void *win);
void			mouse_key(int keys, int x, int y, t_window *win);
void			mouse_julia(int x, int y, t_window *win);
int				expose(void);

void			mandelbrot(t_window *win);
void			julia(t_window *win);
void			chameleon(t_window *win);
void			burningship(t_window *win);

void			fractol_loop(t_window *win);
void			fractol_while(t_window *win);
void			fractol_paint(t_window *win);
void			fractol_init(t_window *win);
int				main(int argc, char **argv);

#endif
