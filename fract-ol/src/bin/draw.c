/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:11:58 by asalo             #+#    #+#             */
/*   Updated: 2024/03/10 12:57:33 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	draw_fractal(t_fractal *fractal, char *option)
{
	if (compare(option, "mandelbrot") == 0)
		draw_mandelbrot(fractal);
	else if (compare(option, "julia") == 0)
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = -0.745429;
			fractal->cy = 0.05;
		}
		draw_julia(fractal);
	}
	else
	{
		write(1, "Available fractals: mandelbrot, julia\n", 38);
		exit_free(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}