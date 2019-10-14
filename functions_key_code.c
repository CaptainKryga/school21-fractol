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

int				key_press(int key, void *fdf)
{
	t_window	*win;

	win = fdf;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == ARROW_UP)
	{
		win->var->x1 -= 30 / win->var->zoom;
		printf("up\n");
	}
    if (key == ARROW_DOWN)
	{
		win->var->x1 -= 30 / win->var->zoom;
		printf("down\n");
	}
    if (key == ARROW_LEFT)
	{
		win->var->y1 -= 30 / win->var->zoom;
		printf("left\n");
	}
    if (key == ARROW_RIGHT)
	{
		win->var->y1 -= 30 / win->var->zoom;
		printf("right\n");
	}
    mlx_clear_window(win->mlx, win->win);
	fractol_while(win);
	return (0);
}
