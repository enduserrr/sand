/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:39:16 by asalo             #+#    #+#             */
/*   Updated: 2024/03/14 10:07:35 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(t_fractal *fractal)
{
	int		i;
	double	tmp;

	fractal->name = "julia";
	fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0xFFFFFF);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * i));
}

void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < WIDTH)
	{
		while (fractal->y < HIGHT)
		{
			calculate_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}