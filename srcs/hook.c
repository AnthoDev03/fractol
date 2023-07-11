/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:04:27 by anthrodr          #+#    #+#             */
/*   Updated: 2023/07/10 17:22:44 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook2(int keycode, t_fractol *data)
{
	if (keycode == 50)
		data->color = 2050;
	else if (keycode == 51)
		data->color = 265;
	else if (keycode == 52)
		data->julia_mouse = !data->julia_mouse;
	else if (keycode == 53)
		data->show_text = !data->show_text;
	return (0);
}

int	key_hook(int keycode, t_fractol *data)
{
	if (keycode == 65307)
		exit(1);
	else if (keycode == 65451)
		data->it_max += 50;
	else if (keycode == 6553)
		data->it_max -= 50;
	else if (keycode == 65361)
		data->x1 -= 30 / data->zoom;
	else if (keycode == 65363)
		data->x1 += 30 / data->zoom;
	else if (keycode == 65364)
		data->y1 += 30 / data->zoom;
	else if (keycode == 65362)
		data->y1 -= 30 / data->zoom;
	else if (keycode == 49)
		fract_init(data);
	else if (keycode == 53)
		data->color = 1677216;
	key_hook2(keycode, data);
	fract_calc(data);
	return (0);
}

void	ft_zoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->it_max++;
}

void	ft_dezoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->it_max--;
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, data);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(x, y, data);
	fract_calc(data);
	return (0);
}
