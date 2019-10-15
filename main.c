/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 12:07:58 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/13 12:08:02 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fractol_loop(t_window *win)
{
	fractol_while(win);
	mlx_hook(win->win, 2, 0, key_press, win);
	mlx_hook(win->win, 17, 0, close, win);
	mlx_hook(win->win, 17, 0, expose, NULL);
	mlx_hook(win->win, 4, 0, (void *)mouse_key, win);
	mlx_hook(win->win, 6, 0, (void *)julia_mouse, win);
	mlx_loop(win->mlx);
}

void			fractol_initialization(t_window *win)
{
	if (win->typeFractol == 1)
		win->var = InitMandelbrot(win->flag_zoom);
	else if (win->typeFractol == 2)
		win->var = InitJulia();
	else if (win->typeFractol == 3)
		win->var = InitChameleon();
	else if (win->typeFractol == 4)
		win->var = InitBurningShip();
	win->flag_zoom = 1;
}

void			fractol_paint(t_window *win)
{
	if (win->var.iteration == win->var.iterations_max)
		win->data[win->i] = 0xFFFFFF;
	else
		win->data[win->i] = win->var.colour * win->var.iteration;
}

void			fractol_while(t_window *win)
{
	win->i = 0;
	win->var.y = 0;
	while (win->var.y < win->var.max_y)
	{
		win->var.x = 0;
		while (win->var.x < SIZE)
		{
			if (win->typeFractol == 1)
				mandelbrot(win);
			else if (win->typeFractol == 2)
				julia(win);
			else if (win->typeFractol == 3)
				chameleon(win);
			else if (win->typeFractol == 4)
				burningship(win);
			win->var.x++;
		}
		win->var.y++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}
/*
 * проверка на левое имя фрактала
 */
int				main(int argc, char **argv)
{
	t_window	*win;

	if (argc != 2)
		ft_usage();
	win = inicialization_win(argv[1]);
	fractol_initialization(win);
	fractol_loop(win);
	exit(0);
}
