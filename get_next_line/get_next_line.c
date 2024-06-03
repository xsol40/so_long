/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:36:58 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/31 14:30:49 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	char	*s;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	s = malloc (sizeof(char) * (ft_strlen(str) - i + 1));
	if (!s)
		return (NULL);
	j = 0;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free (str);
	return (s);
}

char	*ft_put_str(char *str, char *buffer)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			buffer[i++] = '\n';
			buffer[i] = '\0';
			return (buffer);
		}
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*buffer;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	buffer = malloc(sizeof(char) * i + 1);
	if (!buffer)
		return (NULL);
	buffer = ft_put_str(str, buffer);
	return (buffer);
}

char	*read_file1(char *str, int fd)
{
	ssize_t	read_byte;
	char	*res;

	res = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!res)
		return (NULL);
	read_byte = -1;
	while (!ft_strchr(str, '\n') && read_byte != 0)
	{
		read_byte = read (fd, res, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free (res);
			free (str);
			return (NULL);
		}
		res[read_byte] = '\0';
		str = ft_strjoin(str, res);
	}
	free (res);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = read_file1(str, fd);
	if (str == NULL)
		return (NULL);
	buffer = ft_get_line (str);
	str = ft_next_line (str);
	return (buffer);
}
