/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:33:04 by arecce            #+#    #+#             */
/*   Updated: 2022/10/28 16:42:36 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *data)
{
	int	i;
	int	k;
	int	x;
	int	y;
	int	c = 64;

	i = 0;
	y = 0;
	while (i < data->h)
	{
		k = 0;
		x = 0;
		while (k < data->w)
		{
			// ft_printf("x = %d y = %d\n", x, y);
			if (data->map[i][k] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, x, y);
			else if (data->map[i][k] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, x, y);
			else if (data->map[i][k] == 'P')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, x, y);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->pg, x, y);
			}
			else if (data->map[i][k] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, x, y);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->clt, x, y);
			}
			else if (data->map[i][k] == 'E')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, x, y);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, x, y);
			}
			else if (data->map[i][k] == 'X')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, x, y);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->enemy, x, y);
			}
			k++;
			x += c;
		}
		i++;
		y += c;
	}
}
