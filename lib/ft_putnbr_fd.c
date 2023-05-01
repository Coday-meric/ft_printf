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

void	ft_putnbr_fdd(int n, int fd, int *len)
{
	char	nb;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2", fd, len);
		n = 147483648;
	}
	if (n < 0)
	{
		n = n * -1;
		ft_putchar_fd('-', fd, len);
	}
	if (n >= 10)
	{
		ft_putnbr_fdd(n / 10, fd, len);
		ft_putnbr_fdd(n % 10, fd, len);
	}
	else
	{
		nb = n + '0';
		ft_putchar_fd(nb, fd, len);
	}
}
