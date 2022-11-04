/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:26 by arecce            #+#    #+#             */
/*   Updated: 2022/11/04 16:08:47 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_d *d)
{
	char	*move;

	move = ft_itoa(d->m_move);
	ft_printf("%d\n", d->m_move);
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	draw_all(d);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 32, 32, 0xFFFFFF, move);
	free(move);
}

int	exit_win(t_d *d)
{
	close_game(d);
	return (0);
}

int	moves(int keycode, t_d *d)
{
	if (keycode == 53)
		close_game(d);
	else if (keycode == 1 || keycode == 125)
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
	print_move(d);
	return (0);
}

int	main(int ac, char **av)
{
	t_d	d;
	int	c;

	if (ac != 2)
		exit(0);
	d.m_move = 0;
	c = 65;
	check_ber(av);
	get_map(av, &d);
	p_pos(&d);
	e_pos(&d);
	control_total(&d);
	d.mlx_ptr = mlx_init();
	d.e.mlx_ptr = mlx_init();
	d.win_ptr = mlx_new_window(d.mlx_ptr, d.w * 64, d.h * 64, "Dragon Ball M");
	img_init(&d);
	print_move(&d);
	mlx_hook(d.win_ptr, 2, (1L << 0), moves, &d);
	mlx_hook(d.win_ptr, 17, (1L << 16), exit_win, &d);
	mlx_loop_hook(d.e.mlx_ptr, exit_an, &d);
	mlx_loop(d.mlx_ptr);
	return (0);
}

// mlx_key_hook(d.win_ptr, pg_an, &d);
// mlx_do_key_autorepeatoff(d.mlx_ptr);
// mlx_loop_hook(d.mlx_ptr, exit_loop, &d);
//keycode		key
//	1/125			s
//	0/123			a
//	2/124			d
//	13/126			w
//	53			esc
//	49			space
// ft_printf("%d\n", keycode);