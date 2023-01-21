/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_min_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:04:03 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:05 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	ft_put_hex_min_nbr(unsigned int n, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_put_hex_min_nbr(n / 16, len);
	ft_putchar(hex[n % 16], len);
}
