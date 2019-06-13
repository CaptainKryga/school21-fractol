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

void		mandelbrot(t_window *win)
{
	while (win->var.y < SIZEY)
	{
		win->var.complex_y = win->var.zoom_min_y + win->var.y * win->var
				.pixel_height;
		if (fabs(win->var.complex_y) < win->var.pixel_height / 2)
			win->var.complex_y = 0.0;
		win->var.x = 0;
		while(win->var.x < SIZEX)
		{
			win->var.complex_x = win->var.zoom_min_x + win->var.x * win->var
					.pixel_width;
			win->var.Zx = 0.0;
			win->var.Zy = 0.0;
			win->var.Zx2 = win->var.Zx * win->var.Zx;
			win->var.Zy2 = win->var.Zy * win->var.Zy;
			win->var.iteration = 0;
			while (win->var.iteration < win->var.iterations_max &&
				((win->var.Zx2 +	win->var.Zy2) < win->var.ER2))
			{
				win->var.Zy = 2 * win->var.Zx * win->var.Zy + win->var
						.complex_y;
				win->var.Zx = win->var.Zx2 - win->var.Zy2 + win->var.complex_x;
				win->var.Zx2 = win->var.Zx * win->var.Zx;
				win->var.Zy2 = win->var.Zy * win->var.Zy;
				win->var.iteration++;
			}
			if (win->var.iteration == win->var.iterations_max)
				win->data[win->var.i] = 0x00FF00;
			else
				win->data[win->var.i] = 0x000000;
			win->var.i++;
			win->var.x++;
		}
		win->var.y++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, win->img_x,
		win->img_y);
}

void			fractol(t_window *win)
{

	win->var = inicialization_var();
	mandelbrot(win);
	controls(win);
	printf("w:%f\n", win->var.zoom_min_x);
	mlx_loop(win->mlx);
}

int				main(int argc, char **argv)
{
	t_window	*win;

	if (argc != 1)
		exit(0);
	win = inicialization_win();
	fractol(win);
	exit(0);
	ft_usage();
	if (!argv[1])
		return (0);
	return (0);
}

int 			check_name(char *name)
{
	if (!ft_strcmp(name, "mandelbrot"))
		return (1);
	if (!ft_strcmp(name, "harry"))
		return (2);
	return (0);
}