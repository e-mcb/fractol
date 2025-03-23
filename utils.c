/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:10:42 by mzutter           #+#    #+#             */
/*   Updated: 2025/03/12 05:02:20 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s && *(s + 1) != '\0')
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s1[i] != 0 || s2[i] != 0))
	{
		i++;
		if (i == n)
			return (s1[i - 1] - s2[i - 1]);
	}
	return (s1[i] - s2[i]);
}

int	ft_isdblstr(char *str)
{
	int	i;

	i = 0;
	if (str[0] == 0)
		return (0);
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	else
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == 0)
		return (1);
	else
		return (0);
}
