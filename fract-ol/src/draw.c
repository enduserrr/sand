/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:29:17 by asalo             #+#    #+#             */
/*   Updated: 2024/03/14 09:41:48 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

// void	*draw_mandelbrot(void *fractal_void)
// {
// 	t_fractal	*fractal;

// 	fractal = (t_fractal *)fractal_void;
// 	fractal->x = 0;
// 	fractal->y = 0;
// 	while (fractal->x < SIZE)
// 	{
// 		while (fractal->y < SIZE)
// 		{
// 			calculate_mandelbrot(fractal);
// 			fractal->y++;
// 		}
// 		fractal->x++;
// 		fractal->y = 0;
// 	}
// 	return (NULL);
// }

// void	draw_julia(t_fractal *fractal)
// {
// 	fractal->x = 0;
// 	fractal->y = 0;
// 	while (fractal->x < SIZE)
// 	{
// 		while (fractal->y < SIZE)
// 		{
// 			calculate_julia(fractal);
// 			fractal->y++;
// 		}
// 		fractal->x++;
// 		fractal->y = 0;
// 	}
// }

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