/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_to_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:31:24 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/31 15:45:05 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_player(t_long *var, int i, int j)
{
	if (var->flag == 2)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->player_left[var->temp], 60 * j, 60 * i);
	else if (var->flag == 1)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->player_right[var->temp], 60 * j, 60 * i);
	else if (var->flag == 3)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->player_attack_right[var->temp], 60 * j, 60 * i);
	else if (var->flag == 4)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->player_attack_left[var->temp], 60 * j, 60 * i);
	return (0);
}

void	put_exit(t_long *var, int i, int j)
{
	if (var->count_c != 0)
	{
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->exit_close, 60 * j, 60 * i);
	}
	else
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->exit_open, 60 * j, 60 * i);
}

void	put_collectible(t_long *var, int i, int j)
{
	mlx_put_image_to_window(var->mlx, var->mlx_window,
		var->c[var->temp1], j * 60, i * 60);
}

void	put_enemie(t_long *var, int i, int j)
{
	if (var->flag == 2)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->enemie_right[var->temp2], 60 * j, 60 * i);
	else if (var->flag == 1)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->enemie_left[var->temp2], 60 * j, 60 * i);
	else
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->enemie_right[var->temp2], 60 * j, 60 * i);
}

void	put_image_to_win(t_long *var)
{
	int	i;
	int	j;

	i = -1;
	while (++i < var->nbr_line)
	{
		j = -1;
		while (++j < (int)ft_strlen(var->map[i]))
		{
			if (var->map[i][j] == '1')
				mlx_put_image_to_window(var->mlx, var->mlx_window,
					var->wall, j * 60, i * 60);
			if (var->map[i][j] == '0')
				mlx_put_image_to_window(var->mlx, var->mlx_window,
					var->black, j * 60, i * 60);
			if (var->map[i][j] == 'P')
				put_player(var, i, j);
			if (var->map[i][j] == 'C')
				put_collectible(var, i, j);
			if (var->map[i][j] == 'E')
				put_exit(var, i, j);
			if (var->map[i][j] == 'Z')
				put_enemie(var, i, j);
		}
	}
}
