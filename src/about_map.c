/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:32:13 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/29 15:58:26 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_extention(char *str)
{
	int		start;
	char	*extention;

	start = ft_strlen(str) - 4;
	extention = ft_substr(str, start, 4);
	if (ft_strcmp(".ber", extention) || ft_strlen(str) == 4)
	{
		free(extention);
		error("Error extention must be .ber!!!\n");
	}
	free(extention);
}

int	get_nbr_line(char *map_file)
{
	int		nbr_line;
	int		fd;
	char	*line;

	nbr_line = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error("Error open file!!\n");
	line = get_next_line(fd);
	while (line)
	{
		nbr_line++;
		free(line);
		line = get_next_line(fd);
	}
	if (nbr_line == 0)
		error("Error empty map's file!!\n");
	close (fd);
	return (nbr_line);
}

char	**read_file(char *map_file, t_long *var)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error("open file!!\n");
	var->map = (char **)malloc(sizeof(char *) * var->nbr_line + 1);
	if (!var->map)
		return (NULL);
	while (i < var->nbr_line)
	{
		var->map[i] = get_next_line(fd);
		i++;
	}
	return (var->map);
}

void	check_map_form(char **map, int nbr_line)
{
	int	size_first_line;
	int	i;

	i = 1;
	size_first_line = (int)ft_strlen(map[0]);
	while (i < nbr_line - 1)
	{
		if ((int)ft_strlen(map[i]) != size_first_line)
			error("Error map form inavalid!!\n");
		i++;
	}
	if ((int) ft_strlen(map[i]) != size_first_line - 1)
		error("Error map form invalid!!\n");
}

void	check_map_walls(char **map, int nbr_line)
{
	int	i;
	int	j;
	int	size_line;

	i = 0;
	size_line = (int)ft_strlen(map[0]) - 1;
	while (i < nbr_line)
	{
		j = 0;
		while (j < size_line)
		{
			if ((map[0][j] != '1' || map[nbr_line - 1][j] != '1') ||
					(map[i][0] != '1' || map[i][size_line - 1] != '1'))
				error("Error map's wals not valid!!\n");
			j++;
		}
		i++;
	}
}
