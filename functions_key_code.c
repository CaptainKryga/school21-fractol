/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:16:32 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/08 11:20:30 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				expose(void *param)
{
	t_window	*win;

	win = param;
	exit(0);
}

void			controls(t_window *win)
{
	mlx_hook(win->win, 2, 0, key_press, win);
	mlx_hook(win->win, 17, 0, close, win);
	mlx_hook(win->win, 17, 0, expose, win);
}

int				key_press(int key, void *fdf)
{
	t_window	*win;

	win = fdf;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == NUM_PAD_PLUS)
	{
		win->var = restart_var(win);
		printf("w:%f\n", win->var.zoom_min_x);
//		win->img_x += 100;
		win->var.zoom_min_x += 0.1;
		win->var.zoom_max_x -= 0.1;
		win->var.zoom_min_y += 0.1;
		win->var.zoom_max_y -= 0.1;
		mlx_clear_window(win->mlx, win->win);
		printf("w:%f\n", win->var.zoom_min_x);
		mandelbrot(win);
	}
	return (0);
}
