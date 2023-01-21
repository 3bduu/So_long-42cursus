/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:08:17 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:57:59 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	ft_put_address(unsigned long n, int *len)
{
	static int	i;
	char		*hex;

	hex = "0123456789abcdef";
	i += 0;
	if (i == 0)
		ft_putstr("0x", len);
	i++;
	if (n >= 16)
		ft_put_address(n / 16, len);
	ft_putchar(hex[n % 16], len);
	i = 0;
}
