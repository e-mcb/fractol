/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:10:06 by mzutter           #+#    #+#             */
/*   Updated: 2025/03/12 05:34:54 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	proper_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx,
		fractal->img.ptr_img);
	mlx_destroy_window(fractal->mlx,
		fractal->mlx_win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

int	kb_input(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		proper_close(fractal);
	if (keysym == XK_Left)
		fractal->shift_real += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_real -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_imaginary -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_imaginary += (0.5 * fractal->zoom);
	else if (keysym == XK_equal || keysym == 0xffab)
		fractal->max_iter += 5;
	else if (keysym == XK_minus || keysym == 0xffad)
		fractal->max_iter -= 5;
	fractal_render(fractal);
	return (0);
}

int	mouse_input(int mouse_button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (mouse_button == Button5)
		fractal->zoom *= 1.05;
	else if (mouse_button == Button4)
		fractal->zoom *= 0.95;
	fractal_render(fractal);
	return (0);
}
