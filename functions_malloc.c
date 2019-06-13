/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:14:23 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/12 16:14:27 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window    *inicialization_win()
{
	t_window *win;
	int size_line;
	int bpp;
	int endian;

	win = (t_window*)malloc(sizeof(t_window));
	size_line = 1000;
	bpp = 8;
	endian = 0;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, SIZEX, SIZEY, "fractol");
	win->img = mlx_new_image(win->mlx, SIZEX, SIZEY);
	win->img_x = 0;
	win->img_y = 0;
	win->data = (int *)mlx_get_data_addr(win->img, &bpp, &size_line, &endian);
	return (win);
}

t_var		inicialization_var()
{
	t_var var;

	var.x = 0;
	var.y = 0;
	var.complex_x = 0;
	var.complex_y = 0;
	var.Zx = 0;
	var.Zx2 = 0;
	var.Zy = 0;
	var.Zy2 = 0;
	var.i = 0;
	var.zoom_min_x = -2.5;
	var.zoom_max_x = 1.5;
	var.zoom_min_y = -2.0;
	var.zoom_max_y = 2.0;
	var.pixel_width = (var.zoom_max_x - var.zoom_min_x) / SIZEX;
	var.pixel_height = (var.zoom_max_y - var.zoom_min_y) / SIZEY;
	var.iteration = 0;
	var.iterations_max = 200;
	var.EscapeRadius = 2;
	var.ER2 = var.EscapeRadius * var.EscapeRadius;
	return (var);
}

t_var		restart_var(t_window *win)
{
	t_var var;

	var.x = 0;
	var.y = 0;
	var.complex_x = 0;
	var.complex_y = 0;
	var.Zx = 0;
	var.Zx2 = 0;
	var.Zy = 0;
	var.Zy2 = 0;
	var.i = 0;
	var.zoom_min_x = win->var.zoom_min_x;
	var.zoom_max_x = win->var.zoom_max_x;
	var.zoom_min_y = win->var.zoom_min_y;
	var.zoom_max_y = win->var.zoom_max_y;
	var.pixel_width = (var.zoom_max_x - var.zoom_min_x) / SIZEX;
	var.pixel_height = (var.zoom_max_y - var.zoom_min_y) / SIZEY;
	var.iteration = 0;
	var.iterations_max = 200;
	var.EscapeRadius = 2;
	var.ER2 = var.EscapeRadius * var.EscapeRadius;
	return (var);
}