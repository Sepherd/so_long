/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:26 by arecce            #+#    #+#             */
/*   Updated: 2022/11/11 17:11:51 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_d *d)
{
	char	*move;

	move = ft_itoa(d->m_move);
	en_pos(d);
	draw_all(d);
	ft_printf("%d\n", d->m_move);
	mlx_string_put(d->mlx, d->win, 32, 32, 0xFFFFFF, move);
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
	else
		movement(d, keycode);
	return (0);
}

int	main(int ac, char **av)
{
	t_d	d;

	if (ac != 2)
		exit(0);
	check_ber(av);
	get_map(av, &d);
	control_total(&d);
	p_pos(&d);
	d.mlx = mlx_init();
	d.e.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, d.w * 64, d.h * 64, "Dragon Ball M");
	img_init(&d);
	draw_map(&d);
	draw_all(&d);
	mlx_hook(d.win, 2, (1L << 0), moves, &d);
	mlx_hook(d.win, 17, (1L << 16), exit_win, &d);
	mlx_loop_hook(d.e.mlx, exit_an, &d);
	mlx_loop(d.mlx);
	return (0);
}

// mlx_key_hook(d.win, pg_an, &d);
// mlx_do_key_autorepeatoff(d.mlx);
// mlx_loop_hook(d.mlx, exit_loop, &d);
//keycode		key
//	1/125			s
//	0/123			a
//	2/124			d
//	13/126			w
//	53			esc
//	49			space
// ft_printf("%d\n", keycode);
// leaks --list so_long durante l'esecuzione