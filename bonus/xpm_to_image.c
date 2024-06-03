/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:30 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/31 19:22:14 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_data_palyer_right(t_long *var, int x, int y)
{
	var->player_right[0] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_r/p1.xpm", &x, &y);
	var->player_right[1] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_r/p2.xpm", &x, &y);
	var->player_right[2] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_r/p3.xpm", &x, &y);
	var->player_right[3] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_r/p4.xpm", &x, &y);
	var->player_right[4] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_r/p5.xpm", &x, &y);
	var->player_right[5] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_r/p6.xpm", &x, &y);
}

void	get_data_palyer_left(t_long *var, int x, int y)
{
	var->player_left[0] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_lef/p1l.xpm", &x, &y);
	var->player_left[1] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_lef/p2l.xpm", &x, &y);
	var->player_left[2] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_lef/p3l.xpm", &x, &y);
	var->player_left[3] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_lef/p4l.xpm", &x, &y);
	var->player_left[4] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_lef/p5l.xpm", &x, &y);
	var->player_left[5] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_lef/p6l.xpm", &x, &y);
}

void	get_data_enemie(t_long *var, int x, int y)
{
	var->enemie_right[0] = mlx_xpm_file_to_image(var->mlx,
			"./textures/enemie_right/z1.xpm", &x, &y);
	var->enemie_right[1] = mlx_xpm_file_to_image(var->mlx,
			"./textures/enemie_right/z2.xpm", &x, &y);
	var->enemie_right[2] = mlx_xpm_file_to_image(var->mlx,
			"./textures/enemie_right/z3.xpm", &x, &y);
	var->enemie_right[3] = mlx_xpm_file_to_image(var->mlx,
			"./textures/enemie_right/z4.xpm", &x, &y);
	var->enemie_left[0] = mlx_xpm_file_to_image(var->mlx,
			"./textures/enemie_left/z1.xpm", &x, &y);
	var->enemie_left[1] = mlx_xpm_file_to_image(var->mlx,
			"./textures/enemie_left/z2.xpm", &x, &y);
	var->enemie_left[2] = mlx_xpm_file_to_image(var->mlx,
			"./textures/enemie_left/z3.xpm", &x, &y);
	var->enemie_left[3] = mlx_xpm_file_to_image(var->mlx,
			"./textures/enemie_left/z4.xpm", &x, &y);
}

void	get_data_player_attack(t_long *var, int x, int y)
{
	var->player_attack_right[0] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_attack_right/p1.xpm", &x, &y);
	var->player_attack_right[1] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_attack_right/p2.xpm", &x, &y);
	var->player_attack_right[2] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_attack_right/p3.xpm", &x, &y);
	var->player_attack_right[3] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_attack_right/p4.xpm", &x, &y);
	var->player_attack_right[4] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_attack_right/p5.xpm", &x, &y);
	var->player_attack_right[5] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_attack_right/p6.xpm", &x, &y);
	var->player_attack_left[0] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_attack_left/p1.xpm", &x, &y);
	var->player_attack_left[1] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_attack_left/p2.xpm", &x, &y);
	var->player_attack_left[2] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_attack_left/p3.xpm", &x, &y);
	var->player_attack_left[3] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_attack_left/p4.xpm", &x, &y);
	var->player_attack_left[4] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_attack_left/p5.xpm", &x, &y);
	var->player_attack_left[5] = mlx_xpm_file_to_image(var->mlx,
			"./textures/player_attack_left/p6.xpm", &x, &y);
}

void	get_data(t_long *var)
{
	int	x;
	int	y;

	x = 30;
	y = 30;
	get_data_palyer_right(var, x, y);
	get_data_palyer_left(var, x, y);
	get_data_enemie(var, x, y);
	get_data_player_attack(var, x, y);
	var->black = mlx_xpm_file_to_image(var->mlx,
			"./textures/black.xpm", &x, &y);
	var->c[0] = mlx_xpm_file_to_image(var->mlx, "./textures/c.xpm", &x, &y);
	var->c[1] = mlx_xpm_file_to_image(var->mlx, "./textures/c1.xpm", &x, &y);
	var->exit_close = mlx_xpm_file_to_image(var->mlx,
			"./textures/exit_close.xpm", &x, &y);
	var->exit_open = mlx_xpm_file_to_image(var->mlx,
			"./textures/exit_open.xpm", &x, &y);
	var->wall = mlx_xpm_file_to_image(var->mlx, "./textures/wall.xpm", &x, &y);
	var->frame_delay = 40000;
	var->frame_counter = 0;
}
