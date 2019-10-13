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

void			fractol(t_window *win)
{
	if (win->typeFractol == 1)
	{
		win->var = init_malderbrot();
		mandelbrot(win);
	}
	else if (win->typeFractol == 2)
	{
		win->var = init_julia();
		julia(win);
	}
	controls(win);
	mlx_loop(win->mlx);
}

int				main(int argc, char **argv)
{
	t_window	*win;

	if (argc != 2)
		exit(0);
	win = inicialization_win(argv[1]);
	fractol(win);
	exit(0);
}
