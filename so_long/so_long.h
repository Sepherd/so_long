/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:38:47 by arecce            #+#    #+#             */
/*   Updated: 2022/11/03 16:39:37 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
// # endif

# include "libft/libft.h"
# include <mlx.h>
# include <time.h>

typedef struct s_pg {
	char	dir;
	int		pos_x;
	int		pos_y;
	int		clt_tot;
	int		ex_tot;
	int		pg_tot;
}				t_pg;

typedef struct s_ex {
	int		pos_x;
	int		pos_y;
}				t_ex;

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
	void	*floor;
	void	*wall;
	void	*clt;
	void	*pg;
	void	*exit;
	void	*enemy;
	t_pg	p;
	t_ex	e;
}				t_data;

size_t	gnl_strlen(char *str);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_reading(int fd, char *save);
char	*ft_get_line(char *save);
char	*ft_backup(char *save);
char	*get_next_line(int fd);
void	get_dim(char **av, t_data *data);
void	square(t_data *data);
void	line_check(char **av, t_data *data);
void	map_error(void);
void	check_ber(char **av);
void	len_check(char **av, t_data *data);
int		total_count(t_data *data, char t);
void	control_total(t_data *data);
void	get_map(char **av, t_data *data);
void	img_init(t_data *data);
void	map_memory(t_data *data);
void	map_free(t_data *data);
void	draw_map(t_data *data);
void	draw_pg(t_data *data);
void	draw_clt(t_data *data);
void	draw_exit(t_data *data);
void	draw_enemy(t_data *data);
void	draw_all(t_data *data);
int		exit_an(t_data *data);
int		enemy_an(t_data *data);
void	pg_an(t_data *data);
void	p_pos(t_data *data);
void	e_pos(t_data *data);
void	front_move(t_data *data);
void	left_move(t_data *data);
void	back_move(t_data *data);
void	right_move(t_data *data);
void	win(t_data *data);
void	close_game(t_data *data);
void	print_move(t_data *data);

#endif