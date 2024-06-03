/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:39:30 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/31 15:42:33 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_long
{
	void	*mlx;
	void	*mlx_window;
	int		nbr_line;
	char	**map;
	char	**new_map;
	int		moves;
	void	*player_right[6];
	void	*player_left[6];
	void	*enemie_left[4];
	void	*enemie_right[4];
	void	*player_attack_right[6];
	void	*player_attack_left[6];
	int		frame_delay;
	int		temp;
	int		temp2;
	int		temp1;
	int		frame_counter;
	void	*c[2];
	void	*black;
	void	*wall;
	void	*exit_open;
	void	*exit_close;
	int		count_c;
	int		count_p;
	int		count_exit;
	int		count_enemie;
	int		count;
	int		exit;
	int		enemie_c;
	int		flag;
}	t_long;

typedef struct s_cordinate
{
	int	x;
	int	y;
}	t_cordinate;

int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);

void	ft_check_extention(char *str);
int		get_nbr_line(char *map_file);
char	**read_file(char *map_file, t_long *var);
void	check_map_form(char **map, int nbr_line);
void	check_map_walls(char **map, int nbr_line);
void	check_map_component(char **map, int nbr_line);
void	check_component(t_long *var);
void	flood_fill(t_long *var);

void	get_data(t_long *var);
void	put_image_to_win(t_long *var);
void	handle_moves(t_long *var, int keycode, t_cordinate p);
int		key_hook(int keycode, t_long *var);
void	handle_enemie(t_long *var, t_cordinate p);

int		close_window(t_long *var);
int		esc_window(int keycode, t_long *var);

void	error(char *handle_error);

void	ft_free(t_long *var);

#endif