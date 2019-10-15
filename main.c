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
	mlx_hook(win->win, 6, 0, (void *)mouse_julia, win);
	mlx_loop(win->mlx);
}

void			fractol_init(t_window *win)
{
	if (win->type_fractol == 1)
		win->var = init_mandelbrot();
	else if (win->type_fractol == 2)
		win->var = init_julia();
	else if (win->type_fractol == 3)
		win->var = init_chameleon();
	else if (win->type_fractol == 4)
		win->var = init_burning_ship();
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
	while (win->var.y < SIZE)
	{
		win->var.x = 0;
		while (win->var.x < SIZE)
		{
			if (win->type_fractol == 1)
				mandelbrot(win);
			else if (win->type_fractol == 2)
				julia(win);
			else if (win->type_fractol == 3)
				chameleon(win);
			else if (win->type_fractol == 4)
				burningship(win);
			win->var.x++;
		}
		win->var.y++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}

int				main(int argc, char **argv)
{
	t_window	*win;

	if (argc != 2)
		usage();
	win = init_win(argv[1]);
	fractol_init(win);
	fractol_loop(win);
	exit(0);
}
