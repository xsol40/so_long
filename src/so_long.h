/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:24:56 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/28 21:48:30 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	int		frame_delay;
	int		frame;
	int		frame1;
	int		frame_counter;
	void	*c[2];
	void	*black;
	void	*wall;
	void	*exit_open;
	void	*exit_close;
	int		count_c;
	int		count_p;
	int		count_exit;
	int		count;
	int		exit;
	int		flag;
}	t_long;

typedef struct s_cordinate
{
	int	x;
	int	y;
}	t_cordinate;

// Utility functions
int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);

//parsing to validate maps file
void	ft_check_extention(char *str);
void	check_map_form(char **map, int nbr_line);
void	check_map_walls(char **map, int nbr_line);
void	check_map_component(char **map, int nbr_line);
void	check_component(t_long *var);
char	**read_file(char *map_file, t_long *var);
int		get_nbr_line(char *map_file);
void	flood_fill(t_long *var);

//util map
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);

//annimation handling
void	get_data(t_long *var);
void	put_image_to_win(t_long *var);
int		key_hook(int keycode, t_long *var);
void	handle_moves(t_long *var, int keycode, t_cordinate p);

//function to handle window
int		esc_window(int keycode, t_long *var);
int		close_window(t_long *var);

//error handling
void	error(char *error_name);

void	ft_free(t_long *var);

#endif