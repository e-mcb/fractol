/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:10:29 by mzutter           #+#    #+#             */
/*   Updated: 2025/03/12 05:35:08 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (ft_isdblstr(argv[2]) == 0 || ft_isdblstr(argv[3]) == 0)
		{
			ft_putstr_fd(ERROR_MESSAGE, 2);
			exit(EXIT_FAILURE);
		}
		fractal.name = argv[1];
		fractal.julia_real = ft_atod(argv[2]);
		fractal.julia_imaginary = ft_atod(argv[3]);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		fractal.name = argv[1];
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		exit(EXIT_FAILURE);
	}
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
