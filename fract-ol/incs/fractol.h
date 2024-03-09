/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:20:41 by asalo             #+#    #+#             */
/*   Updated: 2024/03/09 11:08:08 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <unistd.h> /*write*/
# include <pthread.h>
# include <stdlib.h> /*exit*/
# include <stdio.h> /*perror*/
# include <string.h> /*strerror*/
# include "../minilibx_opengl.tgz"

# define SIZE 700
# define THREAD_WIDTH 7
# define THREAD_NUMBER 100

// KEYCODES
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

void		put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
int			exit_free(t_fractal *fractal);
double		generate_random_c(void);
void		change_iterations(t_fractal *fractal, int key_code);

void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);

// void		calculate_mandelbrot(t_fractal *fractal);
// void		calculate_julia(t_fractal *fractal);

void		calculate_burning_ship(t_fractal *fractal);

int			draw_fractal(t_fractal *fractal, char option);

int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

void		*draw_mandelbrot(void *fractal_void);
void		draw_julia(t_fractal *fractal);
void		draw_burning_ship(t_fractal *fractal);

#endif