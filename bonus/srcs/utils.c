/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:34:22 by azahid            #+#    #+#             */
/*   Updated: 2025/03/17 21:27:46 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_listener(int keycode, t_screen *screen)
{
	double	temp;

	if (keycode == ESC)
	{
		closeit(screen);
		return (0);
	}
	if (keycode == DOWN)
	{
		temp = screen->value.ymax;
		screen->value.ymax += (screen->value.ymax - screen->value.ymin) / 10.0;
		screen->value.ymin += (temp - screen->value.ymin) / 10.0;
	}
	if (keycode == RIGHT)
	{
		temp = screen->value.xmax;
		screen->value.xmax += (screen->value.xmax - screen->value.xmin) / 10.0;
		screen->value.xmin += (temp - screen->value.xmin) / 10.0;
	}
	if (keycode == UP)
	{
		temp = screen->value.ymax;
		screen->value.ymax -= fabs(screen->value.ymax - screen->value.ymin)
			/ 10.0;
		screen->value.ymin -= fabs(temp - screen->value.ymin) / 10.0;
	}
	if (keycode == LEFT)
	{
		temp = screen->value.xmax;
		screen->value.xmax -= fabs(screen->value.xmax - screen->value.xmin)
			/ 10.0;
		screen->value.xmin -= fabs(temp - screen->value.xmin) / 10.0;
	}
  if (keycode  == SPACE)
  {
    screen->shapeshifter += 0.1;
  }
	if (screen->flag == 1)
		drawjulia(*screen);
	if (screen->flag == 2)
		drawmandelbrotset(*screen);
	else if (screen->flag == 3)
		drawburningship(*screen);
	mlx_put_image_to_window(screen->vars.mlx, screen->vars.win, screen->img.img,
		0, 0);
	return (0);
}

void	mouseup(t_screen *scr, int x, int y)
{
	double	skipx;
	double	skipy;
	double	cx;
	double	cy;

	skipx = (scr->value.xmax - scr->value.xmin) / WIDTH;
	skipy = (scr->value.ymax - scr->value.ymin) / HEIGHT;
	cx = scr->value.xmin + x * skipx;
	cy = scr->value.ymin + y * skipy;
	scr->value.xmin = cx + (scr->value.xmin - cx) * ZIN;
	scr->value.xmax = cx + (scr->value.xmax - cx) * ZIN;
	scr->value.ymin = cy + (scr->value.ymin - cy) * ZIN;
	scr->value.ymax = cy + (scr->value.ymax - cy) * ZIN;
}

void	mousedown(t_screen *scr, int x, int y)
{
	double	skipx;
	double	skipy;
	double	cx;
	double	cy;

	skipx = (scr->value.xmax - scr->value.xmin) / WIDTH;
	skipy = (scr->value.ymax - scr->value.ymin) / HEIGHT;
	cx = scr->value.xmin + x * skipx;
	cy = scr->value.ymin + y * skipy;
	scr->value.xmin = cx + (scr->value.xmin - cx) * ZOUT;
	scr->value.xmax = cx + (scr->value.xmax - cx) * ZOUT;
	scr->value.ymin = cy + (scr->value.ymin - cy) * ZOUT;
	scr->value.ymax = cy + (scr->value.ymax - cy) * ZOUT;
}
int	mouse_listener(int mousecode, int x, int y, t_screen *screen)
{
	if (mousecode == MUP)
	{
		mouseup(screen, x, y);
    if (screen->flag == 1)
			drawjulia(*screen);
		if (screen->flag == 2)
			drawmandelbrotset(*screen);
		if (screen->flag == 3)
			drawburningship(*screen);
		mlx_put_image_to_window(screen->vars.mlx, screen->vars.win,
			screen->img.img, 0, 0);
	}
	else if (mousecode == MDOWN)
	{
		mousedown(screen, x, y);
		if (screen->flag == 1)
			drawjulia(*screen);
		if (screen->flag == 2)
			drawmandelbrotset(*screen);
		if (screen->flag == 3)
			drawburningship(*screen);
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

int	figureoutiter(int temp,double shapeshifter)
{
	int		r;
	int		g;
	int		b;
	double	t;
	t = (double)((double)temp / MAXITER) * 11;
	r = (int)(sin(t * 5 + 3 + shapeshifter) * 127 + 128);
	g = (int)(sin(t * 5 + 2 + shapeshifter) * 127 + 128);
	b = (int)(sin(t * 5 + 5 + shapeshifter) * 127 + 128);
	return (255 << 24 | r << 16 | g << 8 | b);
}
