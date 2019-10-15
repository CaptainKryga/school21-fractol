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

void	usage()
{
	ft_printf("./fractol [mandelbrot or julia or burningship or chameleon]\n");
	exit(0);
}

int		check_name(char *name)
{
	if (!ft_strcmp(name, "mandelbrot") || !ft_strcmp(name, "Mandelbrot"))
		return (1);
	else if (!ft_strcmp(name, "julia") || !ft_strcmp(name, "Julia"))
		return (2);
	else if (!ft_strcmp(name, "chameleon") || !ft_strcmp(name, "Chameleon"))
		return (3);
	else if (!ft_strcmp(name, "burningship") || !ft_strcmp(name, "Burningship"))
		return (4);
	usage();
	exit(0);
}

int				expose()
{
	exit(0);
}
