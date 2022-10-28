/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:02:18 by arecce            #+#    #+#             */
/*   Updated: 2022/10/28 17:48:15 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(void)
{
	ft_printf("Error\nManco una mappa sai disegnare...\n");
	exit(0);
}

void	map_memory(t_data *data)
{
	// int	i;

	// i = 0;
	data->map = malloc(sizeof(char **) * data->h);
	// while (i < data->h)
	// {
	// 	data->map[i] = malloc(sizeof(char *) * data->w + 1);
	// 	i++;
	// }
}

void	map_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->h)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
