/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:07:03 by arecce            #+#    #+#             */
/*   Updated: 2022/11/10 18:02:41 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_d *d, int keycode)
{
	if (keycode == 1 || keycode == 125)
	{
		front_move(d);
		d->m_move++;
	}
	else if (keycode == 0 || keycode == 123)
	{
		left_move(d);
		d->m_move++;
	}
	else if (keycode == 2 || keycode == 124)
	{
		right_move(d);
		d->m_move++;
	}
	else if (keycode == 13 || keycode == 126)
	{
		back_move(d);
		d->m_move++;
	}
}

void	front_move(t_d *d)
{
	int	c;

	c = 65;
	p_pos(d);
	d->pg = mlx_xpm_file_to_image(d->mlx, "img/pf0.xpm", &c, &c);
	if (d->map[d->p.pos_y + 1][d->p.pos_x] == '0' \
		|| d->map[d->p.pos_y + 1][d->p.pos_x] == 'C')
	{
		d->map[d->p.pos_y][d->p.pos_x] = '0';
		d->map[d->p.pos_y + 1][d->p.pos_x] = 'P';
	}
	else if (d->map[d->p.pos_y + 1][d->p.pos_x] == 'X')
	{
		print_lose(d);
		close_game(d);
	}
	else if (d->map[d->p.pos_y + 1][d->p.pos_x] == 'E')
		win(d);
	print_move(d);
}

void	back_move(t_d *d)
{
	int	c;

	c = 65;
	p_pos(d);
	d->pg = mlx_xpm_file_to_image(d->mlx, "img/pb0.xpm", &c, &c);
	if (d->map[d->p.pos_y - 1][d->p.pos_x] == '0' \
		|| d->map[d->p.pos_y - 1][d->p.pos_x] == 'C')
	{
		d->map[d->p.pos_y][d->p.pos_x] = '0';
		d->map[d->p.pos_y - 1][d->p.pos_x] = 'P';
	}
	else if (d->map[d->p.pos_y - 1][d->p.pos_x] == 'X')
	{
		print_lose(d);
		close_game(d);
	}
	else if (d->map[d->p.pos_y - 1][d->p.pos_x] == 'E')
		win(d);
	print_move(d);
}

void	right_move(t_d *d)
{
	int	c;

	c = 65;
	p_pos(d);
	d->pg = mlx_xpm_file_to_image(d->mlx, "img/pr0.xpm", &c, &c);
	if (d->map[d->p.pos_y][d->p.pos_x + 1] == '0' \
		|| d->map[d->p.pos_y][d->p.pos_x + 1] == 'C')
	{
		d->map[d->p.pos_y][d->p.pos_x] = '0';
		d->map[d->p.pos_y][d->p.pos_x + 1] = 'P';
	}
	else if (d->map[d->p.pos_y][d->p.pos_x + 1] == 'X')
	{
		print_lose(d);
		close_game(d);
	}
	else if (d->map[d->p.pos_y][d->p.pos_x + 1] == 'E')
		win(d);
	print_move(d);
}

void	left_move(t_d *d)
{
	int	c;

	c = 65;
	p_pos(d);
	d->pg = mlx_xpm_file_to_image(d->mlx, "img/pl0.xpm", &c, &c);
	if (d->map[d->p.pos_y][d->p.pos_x - 1] == '0' \
		|| d->map[d->p.pos_y][d->p.pos_x - 1] == 'C')
	{
		d->map[d->p.pos_y][d->p.pos_x] = '0';
		d->map[d->p.pos_y][d->p.pos_x - 1] = 'P';
	}
	else if (d->map[d->p.pos_y][d->p.pos_x - 1] == 'X')
	{
		print_lose(d);
		close_game(d);
	}
	else if (d->map[d->p.pos_y][d->p.pos_x - 1] == 'E')
		win(d);
	print_move(d);
}
