/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowerhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:03:40 by mel-hiak          #+#    #+#             */
/*   Updated: 2023/12/03 11:03:42 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowerhexa(unsigned long n)
{
	int		r;
	char	*base;

	r = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		r += ft_lowerhexa(n / 16);
	r += ft_putchar(base[n % 16]);
	return (r);
}
