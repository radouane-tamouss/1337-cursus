/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:00:33 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/22 22:16:44 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// void	ft_putnbr_x(unsigned long long int nbr, char c)
// {
// 	char  	*base;
// 	int count;
// 	count = 0;
// 	if (c == 'x')
// 		base = "0123456789abcdef";
// 	else if (c == 'X')
// 		base = "0123456789ABCDEF";
// 	else if (c == 'u')
// 		base = "0123456789";
// 	if (nbr < 16)
// 	{
// 		write(1, &base[nbr], 1);
// 	}
// 	else
// 	{
// 		ft_putnbr_x(nbr / ft_strlen(base), c);
// 		ft_putnbr_x((nbr % ft_strlen(base)), c);
// 	}
// }

// void ft_putnbr_x(unsigned long long nbr, char c)
// {
//     char *base;
//     if (c == 'x')
//         base = "0123456789abcdef";
//     else if (c == 'X')
//         base = "0123456789ABCDEF";
//     else if (c == 'u')
//         base = "0123456789";

//     char buffer[50]; // Buffer to hold the result
//     int i = 0;

//     // Handle 0 explicitly to simplify the rest of the code
//     if (nbr == 0) {
//         write(1, &base[0], 1);
//         return ;
//     }

//     // Convert nbr to the specified base
//     while (nbr != 0) {
//         buffer[i++] = base[nbr % ft_strlen(base)];
//         nbr /= ft_strlen(base);
//     }

//     // The result is in buffer in reverse order, so print it backwards
//     while (--i >= 0)
//         write(1, &buffer[i], 1);
// }
static int	format2(va_list *args, const char format)
{
	void	*ptr;

	if (format == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	else if (format == 'x' || format == 'X')
		return (ft_putnbr_x(va_arg(*args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar_fd('%', 1));
	else if (format == 'u')
		return (ft_putnbr_x(va_arg(*args, unsigned int), 'u'));
	else if (format == 'p')
	{
		ptr = va_arg(*args, void *);
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

static int	format(va_list *args, const char format)
{
	char	*str;

	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	else if (format == 's')
	{
		str = va_arg(*args, char *);
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
			count += format(&args, s[i + 1]);
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

// int main(void)
// {
// 	int nb4 = 34;
// 	int *nb = &nb4;
// 	int count = 0;
// 	int count2 = 0;
// 	count = ft_printf("hello world %d , %s, %c, %d, %d, %x, %X, %i , %% , %u,
// %p\n", 92,"hello:", 'c', 380238202, 20923, 255, 2902, 234, 20839,
// nb);
// 	count2 = printf("hello world %d , %s, %c, %d, %d, %x, %X, %i , %% , %u,
// %p\n", 92, "hello:", 'c', 380238202, 20923, 255, 2902, 234, 20839,
// nb);
// 	ft_printf("count = %d\n", count);
// 	ft_printf("count2 = %d", count2);
// 	return (0);
// }