/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:29:17 by asalo             #+#    #+#             */
/*   Updated: 2024/03/13 10:23:49 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}
