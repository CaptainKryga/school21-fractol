/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:07:58 by jbashiri          #+#    #+#             */
/*   Updated: 2019/10/13 12:08:02 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_var		init_malderbrot()//переписать
{
	t_var var;

	var.x = 0;
	var.y = 0;
	var.dx = 0;
	var.dx2 = 0;
	var.dy = 0;
	var.dy2 = 0;
	var.zoom = SIZE / 4;
	var.x1 = -2.5;
	var.y1 = -1.8;
	var.iteration = 0;
	var.iterations_max = 255;
	var.colour = 265;
	return (var);
}

void		mandelbrot(t_window *win)
{
	double tmp;

	win->var.dy = win->var.x / win->var.zoom + win->var.x1;
	win->var.dy2 = win->var.y / win->var.zoom + win->var.y1;
	win->var.dx = 0;
	win->var.dx2 = 0;
	win->var.iteration = 0;
	while(win->var.dx * win->var.dx + win->var.dx2 * win->var.dx2 < 4 &&
		win->var.iteration < win->var.iterations_max)
	{
		tmp = win->var.dx * win->var.dx - win->var.dx2 * win->var.dx2 + win->var.dy;
		win->var.dx2 = 2.0 * win->var.dx * win->var.dx2 + win->var.dy2;
		win->var.dx = tmp;
		fractol_paint(win);
		win->var.iteration++;
	}
	win->i++;
	win->var.x++;
}
