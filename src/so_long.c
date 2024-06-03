/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:11:33 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/31 15:48:06 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_player_frame(t_long *var)
{
	var->frame_counter++;
	if (var->frame_counter >= var->frame_delay)
	{
		var->frame_counter = 0;
		var->frame = (var->frame + 1) % 6;
		var->frame1 = (var->frame1 + 1) % 2;
		put_image_to_win(var);
	}
	return (0);
}

void	init_util(t_long *var)
{
	var->moves = 0;
	var->nbr_line = 0;
	var->map = 0;
	var->frame = 0;
	var->frame1 = 0;
	var->flag = 1;
	var->count = 0;
	var->exit = 0;
	var->new_map = NULL;
}

void	lets_play(t_long var)
{
	var.mlx = mlx_init();
	var.mlx_window = mlx_new_window(var.mlx, ((int)ft_strlen(var.map[0]) - 1)
			* 60, var.nbr_line * 60, "so_long");
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
