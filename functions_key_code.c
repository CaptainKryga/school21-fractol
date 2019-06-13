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

//void			key_menu(int key, t_window *win)
//{
//	if (key == 48)
//	{
//		if (win->cyp->war == 0)
//		{
//			win->cyp->war = 1;
//			mlx_string_put(win->mlx, win->win,\
//					20, 50, 0x7291F3, "1 - map reset");
//			mlx_string_put(win->mlx, win->win,\
//					20, 70, 0x7291F3, "2,3,4 - isometry");
//			mlx_string_put(win->mlx, win->win,\
//					20, 90, 0x7291F3, "-,+ - zoom");
//			mlx_string_put(win->mlx, win->win,\
//					20, 110, 0x7291F3, "up,down,left,right - move map");
//			mlx_string_put(win->mlx, win->win,\
//					20, 130, 0x7291F3, "<,> - depth z");
//			mlx_string_put(win->mlx, win->win,\
//					20, 150, 0x7291F3, "w,a,s,d - rotate");
//			mlx_string_put(win->mlx, win->win,\
//					20, 170, 0x7291F3, "z,x,c - change colour");
//			mlx_string_put(win->mlx, win->win,\
//					20, 190, 0x7291F3, "esc - exit program");
//		}
//	}
//}

int				key_press(int key, void *fdf)
{
	t_window	*win;

	win = fdf;
	if (key == MAIN_PAD_ESC)
		exit(0);
//	key_menu(key, win);
	return (0);
}


