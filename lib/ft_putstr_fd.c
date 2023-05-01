/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:58:32 by amaisonn          #+#    #+#             */
/*   Updated: 2023/02/13 23:15:14 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int *len)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1, len);
		return ;
	}
	while (*s)
	{
		ft_putchar_fd(*s, fd, len);
		s++;
	}
}
