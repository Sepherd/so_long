/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:33:04 by arecce            #+#    #+#             */
/*   Updated: 2022/11/09 17:46:24 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_d *d)
{
	int	i;
	int	k;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < d->h)
	{
		k = 0;
		x = 0;
		while (k < d->w)
		{
			if (d->map[i][k] == '1')
				mlx_put_image_to_window(d->mlx, d->win, d->wall, x, y);
			else
				mlx_put_image_to_window(d->mlx, d->win, d->floor, x, y);
			k++;
			x += 64;
		}
		i++;
		y += 64;
	}
}

void	draw_pg(t_d *d)
{
	int	i;
	int	k;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < d->h)
	{
		k = 0;
		x = 0;
		while (k < d->w)
		{
			if (d->map[i][k] == 'P')
			{
				mlx_put_image_to_window(d->mlx, d->win, d->pg, x, y);
				return ;
			}
			k++;
			x += 64;
		}
		i++;
		y += 64;
	}
}

void	draw_clt(t_d *d)
{
	int	i;
	int	k;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < d->h)
	{
		k = 0;
		x = 0;
		while (k < d->w)
		{
			if (d->map[i][k] == 'C')
				mlx_put_image_to_window(d->mlx, d->win, d->clt, x, y);
			k++;
			x += 64;
		}
		i++;
		y += 64;
	}
}

void	draw_exit(t_d *d)
{
	int	i;
	int	k;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < d->h)
	{
		k = 0;
		x = 0;
		while (k < d->w)
		{
			if (d->map[i][k] == 'E')
			{
				mlx_put_image_to_window(d->mlx, d->win, d->exit, x, y);
				return ;
			}
			k++;
			x += 64;
		}
		i++;
		y += 64;
	}
}

void	draw_enemy(t_d *d)
{
	int	i;
	int	k;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < d->h)
	{
		k = 0;
		x = 0;
		while (k < d->w)
		{
			if (d->map[i][k] == 'X')
				mlx_put_image_to_window(d->mlx, d->win, d->enemy, x, y);
			k++;
			x += 64;
		}
		i++;
		y += 64;
	}
}
