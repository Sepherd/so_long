/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:26 by arecce            #+#    #+#             */
/*   Updated: 2022/10/31 16:41:44 by arecce           ###   ########.fr       */
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
	exit_anim(data);
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
	print_move(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int	c = 65;
	data.m_move = 0;
	get_map(av, &data);
	p_pos(&data);
	e_pos(&data);
	total_clt(&data, 'C');
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.w * 64, data.h * 64, "Dragon Ball M");
	data.wall = mlx_xpm_file_to_image(data.mlx_ptr, "img/1.xpm", &c, &c);
	data.floor = mlx_xpm_file_to_image(data.mlx_ptr, "img/0.xpm", &c, &c);
	data.clt = mlx_xpm_file_to_image(data.mlx_ptr, "img/c.xpm", &c, &c);
	data.pg = mlx_xpm_file_to_image(data.mlx_ptr, "img/pf0.xpm", &c, &c);
	data.exit = mlx_xpm_file_to_image(data.mlx_ptr, "img/x0.xpm", &c, &c);
	data.enemy = mlx_xpm_file_to_image(data.mlx_ptr, "img/ef0.xpm", &c, &c);
	// draw_all(&data);
	print_move(&data);
	// mlx_do_key_autorepeatoff(data.mlx_ptr);
	mlx_hook(data.win_ptr, 2, (1L << 0), closes, &data);
	mlx_hook(data.win_ptr, 17, (1L << 16), exit_win, &data);
	// mlx_loop_hook(data.mlx_ptr, exit_loop, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
