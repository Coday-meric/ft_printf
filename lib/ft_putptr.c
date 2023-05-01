/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:18:23 by amaisonn          #+#    #+#             */
/*   Updated: 2023/02/24 13:18:32 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_ptrhex(uintptr_t nb, int *len)
{
	if (nb >= 16)
	{
		ft_ptrhex(nb / 16, len);
		ft_ptrhex(nb % 16, len);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + 48), 1, len);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1, len);
	}
}

void	ft_putptr(unsigned long long nb, int *len)
{
	if (nb == 0)
		ft_putstr_fd("(nil)", 1, len);
	else
	{
		ft_putstr_fd("0x", 1, len);
		ft_ptrhex(nb, len);
	}
}
