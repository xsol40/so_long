/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upperhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:45:26 by mel-hiak          #+#    #+#             */
/*   Updated: 2023/11/30 15:51:53 by mel-hiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upperhexa(unsigned int n)
{
	int		r;
	char	*base;

	r = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
		r += ft_upperhexa(n / 16);
	r += ft_putchar(base[n % 16]);
	return (r);
}
