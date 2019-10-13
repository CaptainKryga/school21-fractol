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
	fractol_initialization(win);
	fractol_while(win);
	controls(win);
	mlx_loop(win->mlx);
}

void			fractol_initialization(t_window *win)
{
	if (win->typeFractol == 1)
		win->var = init_malderbrot();
	else if (win->typeFractol == 2)
		win->var = init_julia();
	else if (win->typeFractol == 3)
		win->var = init_chameleon();
	else if (win->typeFractol == 4)
		win->var = init_burningship();
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
	while (win->var.y < SIZE)
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
		}
		win->var.y++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}

int				main(int argc, char **argv)
{
	t_window	*win;

	if (argc != 2)
		exit(0);
	win = inicialization_win(argv[1]);
	fractol_loop(win);
	exit(0);
}