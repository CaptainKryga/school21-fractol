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

/*
 * key_press == использование клавы
 * close == закрытие окна на крестик красный
 * expose == ?
 */
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
    /*
    * кнопки реализованы
    */
	if (key == MAIN_PAD_ESC)
		exit(0);
	else if (key == NUM_PAD_PLUS)
	{
		win->var.zoom_min_x += 0.05;
		win->var.zoom_max_x -= 0.05;
		win->var.zoom_min_y += 0.05;
		win->var.zoom_max_y -= 0.05;
	}
	else if (key == NUM_PAD_MINUS)
    {
        win->var.zoom_min_x -= 0.05;
        win->var.zoom_max_x += 0.05;
        win->var.zoom_min_y -= 0.05;
        win->var.zoom_max_y += 0.05;
    }
	else if (key == ARROW_UP)
    {
        win->var.zoom_min_y += 0.05;
        win->var.zoom_max_y += 0.05;
    }
    else if (key == ARROW_DOWN)
    {
        win->var.zoom_min_y -= 0.05;
        win->var.zoom_max_y -= 0.05;
    }
    else if (key == ARROW_LEFT)
    {
        win->var.zoom_min_x += 0.05;
        win->var.zoom_max_x += 0.05;
    }
    else if (key == ARROW_RIGHT)
    {
        win->var.zoom_min_x -= 0.05;
        win->var.zoom_max_x -= 0.05;
    }
    else
        return (0);
    mlx_clear_window(win->mlx, win->win);
    if (win->typeFractol == 1)
	{
		mandelbrot(win);
	}
    else if (win->typeFractol == 2)
	{
    	julia(win);
	}
	return (0);
}
