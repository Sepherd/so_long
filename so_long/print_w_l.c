/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_w_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:21:02 by arecce            #+#    #+#             */
/*   Updated: 2022/11/04 15:46:45 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_lose(void)
{
	int		fd;
	char	*lose;

	fd = open("txt/lose.txt", O_RDONLY);
	lose = get_next_line(fd);
	while (lose != NULL)
	{
		ft_printf("\033[1;31m%s\033[1;0m", lose);
		free(lose);
		lose = get_next_line(fd);
	}
	ft_printf("\n");
	free(lose);
	close(fd);
}

void	print_win(void)
{
	int		fd;
	char	*win;

	fd = open("txt/win.txt", O_RDONLY);
	win = get_next_line(fd);
	while (win != NULL)
	{
		ft_printf("\033[1;32m%s\033[1;0m", win);
		free(win);
		win = get_next_line(fd);
	}
	ft_printf("\n");
	free(win);
	close(fd);
}
