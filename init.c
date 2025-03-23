/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:10:14 by mzutter           #+#    #+#             */
/*   Updated: 2025/03/12 04:15:18 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->mod = 4;
	fractal->max_iter = 50;
	fractal->shift_real = 0.0;
	fractal->shift_imaginary = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress, KeyPressMask, kb_input, fractal);
	mlx_hook(fractal->mlx_win, ButtonPress, ButtonPressMask,
		mouse_input, fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify, StructureNotifyMask,
		proper_close, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (NULL == fractal->mlx)
		malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx, SIZE, SIZE, fractal->name);
	if (NULL == fractal->mlx_win)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.ptr_img = mlx_new_image(fractal->mlx,
			SIZE, SIZE);
	if (NULL == fractal->img.ptr_img)
	{
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.ptr_pix = mlx_get_data_addr(fractal->img.ptr_img,
			&fractal->img.bpp,
			&fractal->img.line_len,
			&fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
