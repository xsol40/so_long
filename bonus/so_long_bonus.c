/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:36:13 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/31 15:44:20 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	update_player_frame(t_long *var)
{
	char	*str;
	char	*str1;

	var->frame_counter++;
	if (var->frame_counter >= var->frame_delay)
	{
		var->frame_counter = 0;
		var->temp = (var->temp + 1) % 6;
		var->temp1 = (var->temp1 + 1) % 2;
		var->temp2 = (var->temp2 + 1) % 4;
		put_image_to_win(var);
		str = ft_itoa(var->moves);
		str1 = ft_strjoin(ft_strdup("Moves: "), str);
		mlx_string_put(var->mlx, var->mlx_window, 32, 20, 0X00FF00FF, str1);
		free(str1);
		free(str);
	}
	return (0);
}

void	init_util(t_long *var)
{
	var->map = 0;
	var->nbr_line = 0;
	var->temp = 0;
	var->temp2 = 0;
	var->temp1 = 0;
	var->count = 0;
	var->exit = 0;
	var->enemie_c = 0;
	var->new_map = NULL;
	var->count_c = 0;
	var->count_p = 0;
	var->count_exit = 0;
	var->count_enemie = 0;
	var->flag = 1;
	var->moves = 0;
}

void	lets_play(t_long var)
{
	var.mlx = mlx_init();
	var.mlx_window = mlx_new_window(var.mlx, ((int)ft_strlen(var.map[0]) - 1)
			* 60, var.nbr_line * 60, "so_long_bonus");
	get_data(&var);
	put_image_to_win(&var);
	mlx_loop_hook(var.mlx, update_player_frame, &var);
	mlx_key_hook(var.mlx_window, key_hook, &var);
	mlx_hook(var.mlx_window, 17, 0, close_window, &var);
	mlx_hook(var.mlx_window, 2, 1L << 0, esc_window, &var);
	mlx_loop(var.mlx);
}

int	main(int argc, char **argv)
{
	t_long	var;

	init_util(&var);
	if (argc != 2)
		error("Invaid argument!!\n");
	ft_check_extention(argv[1]);
	var.nbr_line = get_nbr_line(argv[1]);
	var.map = read_file(argv[1], &var);
	check_map_form(var.map, var.nbr_line);
	check_map_walls(var.map, var.nbr_line);
	check_map_component(var.map, var.nbr_line);
	check_component(&var);
	flood_fill(&var);
	lets_play(var);
}
