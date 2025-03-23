/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:10:10 by mzutter           #+#    #+#             */
/*   Updated: 2025/03/12 21:34:25 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "./fractol mandelbrot || ./fractol julia [Re] [Im]\n\
	(Re, Im) ∈  ]-2, +2[\n"

# define SIZE 800

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define MAGENTA     0xFF00FF
# define LIME        0x00FF00
# define NEON_ORANGE 0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA        0x33CCCC
# define HOT_PINK    0xFF66B2
# define ELECTRIC_BLUE 0x0066FF
# define LAVA_RED    0xFF3300
# define FLUORESCENT_GREEN 0x39FF14
# define CYBERPUNK_PINK 0xFF007F
# define NEON_YELLOW 0xFFFF00

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_img
{
	void	*ptr_img;
	char	*ptr_pix;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	double	mod;
	int		max_iter;
	double	shift_real;
	double	shift_imaginary;
	double	zoom;
	double	julia_real;
	double	julia_imaginary;
}				t_fractal;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		ft_atod(const char *s);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		map(double num, double min2, double max2, double min1);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			kb_input(int keysym, t_fractal *fractal);
int			proper_close(t_fractal *fractal);
int			mouse_input(int mouse_button, int x, int y, t_fractal *fractal);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_square(t_complex z);
int			ft_isdblstr(char *str);

#endif
