/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:06:11 by jbashiri          #+#    #+#             */
/*   Updated: 2019/10/13 19:06:12 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_var		init_julia()
{
	t_var var;

	var.x = 0;
	var.y = 0;

	var.dx = 0;
	var.dx2 = 0;
	var.dy = -0.1;
	var.dy2 = 0.651;

	var.zoom = SIZE / 4;
	var.x1 = -2;
	var.y1 = -1.9;

	var.iteration = 0;
	var.iterations_max = 200;
	return (var);
}

void		julia(t_window *win)
{
	double  tmp;

	while (win->var.y < SIZE)
	{
		win->var.x = 0;
		while (win->var.x < SIZE)
		{
			win->var.dx = win->var.x / win->var.zoom + win->var.x1;
			win->var.dx2 = win->var.y / win->var.zoom + win->var.y1;
			win->var.iteration = 0;
			while (win->var.dx * win->var.dx + win->var.dx2 * win->var.dx2 < 4 && win->var.iteration < win->var.iterations_max)
			{
				tmp = win->var.dx * win->var.dx - win->var.dx2 * win->var.dx2 + win->var.dy;
				win->var.dx2 = 2.0 * win->var.dx * win->var.dx2 + win->var.dy2;
				win->var.dx = tmp + win->var.dy;
				win->var.iteration++;
			}

			if (win->var.iteration == win->var.iterations_max)
				win->data[win->i] = 0xFFFFFF;
			else
				win->data[win->i] = win->var.colour * win->var.iteration;
			win->i++;
			win->var.x++;
		}
		win->var.y++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}