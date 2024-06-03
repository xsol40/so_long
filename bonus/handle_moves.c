/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:29:09 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/31 15:44:36 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	moves_right(t_long *var, t_cordinate p)
{
	if (var->map[p.y][p.x + 1] == 'Z')
		(ft_printf("You died"), close_window(var));
	if (var->map[p.y][p.x + 1] != '1' && var->map[p.y][p.x + 1] != 'E')
	{
		if (var->map[p.y][p.x + 1] == 'C')
			var->count_c--;
		var->map[p.y][p.x + 1] = 'P';
		var->map[p.y][p.x] = '0';
		var->moves++;
		ft_printf("You moved %d times.\n", var->moves);
	}
	if (var->map[p.y][p.x + 1] == 'E' && var->count_c == 0)
	{
		var->moves++;
		ft_printf("You moved %d times.\n", var->moves);
		ft_printf("You Win\n");
		var->map[p.y][p.x] = '0';
		close_window(var);
	}
}

void	moves_left(t_long *var, t_cordinate p)
{
	if (var->map[p.y][p.x - 1] == 'Z')
		(ft_printf("You died"), close_window(var));
	if (var->map[p.y][p.x - 1] != '1' && var->map[p.y][p.x - 1] != 'E')
	{
		if (var->map[p.y][p.x - 1] == 'C')
			var->count_c--;
		var->map[p.y][p.x - 1] = 'P';
		var->map[p.y][p.x] = '0';
		var->moves++;
		ft_printf("You moved %d times.\n", var->moves);
	}
	if (var->map[p.y][p.x - 1] == 'E' && var->count_c == 0)
	{
		var->moves++;
		ft_printf("You moved %d times.\n", var->moves);
		ft_printf("You Win\n");
		var->map[p.y][p.x] = '0';
		close_window(var);
	}
}

void	moves_up(t_long *var, t_cordinate p)
{
	if (var->map[p.y - 1][p.x] == 'Z')
		(ft_printf("You died"), close_window(var));
	if (var->map[p.y - 1][p.x] != '1' && var->map[p.y - 1][p.x] != 'E')
	{
		if (var->map[p.y - 1][p.x] == 'C')
			var->count_c--;
		var->map[p.y - 1][p.x] = 'P';
		var->map[p.y][p.x] = '0';
		var->moves++;
		ft_printf("You moved %d times.\n", var->moves);
	}
	if (var->map[p.y - 1][p.x] == 'E' && var->count_c == 0)
	{
		var->moves++;
		ft_printf("You moved %d times.\n", var->moves);
		ft_printf("You Win\n");
		var->map[p.y][p.x] = '0';
		close_window(var);
	}
}

void	moves_down(t_long *var, t_cordinate p)
{
	if (var->map[p.y + 1][p.x] == 'Z')
		(ft_printf("You died"), close_window(var));
	if (var->map[p.y + 1][p.x] != '1' && var->map[p.y + 1][p.x] != 'E')
	{
		if (var->map[p.y + 1][p.x] == 'C')
			var->count_c--;
		var->map[p.y + 1][p.x] = 'P';
		var->map[p.y][p.x] = '0';
		var->moves++;
		ft_printf("You moved %d times.\n", var->moves);
	}
	if (var->map[p.y + 1][p.x] == 'E' && var->count_c == 0)
	{
		var->moves++;
		ft_printf("You moved %d times.\n", var->moves);
		ft_printf("You Win\n");
		var->map[p.y][p.x] = '0';
		close_window(var);
	}
}

void	handle_moves(t_long *var, int keycode, t_cordinate p)
{
	if (keycode == 65363 || keycode == 100)
	{
		var->flag = 1;
		moves_right(var, p);
	}
	else if (keycode == 65361 || keycode == 97)
	{
		var->flag = 2;
		moves_left(var, p);
	}
	else if (keycode == 65362 || keycode == 119)
	{
		var->flag = 1;
		moves_up(var, p);
	}
	else if (keycode == 65364 || keycode == 115)
	{
		var->flag = 1;
		moves_down(var, p);
	}
	else if (keycode == 32)
		handle_enemie(var, p);
}
