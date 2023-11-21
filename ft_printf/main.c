/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:00:33 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/21 10:29:56 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ft_printf.h"
#include <stdarg.h>


static int	count_digits(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
void	ft_putnbr_x(unsigned long long int nbr, char c)
{
	char  	*base;
	int count;
	count = 0;
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
//         return;
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

int format(va_list *args, const char format)
{
	if(format == 'd' || format == 'i')
	{
		int num = va_arg(*args,int);
		ft_putnbr_fd(num, 1);
		return (count_digits(num));
	}
	else if(format == 's')
	{
		char *str = va_arg(*args,char *);
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));	
	}
	else if (format == 'c')
	{
		ft_putchar_fd(va_arg(*args,int), 1);
		return (1);
	}
	else if (format == 'x')
	{
		ft_putnbr_x(va_arg(*args,unsigned int), 'x');
		return (1);
	}
	else if (format == 'X')
	{
		ft_putnbr_x(va_arg(*args,unsigned int), 'X');
		return (1);
	}
	else if (format == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (format == 'u')
	{
		ft_putnbr_x(va_arg(*args,unsigned int), 'u');
		return (1);
	}
	else if (format == 'p')
    {
		void* ptr = va_arg(*args, void*);
		if (ptr == NULL)
		{
			write(1, "(nil)", 5);
		}
		else
		{
			write(1, "0x", 2); // Prefix for hexadecimal numbers
			ft_putnbr_x((unsigned long long)ptr, 'x'); // Print the pointer value as a 64-bit hexadecimal number
		}
		return (1);
	}
	else 
		return (-1);
}


int ft_printf(const char *s, ...)
{
	int i = 0;
	va_list args;
	int count = 0;
	va_start(args,s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("%dcsuixpX",s[ i + 1 ]) != NULL)
		{
			count += format(&args, s[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(s[i],1);
			count++;
		}
		i++;
	}
	return (count);
}

int main(void)
{
	int nb4 = 34;
	int *nb = &nb4;
	ft_printf("hello world %d , %s, %c, %d, %d, %x, %X, %i , %% , %u, %p\n", 92,"hello:", 'c', 380238202, 20923, 255, 2902, 234, 20839, nb);
	printf("hello world %d , %s, %c, %d, %d, %x, %X, %i , %% , %u, %p\n", 92, "hello:", 'c', 380238202, 20923, 255, 2902, 234, 20839, nb);
	return (0);
}