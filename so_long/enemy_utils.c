/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:34:09 by arecce            #+#    #+#             */
/*   Updated: 2022/11/11 16:22:10 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_left(t_d *d)
{
	int	c;

	c = 65;
	d->enemy = mlx_xpm_file_to_image(d->mlx, "img/el0.xpm", &c, &c);
	if (d->map[d->e.en_y][d->e.en_x - 1] == 'P')
		print_lose(d);
	d->map[d->e.en_y][d->e.en_x] = '0';
	d->map[d->e.en_y][d->e.en_x - 1] = 'X';
}

void	enemy_right(t_d *d)
{
	int	c;

	c = 65;
	d->enemy = mlx_xpm_file_to_image(d->mlx, "img/er0.xpm", &c, &c);
	if (d->map[d->e.en_y][d->e.en_x + 1] == 'P')
		print_lose(d);
	d->map[d->e.en_y][d->e.en_x] = '0';
	d->map[d->e.en_y][d->e.en_x + 1] = 'X';
	d->e.en_x++;
}

void	enemy_front(t_d *d)
{
	int	c;

	c = 65;
	d->enemy = mlx_xpm_file_to_image(d->mlx, "img/ef0.xpm", &c, &c);
	if (d->map[d->e.en_y + 1][d->e.en_x] == 'P')
		print_lose(d);
	d->map[d->e.en_y][d->e.en_x] = '0';
	d->map[d->e.en_y + 1][d->e.en_x] = 'X';
}

void	enemy_back(t_d *d)
{
	int	c;

	c = 65;
	d->enemy = mlx_xpm_file_to_image(d->mlx, "img/eb0.xpm", &c, &c);
	if (d->map[d->e.en_y - 1][d->e.en_x] == 'P')
		print_lose(d);
	d->map[d->e.en_y][d->e.en_x] = '0';
	d->map[d->e.en_y - 1][d->e.en_x] = 'X';
}
