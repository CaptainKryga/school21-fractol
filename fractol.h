/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 12:07:58 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/13 12:08:02 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "libftprintf/ft_printf.h"
# include "libftprintf/libft/libft.h"
# include "libftprintf/libft/get_next_line.h"
# include "keycode.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# define SIZEX 1000
# define SIZEY 1000

typedef struct              s_pos
{
	int						x;
	int						y;
	int						z;
	int						flag;
	int						colour;
}							t_pos;

typedef struct              s_color
{
	int                     red;
	int                     green;
	int                     blue;
}                           t_color;

typedef struct              s_var
{
	int x;
	int y;
	int z;
	double i;
}                           t_var;

typedef struct				s_window
{
	void					*mlx;
	void					*win;
	int                     *img;
}							t_window;

/*
 * malloc
 */
t_window					*inicialization_win();

/*
 * support
 */
void    ft_error(int error);
void    ft_usage();

/*
 * fractol
 */
int							main(int argc, char **argv);

/*
 * options
 */
void			controls(t_window *win);
int				key_press(int key, void *fdf);


#endif
