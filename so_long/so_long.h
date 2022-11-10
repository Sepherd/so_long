/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:38:47 by arecce            #+#    #+#             */
/*   Updated: 2022/11/10 18:36:52 by arecce           ###   ########.fr       */
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
	int		en_y;
	int		en_x;
	void	*mlx;
}				t_ex;

typedef struct s_d {
	void	*img;
	void	*mlx;
	void	*win;
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
}				t_d;

size_t	gnl_strlen(char *str);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_reading(int fd, char *save);
char	*ft_get_line(char *save);
char	*ft_backup(char *save);
char	*get_next_line(int fd);
void	get_dim(char **av, t_d *d);
void	square(t_d *d);
void	line_check(char **av, t_d *d);
void	map_error(void);
void	check_ber(char **av);
void	len_check(char **av, t_d *d);
int		total_count(t_d *d, char t);
void	control_total(t_d *d);
void	get_map(char **av, t_d *d);
void	img_init(t_d *d);
void	check_utils(t_d *d, int i, int k, char *line);
void	map_free(t_d *d);
void	draw_map(t_d *d);
void	draw_pg(t_d *d);
void	draw_clt(t_d *d);
void	draw_exit(t_d *d);
void	draw_enemy(t_d *d);
void	draw_all(t_d *d);
int		exit_an(t_d *d);
void	p_pos(t_d *d);
void	e_pos(t_d *d);
void	movement(t_d *d, int keycode);
void	front_move(t_d *d);
void	left_move(t_d *d);
void	back_move(t_d *d);
void	right_move(t_d *d);
void	win(t_d *d);
void	close_game(t_d *d);
void	print_move(t_d *d);
void	print_lose(t_d *d);
void	print_win(void);
void	refresh_map(t_d *d);
void	draw_floor(t_d *d);
void	en_pos(t_d *d);
void	en_move(t_d *d);
void	en_move_d(t_d *d);
void	enemy_left(t_d *d);
void	enemy_right(t_d *d);
void	enemy_front(t_d *d);
void	enemy_back(t_d *d);

#endif