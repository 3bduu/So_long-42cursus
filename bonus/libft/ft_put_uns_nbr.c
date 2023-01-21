/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:24:03 by abenlahb          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:10 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	ft_put_uns_nbr(unsigned int n, int *len)
{
	if (n >= 10)
		ft_put_uns_nbr(n / 10, len);
	ft_putchar(((n % 10) + '0'), len);
}
