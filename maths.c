/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:10:33 by mzutter           #+#    #+#             */
/*   Updated: 2025/03/12 04:16:08 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double num, double min2, double max2, double min1)
{
	return ((max2 - min2) * (num - min1) / (SIZE - min1) + min2);
}

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.imaginary = a.imaginary + b.imaginary;
	return (result);
}

t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.real = z.real * z.real - z.imaginary * z.imaginary;
	result.imaginary = 2 * z.real * z.imaginary;
	return (result);
}
