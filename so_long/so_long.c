/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:26 by arecce            #+#    #+#             */
/*   Updated: 2022/11/03 16:39:24 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }
void	print_move(t_data *data)
{
	char	*move;

	move = ft_itoa(data->m_move);
	ft_printf("%d\n", data->m_move);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_all(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 32, 32, 0xFFFFFF, move);
}

int	exit_win(t_data *data)
{
	close_game(data);
	return (0);
}
//keycode		key
//	1/125			s
//	0/123			a
//	2/124			d
//	13/126			w
//	53			esc
//	49			space

// ft_printf("%d\n", keycode);
int	closes(int keycode, t_data *data)
{
	if (keycode == 53)
		close_game(data);
	else if (keycode == 1 || keycode == 125)
	{
		front_move(data);
		data->m_move++;
	}
	else if (keycode == 0 || keycode == 123)
	{
		left_move(data);
		data->m_move++;
	}
	else if (keycode == 2 || keycode == 124)
	{
		right_move(data);
		data->m_move++;
	}
	else if (keycode == 13 || keycode == 126)
	{
		back_move(data);
		data->m_move++;
	}
	else if (keycode == 49)
		pg_an(data);
	print_move(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int	c = 65;
	data.m_move = 0;
	check_ber(av);
	get_map(av, &data);
	p_pos(&data);
	e_pos(&data);
	control_total(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.w * 64, data.h * 64, "Dragon Ball M");
	img_init(&data);
	// draw_all(&data);
	print_move(&data);
	mlx_hook(data.win_ptr, 2, (1L << 0), closes, &data);
	mlx_hook(data.win_ptr, 17, (1L << 16), exit_win, &data);
	mlx_loop_hook(data.mlx_ptr, exit_an, &data);
	// mlx_key_hook(data.win_ptr, pg_an, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

// mlx_do_key_autorepeatoff(data.mlx_ptr);
// mlx_loop_hook(data.mlx_ptr, exit_loop, &data);