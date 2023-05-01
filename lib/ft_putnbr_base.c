/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:41:49 by amaisonn          #+#    #+#             */
/*   Updated: 2022/12/08 12:42:41 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_hexa(unsigned int nbr, char *base, int c, int *len)
{
	if (nbr >= 16)
	{
		ft_hexa(nbr / 16, base, c, len);
		ft_hexa(nbr % 16, base, c, len);
	}
	else
	{
		if (c == 0)
			ft_putchar_fd(ft_tolower(base[nbr]), 1, len);
		else if (c == 1)
			ft_putchar_fd(ft_toupper(base[nbr]), 1, len);
		else
			ft_putchar_fd(base[nbr], 1, len);
	}
}

void	ft_putnbr_base(unsigned int nbr, int c, int *len)
{
	unsigned int	nbrl;

	nbrl = nbr;
	ft_hexa(nbrl, "0123456789ABCDEF", c, len);
}
