/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:16:25 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/29 11:58:05 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_player(t_long *var, int i, int j)
{
	if (var->flag == 2)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->player_left[var->frame], 60 * j, 60 * i);
	else if (var->flag == 1)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->player_right[var->frame], 60 * j, 60 * i);
	else
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->player_right[var->frame], 60 * j, 60 * i);
	return (0);
}

void	put_exit(t_long *var, int i, int j)
{
	if (var->count_c != 0)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->exit_close, 60 * j, 60 * i);
	else
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->exit_open, 60 * j, 60 * i);
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
				mlx_put_image_to_window(var->mlx, var->mlx_window,
					var->c[var->frame1], j * 60, i * 60);
			if (var->map[i][j] == 'E')
				put_exit(var, i, j);
		}
	}
}
