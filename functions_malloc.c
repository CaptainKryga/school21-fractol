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

	if (!(win = (t_window*)malloc(sizeof(t_window))))
		ft_error(0);
	win->mlx = mlx_init();
	win->win = NULL;
	return (win);
}