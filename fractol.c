/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:30:14 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/08 10:17:44 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void            mot(t_var *var, t_window *win)
{
	double Cx, Cy;
	const double CxMin = -2.5;
	const double CxMax = 1.5;
	const double CyMin = -2.0;
	const double CyMax = 2.0;
	double PixelWidth = (CxMax - CxMin) / SIZEX;
	double PixelHeight = (CyMax - CyMin) / SIZEY;
	int Iteration;
	const int IterationMax = 200;
	double Zx, Zy;
	double Zx2, Zy2;
	const double EscapeRadius = 2;
	double ER2 = EscapeRadius * EscapeRadius;

	var->y = 0;
	while (var->y < SIZEY)
	{
		Cy = CyMin + var->y * PixelHeight;
		if (fabs(Cy) < PixelHeight / 2)
			Cy = 0.0;
		var->x = 0;
		while(var->x < SIZEX)
		{
			Cx = CxMin + var->x * PixelWidth;
			Zx = 0.0;
			Zy = 0.0;
			Zx2 = Zx * Zx;
			Zy2 = Zy * Zy;
			Iteration = 0;
			while (Iteration < IterationMax && ((Zx2 + Zy2) < ER2))
			{
				Zy = 2 * Zx * Zy + Cy;
				Zx = Zx2 - Zy2 + Cx;
				Zx2 = Zx * Zx;
				Zy2 = Zy * Zy;
				Iteration++;
			}
			if (Iteration == IterationMax)
			{
				mlx_pixel_put(win->mlx, win->win, var->x, var->y, 0x000000);
			}
			else if (Iteration == 2)
				mlx_pixel_put(win->mlx, win->win, var->x, var->y, 0xAAAAAA);
			else if (Iteration > 1 && Iteration < 10)
				mlx_pixel_put(win->mlx, win->win, var->x, var->y, 0x777777);
			else if (Iteration >= 10 && Iteration < 50)
				mlx_pixel_put(win->mlx, win->win, var->x, var->y, 0x333333);
			else if (Iteration >= 50 && Iteration < IterationMax)
				mlx_pixel_put(win->mlx, win->win, var->x, var->y, 0xdddddd);
			else
				mlx_pixel_put(win->mlx, win->win, var->x, var->y, 0xFFFFFF);
			var->i++;
			var->x++;
		}
		var->y++;
	}
}

void			fractol(t_window *win)
{
	t_var *var;

	var = (t_var*)malloc(sizeof(t_var));
	win->win = mlx_new_window(win->mlx, SIZEX, SIZEY,
		"fractol");
	mot(var, win);
//	controls(win);
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
