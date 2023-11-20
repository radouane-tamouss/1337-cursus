/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:00:33 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/20 21:37:21 by rtamouss         ###   ########.fr       */
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
		if (s[i] == '%' && ft_strchr("%dcsuixX",s[ i + 1 ]) != NULL)
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
	int nb = 0;
	nb = ft_printf("hello world %d , %s, %c, %d, %d, %x, %X, %i , %%, %u\n", 92,"hello:", 'c', 380238202, 20923, 255, 2902, 234, 20839);
	printf("hello world %d , %s, %c, %d, %d, %x, %X, %i , %% , %u\n", 92, "hello:", 'c', 380238202, 20923, 255, 2902, 234, 20839);
	ft_printf("\n the numer returned is : %d", nb);
	return (0);
}