/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:08:57 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/31 15:45:56 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_long *var)
{
	int		i;

	i = -1;
	var->new_map = (char **)malloc(sizeof(char *) * var->nbr_line + 1);
	if (!var->new_map)
		exit(1);
	while (++i < var->nbr_line)
	{
		var->new_map[i] = ft_strdup(var->map[i]);
	}
	return (var->new_map);
}

void	fill(int x, int y, t_long *var)
{
	if (var->new_map[x][y] == 'P' || var->new_map[x][y] == '0'
			|| var->new_map[x][y] == 'C' || var->new_map[x][y] == 'E')
	{
		if (var->new_map[x][y] == 'C')
			var->count++;
		else if (var->new_map[x][y] == 'E')
		{
			var->exit++;
			return ;
		}
		var->new_map[x][y] = '1';
		fill(x + 1, y, var);
		fill(x - 1, y, var);
		fill(x, y + 1, var);
		fill(x, y - 1, var);
	}
	else
		return ;
}

void	flood_fill(t_long *var)
{
	int		x;
	int		y;

	x = 0;
	var->new_map = copy_map(var);
	while (++x < var->nbr_line - 1)
	{
		y = 0;
		while (++y < (int)ft_strlen(var->new_map[x]) - 1)
		{
			if (var->new_map[x][y] == 'P')
				fill(x, y, var);
		}
	}
	if (!(var->count == var->count_c && var->exit > 0))
	{
		if (var->count != var->count_c)
			error("Error not all collectible are reachable!!\n");
		else if (var->exit == 0)
			error("Error exit is not reachable!!\n");
	}
}
