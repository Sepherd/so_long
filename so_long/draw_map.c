/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:33:04 by arecce            #+#    #+#             */
/*   Updated: 2022/10/27 19:55:43 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *data)
{
	int	i;
	int	k;
	int	x;
	int	y;
	int	c = 32;

	i = 0;
	y = 0;
	while (i < data->h)
	{
		k = 0;
		x = 0;
		while (k < data->w)
		{
			if (data->map[i][k] == '1')
			{
				data->img = mlx_xpm_file_to_image(data->mlx_ptr, "img/1.xpm", &c, &c);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, x, y);
			}
			else if (data->map[i][k] == '0')
			{
				data->img = mlx_xpm_file_to_image(data->mlx_ptr, "img/0.xpm", &c, &c);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, x, y);
			}
			k++;
			x += c;
		}
		i++;
		y += c;
	}
}
