/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:49:25 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/23 19:03:07 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_x(unsigned long long nbr, char c)
{
	char	*base;
	int		count;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == 'u')
		base = "0123456789";
	if (nbr < ft_strlen(base))
	{
		count++;
		write(1, &base[nbr], 1);
	}
	else
	{
		count += ft_putnbr_x(nbr / ft_strlen(base), c);
		count += ft_putnbr_x((nbr % ft_strlen(base)), c);
	}
	return (count);
}
