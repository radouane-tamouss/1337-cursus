/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:00:33 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/23 19:17:42 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format2(va_list args, const char format)
{
	void	*ptr;

	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (format == 'x' || format == 'X')
		return (ft_putnbr_x(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar_fd('%', 1));
	else if (format == 'u')
		return (ft_putnbr_x(va_arg(args, unsigned int), 'u'));
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
		{
			write(1, "0x0", 3);
			return (3);
		}
		else
		{
			write(1, "0x", 2);
			return (2 + ft_putnbr_x((unsigned long long)ptr, 'x'));
		}
	}
	return (0);
}

static int	format(va_list args, const char format)
{
	char	*str;

	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (format == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			return (ft_putstr_fd("(null)", 1));
		else
			return (ft_putstr_fd(str, 1));
	}
	else
		return (format2(args, format));
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("%dcsuixpX", s[i + 1]) != NULL)
		{
			count += format(args, s[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
