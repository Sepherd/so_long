/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:26 by arecce            #+#    #+#             */
/*   Updated: 2022/10/26 18:53:15 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//keycode		key
//	1			s
//	0			a
//	2			d
//	13			w
//	53			esc
//	49			space

int	closes(int keycode, t_data *data)
{
	// ft_printf("%d\n", keycode);
	char	*moves;	
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	else if (keycode == 1)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 50, 60);
		data->m_move++;
	}
	else if (keycode == 0)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 40, 60);
		data->m_move++;
	}
	else if (keycode == 2)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 60, 60);
		data->m_move++;
	}
	else if (keycode == 13)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 50, 40);
		data->m_move++;
	}
	moves = ft_itoa(data->m_move);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 400, 30, 0xFFFFFF, moves);
	return (0);
}

int	main()
{
	t_data	data;
	int	c = 32;
	data.m_move = 1000000012;
	
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 800, "Hello world!");
	data.img = mlx_xpm_file_to_image(data.mlx_ptr, "sa.xpm", &c, &c);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 50, 50);
	mlx_hook(data.win_ptr, 2, (1L << 0), closes, &data);
	mlx_loop(data.mlx_ptr);
}
