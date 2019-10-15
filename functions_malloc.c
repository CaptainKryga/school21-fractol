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

t_window		*init_win(char *name)
{
	t_window	*win;
	int			size_line;
	int			bpp;
	int			endian;

	if (!(win = (t_window*)malloc(sizeof(t_window))))
		exit(0);
	size_line = SIZE * SIZE;
	bpp = 8;
	endian = 0;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, SIZE, SIZE, "fractol");
	win->img = mlx_new_image(win->mlx, SIZE, SIZE);
	win->data = (int *)mlx_get_data_addr(win->img, &bpp, &size_line, &endian);
	win->i = 0;
	win->type_fractol = check_name(name);
	win->flag_mouse = 0;
	return (win);
}
