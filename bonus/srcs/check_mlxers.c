/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mlxers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:39:42 by azahid            #+#    #+#             */
/*   Updated: 2025/03/18 03:49:53 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	closeit(t_screen *f)
{
	if (f->img.img)
	{
		mlx_destroy_image(f->vars.mlx, f->img.img);
	}
	if (f->vars.win)
	{
		mlx_clear_window(f->vars.mlx, f->vars.win);
		mlx_destroy_window(f->vars.mlx, f->vars.win);
	}
	if (f->vars.mlx)
	{
		mlx_destroy_display(f->vars.mlx);
		free(f->vars.mlx);
	}
	exit(1);
	return (0);
}

static int	point(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '.')
			c++;
		i++;
	}
	return (c);
}

static int	checker(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (!s[i])
		return (1);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (1);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '.' && (s[i + 1] >= '0' && s[i + 1] <= '9'))
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i])
		return (1);
	return (0);
}

int	checkerav(char **av)
{
	return ((checker(av[2]) || checker(av[3])) || ((point(av[2]) > 1)
			|| (point(av[3]) > 1)));
}
