/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:12:20 by azahid            #+#    #+#             */
/*   Updated: 2025/03/18 05:51:24 by azahid           ###   ########.fr       */
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

int	mouse_listener(int mousecode, int x, int y, t_screen *screen)
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n || !s1 || !s2)
		return (0);
	while (*s1 && *s2 && --n > 0 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
