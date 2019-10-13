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

void    ft_error(int error)
{
	ft_printf("error: %d\n", error);
	exit(0);
}

void    ft_usage()
{
	ft_printf("./fractol [mandelbrot or julia or burningship or chameleon]\n");
	exit(0);
}