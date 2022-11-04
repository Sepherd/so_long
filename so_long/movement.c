/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:07:03 by arecce            #+#    #+#             */
/*   Updated: 2022/11/04 16:02:51 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	front_move(t_d *d)
{
	int	c;

	c = 65;
	p_pos(d);
	d->pg = mlx_xpm_file_to_image(d->mlx_ptr, "img/pf0.xpm", &c, &c);
	if (d->map[d->p.pos_y + 1][d->p.pos_x] == '0' \
		|| d->map[d->p.pos_y + 1][d->p.pos_x] == 'C')
	{
		d->map[d->p.pos_y][d->p.pos_x] = '0';
		d->map[d->p.pos_y + 1][d->p.pos_x] = 'P';
	}
	else if (d->map[d->p.pos_y + 1][d->p.pos_x] == 'X')
	{
		print_lose();
		close_game(d);
	}
	else if (d->map[d->p.pos_y + 1][d->p.pos_x] == 'E')
		win(d);
}

void	back_move(t_d *d)
{
	int	c;

	c = 65;
	p_pos(d);
	d->pg = mlx_xpm_file_to_image(d->mlx_ptr, "img/pb0.xpm", &c, &c);
	if (d->map[d->p.pos_y - 1][d->p.pos_x] == '0' \
		|| d->map[d->p.pos_y - 1][d->p.pos_x] == 'C')
	{
		d->map[d->p.pos_y][d->p.pos_x] = '0';
		d->map[d->p.pos_y - 1][d->p.pos_x] = 'P';
	}
	else if (d->map[d->p.pos_y - 1][d->p.pos_x] == 'X')
	{
		print_lose();
		close_game(d);
	}
	else if (d->map[d->p.pos_y - 1][d->p.pos_x] == 'E')
		win(d);
}

void	right_move(t_d *d)
{
	int	c;

	c = 65;
	p_pos(d);
	d->pg = mlx_xpm_file_to_image(d->mlx_ptr, "img/pr0.xpm", &c, &c);
	if (d->map[d->p.pos_y][d->p.pos_x + 1] == '0' \
		|| d->map[d->p.pos_y][d->p.pos_x + 1] == 'C')
	{
		d->map[d->p.pos_y][d->p.pos_x] = '0';
		d->map[d->p.pos_y][d->p.pos_x + 1] = 'P';
	}
	else if (d->map[d->p.pos_y][d->p.pos_x + 1] == 'X')
	{
		print_lose();
		close_game(d);
	}
	else if (d->map[d->p.pos_y][d->p.pos_x + 1] == 'E')
		win(d);
}

void	left_move(t_d *d)
{
	int	c;

	c = 65;
	p_pos(d);
	d->pg = mlx_xpm_file_to_image(d->mlx_ptr, "img/pl0.xpm", &c, &c);
	if (d->map[d->p.pos_y][d->p.pos_x - 1] == '0' \
		|| d->map[d->p.pos_y][d->p.pos_x - 1] == 'C')
	{
		d->map[d->p.pos_y][d->p.pos_x] = '0';
		d->map[d->p.pos_y][d->p.pos_x - 1] = 'P';
	}
	else if (d->map[d->p.pos_y][d->p.pos_x - 1] == 'X')
	{
		print_lose();
		close_game(d);
	}
	else if (d->map[d->p.pos_y][d->p.pos_x - 1] == 'E')
		win(d);
}

void	win(t_d *d)
{
	d->p.clt_tot = total_count(d, 'C');
	if (d->p.clt_tot == 0)
	{
		print_win();
		close_game(d);
	}
	else
		ft_printf("\033[1;34mNon hai raccolto tutti i collezionabili!\n\033[1;0m");
}
