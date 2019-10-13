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

t_window    *inicialization_win(char *name)
{
	t_window *win;
	int size_line;
	int bpp;
	int endian;

	win = (t_window*)malloc(sizeof(t_window));
	size_line = SIZE * SIZE;
	bpp = 8;
	endian = 0;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, SIZE, SIZE, "fractol");
	win->img = mlx_new_image(win->mlx, SIZE, SIZE);
	win->data = (int *)mlx_get_data_addr(win->img, &bpp, &size_line, &endian);
	win->typeFractol = check_name(name);
	return (win);
}

int 			check_name(char *name)
{
	if (!ft_strcmp(name, "mandelbrot") || !ft_strcmp(name, "Mandelbrot") || !ft_strcmp(name, "1"))
		return (1);
	if (!ft_strcmp(name, "julia") || !ft_strcmp(name, "Julia") || !ft_strcmp(name, "2"))
		return (2);
	return (0);
}