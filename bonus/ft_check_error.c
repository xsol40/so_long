/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:46:04 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/31 15:43:50 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error(char *handle_error)
{
	perror(handle_error);
	exit (1);
}

void	ft_free(t_long *var)
{
	int	i;

	i = -1;
	while (++i < var->nbr_line)
		free(var->map[i]);
}

void	check_map_component(char **map, int nbr_line)
{
	int	i;
	int	j;

	i = 0;
	while (i < nbr_line)
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]) - 2)
		{
			if (map[i][j] != '1' && map[i][j] != '0' &&
					map[i][j] != 'C' && map[i][j] != 'P'
						&& map[i][j] != 'E' && map[i][j] != 'Z')
				error("Error invalid map component!!!\n");
			j++;
		}
		i++;
	}
}

void	check_number_of_component(t_long *var)
{
	if (var->count_p != 1)
		error("Error number of player invalid!!!\n");
	if (var->count_exit != 1)
		error("Error number of exit invalid!!!\n");
	if (var->count_c == 0)
		error("Error number of collectible invalid!!!\n");
	if (var->count_enemie == 0)
		error("Error number of enemie invalid!!!\n");
}

void	check_component(t_long *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->nbr_line)
	{
		j = 0;
		while (j < (int)ft_strlen(var->map[i]) - 2)
		{
			if (var->map[i][j] == 'P')
				var->count_p++;
			if (var->map[i][j] == 'E')
				var->count_exit++;
			if (var->map[i][j] == 'C')
				var->count_c++;
			if (var->map[i][j] == 'Z')
				var->count_enemie++;
			j++;
		}
		i++;
	}
	check_number_of_component(var);
}
