/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 05:14:57 by azahid            #+#    #+#             */
/*   Updated: 2025/03/18 05:23:55 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyhelper(int keycode, t_screen *screen)
{
	double	temp;

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
	return (0);
}

int	key_listener(int keycode, t_screen *screen)
{
	double	temp;

	if (keycode == ESC)
		return (closeit(screen), 0);
	else if (keycode == SPACE)
		screen->shapeshifter += 0.1;
	else if (keycode == DOWN)
	{
		temp = screen->value.ymax;
		screen->value.ymax += (screen->value.ymax - screen->value.ymin) / 10.0;
		screen->value.ymin += (temp - screen->value.ymin) / 10.0;
	}
	else
		keyhelper(keycode, screen);
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
