/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:38:47 by arecce            #+#    #+#             */
/*   Updated: 2022/10/27 18:45:38 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "libft/libft.h"
# include <mlx.h>

// typedef struct s_stack
// {
// 	int		*stack;
// 	int		size;
// 	int		pos_min;
// 	int		pos_max;
// 	int		value;
// 	int		index;
// 	int		pos;
// 	int		target_pos;
// 	int		cost_a;
// 	int		cost_b;
// 	char	***arg;
// }				t_stack;

typedef struct s_data {
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		m_move;
	char	**map;
	int		h;
	int		w;
}				t_data;

size_t	gnl_strlen(char *str);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_reading(int fd, char *save);
char	*ft_get_line(char *save);
char	*ft_backup(char *save);
char	*get_next_line(int fd);
void	get_dim(char **av, t_data *data);
void	line_check(char **av, t_data *data);
void	map_error(void);
void	len_check(char **av, t_data *data);
void	get_map(char **av, t_data *data);
void	map_memory(t_data *data);
void	map_free(t_data *data);
void    draw_map(t_data *data);

#endif