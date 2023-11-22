/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:40:35 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/22 16:14:47 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count++;
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr < 10)
		count += ft_putchar_fd(nbr + '0', fd);
	else
	{
		count += ft_putnbr_fd(nbr / 10, fd);
		count += ft_putchar_fd((nbr % 10) + '0', fd);
	}
	return (count);
}
