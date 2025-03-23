/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:10:36 by mzutter           #+#    #+#             */
/*   Updated: 2025/03/12 04:19:07 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->ptr_pix + offset) = color;
}

static double	map_color(int num, double min1, double max1)
{
	double	color1;
	double	color2;

	color1 = NEON_ORANGE;
	color2 = ELECTRIC_BLUE;
	return ((color2 - color1) * (num - min1) / (max1 - min1) + color1);
}

static void	define_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_real;
		c->imaginary = fractal->julia_imaginary;
	}
	else
	{
		c->real = z->real;
		c->imaginary = z->imaginary;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = (map(x, -2, +2, 0) * fractal->zoom) + fractal->shift_real;
	z.imaginary = (map(y, +2, -2, 0) * fractal->zoom) \
	+ fractal->shift_imaginary;
	define_fractal(&z, &c, fractal);
	while (i < fractal->max_iter)
	{
		z = complex_add(complex_square(z), c);
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > fractal->mod)
		{
			color = map_color(i, 0, fractal->max_iter);
			color_pixel(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	color_pixel(x, y, &fractal->img, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx,
		fractal->mlx_win,
		fractal->img.ptr_img,
		0, 0);
}
