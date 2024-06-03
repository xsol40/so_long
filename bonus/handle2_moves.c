/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle2_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:29:37 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/31 15:42:13 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_long *var)
{
	mlx_destroy_window(var->mlx, var->mlx_window);
	free(var->mlx);
	ft_free(var);
	exit(1);
}

int	esc_window(int keycode, t_long *var)
{
	if (keycode == XK_Escape)
	{
		ft_printf("Game Over\n");
		close_window(var);
	}
	return (0);
}

t_cordinate	get_cordinate(t_long *var, char point)
{
	int			i;
	int			j;
	t_cordinate	c;

	i = -1;
	while (++i < var->nbr_line)
	{
		j = -1;
		while (++j < ((int)ft_strlen(var->map[i]) - 2))
		{
			if (var->map[i][j] == point)
			{
				c.x = j;
				c.y = i;
			}
		}
	}
	return (c);
}

int	key_hook(int keycode, t_long *var)
{
	t_cordinate	p;

	p = get_cordinate(var, 'P');
	handle_moves(var, keycode, p);
	put_image_to_win(var);
	return (1);
}
