/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <mel-hiak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:32:49 by mel-hiak          #+#    #+#             */
/*   Updated: 2024/05/23 14:11:27 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putnbr(long long n);
int	ft_putunbr(unsigned int n);
int	ft_putstr(char *str);
int	ft_lowerhexa(unsigned long n);
int	ft_upperhexa(unsigned int n);
int	ft_printf(const char *str, ...);

#endif