/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:53:57 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/31 15:36:38 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	killed_enemie(t_long *var, t_cordinate p)
{
	if (var->map[p.y][p.x + 1] == 'Z')
	{
		var->map[p.y][p.x + 1] = '0';
		ft_printf("You killed the enemie!!\n");
	}
	else if (var->map[p.y][p.x - 1] == 'Z')
	{
		var->map[p.y][p.x - 1] = '0';
		ft_printf("You killed the enemie!!\n");
	}
}

void	handle_enemie(t_long *var, t_cordinate p)
{
	if (var->flag == 1)
	{
		var->flag = 3;
		killed_enemie(var, p);
	}
	else if (var->flag == 2)
	{
		var->flag = 4;
		killed_enemie(var, p);
	}
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)malloc(ft_strlen(str) + 1);
	if (ptr == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (s == 0)
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
