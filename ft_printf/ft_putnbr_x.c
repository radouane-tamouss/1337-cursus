/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:49:25 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/20 22:28:23 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_x(unsigned int nbr, char c)
{
	char  	*base;
	int count;
	count = 0;
	if (c == 'p')
	{
		write(1, "0x", 2);
	}
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == 'u')
		base = "0123456789";
	if (nbr < 16)
	{
		write(1, &base[nbr], 1);
	}
	else
	{
		ft_putnbr_x(nbr / ft_strlen(base), c);
		ft_putnbr_x((nbr % ft_strlen(base)), c);
	}
}