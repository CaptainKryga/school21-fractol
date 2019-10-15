/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_support.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:16:56 by jbashiri          #+#    #+#             */
/*   Updated: 2019/06/12 16:16:58 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
# include "pthread.h"

void    ft_usage()
{
	ft_printf("./fractol [mandelbrot or julia or burningship or chameleon]\n");
	exit(0);
}

int 			check_name(char *name)
{
	if (!ft_strcmp(name, "mandelbrot") || !ft_strcmp(name, "Mandelbrot") || !ft_strcmp(name, "1"))
		return (1);
	else if (!ft_strcmp(name, "julia") || !ft_strcmp(name, "Julia") || !ft_strcmp(name, "2"))
		return (2);
	else if (!ft_strcmp(name, "chameleon") || !ft_strcmp(name, "Chameleon") || !ft_strcmp(name, "3"))
		return (3);
	else if (!ft_strcmp(name, "burningship") || !ft_strcmp(name, "Burningship") ||
			 !ft_strcmp(name, "Ship") || !ft_strcmp(name, "ship") || !ft_strcmp(name, "4"))
		return (4);
	return (0);
}