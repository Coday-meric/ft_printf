/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:05:31 by amaisonn          #+#    #+#             */
/*   Updated: 2023/02/13 23:25:01 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_unsign_fd(unsigned int n, int fd, int *len)
{
	char	nb;

	if (n >= 10)
	{
		ft_putnbr_unsign_fd(n / 10, fd, len);
		ft_putnbr_unsign_fd(n % 10, fd, len);
	}
	else
	{
		nb = n + '0';
		ft_putchar_fd(nb, fd, len);
	}
}
