/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:23:02 by arecce            #+#    #+#             */
/*   Updated: 2022/10/31 17:01:09 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_anim(t_data *data)
{
	int	c = 65;

	if (data->m_move % 12)
		data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "img/x1.xpm", &c, &c);
	else
		data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "img/x2.xpm", &c, &c);
}
