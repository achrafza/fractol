/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:34:22 by azahid            #+#    #+#             */
/*   Updated: 2025/03/18 00:56:01 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_listener(int keycode, t_screen *screen)
{
	if (keycode == ESC)
	{
		closeit(screen);
		return (0);
	}
	if (screen->flag == 1)
		drawjulia(*screen);
	if (screen->flag == 2)
		drawmandelbrotset(*screen);
	mlx_put_image_to_window(screen->vars.mlx, screen->vars.win, screen->img.img,
		0, 0);
	return (0);
}

void	mouseup(t_screen *scr)
{
	scr->value.xmin *= ZIN;
	scr->value.xmax *= ZIN;
	scr->value.ymin *= ZIN;
	scr->value.ymax *= ZIN;
}

void	mousedown(t_screen *scr)
{
	scr->value.xmin *= ZOUT;
	scr->value.xmax *= ZOUT;
	scr->value.ymin *= ZOUT;
	scr->value.ymax *= ZOUT;
}
int	mouse_listener(int mousecode,int x,int y, t_screen *screen)
{
  (void)x;
  (void)y;
	if (mousecode == MUP)
	{
		mouseup(screen);
		if (screen->flag == 1)
			drawjulia(*screen);
		if (screen->flag == 2)
			drawmandelbrotset(*screen);
		mlx_put_image_to_window(screen->vars.mlx, screen->vars.win,
			screen->img.img, 0, 0);
	}
	else if (mousecode == MDOWN)
	{
		mousedown(screen);
		if (screen->flag == 1)
			drawjulia(*screen);
		if (screen->flag == 2)
			drawmandelbrotset(*screen);
		mlx_put_image_to_window(screen->vars.mlx, screen->vars.win,
			screen->img.img, 0, 0);
	}
	return (0);
}

double	ft_atod(char *str)
{
	int		i;
	int		signe;
	double	power;
	double	res;

	i = 0;
	res = 0;
	power = 1;
	signe = 1;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			signe = -1;
	}
	while (('0' <= str[i] && str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	if (str[i] == '.' || str[i] == ',')
		i++;
	while (('0' <= str[i] && str[i] <= '9'))
	{
		power = power / 10;
		res = res + (str[i] - '0') * power;
		i++;
	}
	return (res * signe);
}

int	figureoutiter(int temp)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = (double)((double)temp / MAXITER) * 11;
	r = (int)(sin(t * 5 + 3) * 127 + 128);
	g = (int)(sin(t * 5 + 2) * 127 + 128);
	b = (int)(sin(t * 5 + 5) * 127 + 128);
	return (255 << 24 | r << 16 | g << 8 | b);
}
