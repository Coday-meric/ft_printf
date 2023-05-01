/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:50:05 by amaisonn          #+#    #+#             */
/*   Updated: 2023/02/23 16:59:20 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_sort(char c, va_list printlist, int *len)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(printlist, int), 1, len);
	else if (c == 's')
		ft_putstr_fd(va_arg(printlist, char *), 1, len);
	else if (c == 'p')
		ft_putptr(va_arg(printlist, long long int), len);
	else if (c == 'd')
		ft_putnbr_fdd(va_arg(printlist, int), 1, len);
	else if (c == 'i')
		ft_putnbr_fdd(va_arg(printlist, int), 1, len);
	else if (c == 'u')
		ft_putnbr_unsign_fd(va_arg(printlist, unsigned int), 1, len);
	else if (c == 'x')
		ft_putnbr_base(va_arg(printlist, unsigned int), 0, len);
	else if (c == 'X')
		ft_putnbr_base(va_arg(printlist, unsigned int), 1, len);
	else if (c == '%')
		ft_putchar_fd('%', 1, len);
}

int	ft_printf(const char *str, ...)
{
	va_list		printlist;
	size_t		i;
	int			len;

	i = 0;
	len = 0;
	va_start(printlist, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_fd(str[i], 1, &len);
		else
		{
			ft_printf_sort(str[i + 1], printlist, &len);
			i++;
		}
		i++;
	}
	va_end(printlist);
	return (len);
}
