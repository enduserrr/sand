/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:29:17 by asalo             #+#    #+#             */
/*   Updated: 2024/03/14 18:58:52 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

int	draw_fractal(t_fractal *fractal, char *option)
{
	if (ft_strcmp(option, "mandel") == 0)
		draw_mandelbrot(fractal);
	else if (ft_strcmp(option, "julia") == 0)
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
		ft_printf("available fractals: mandel, julia\n");
		clean_exit(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

void draw_fractal_section(t_fractal *fractal, int x, int y, int end_x, int end_y)
{
	if (x >= end_x && y >= end_y)
	{
		return ;
	}
	fractal->x = x;
	fractal->y = y;
	calculate_julia(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	if (x + 1 >= end_x) 
		draw_fractal_section(fractal, 0, + 1, end_x, end_y);
	else
		draw_fractal_section(fractal, x + 1, y, end_x, end_y);
}