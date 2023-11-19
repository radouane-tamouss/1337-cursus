/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:00:33 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/19 22:26:03 by rtamouss         ###   ########.fr       */
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

int ft_case(va_list args, const char format)
{
	if(format == 'd')
	{
		int num = va_arg(args,int);
		ft_putnbr_fd(num, 1);
		return (count_digits(num));
	}
	else if(format == 's')
	{
		char *str = va_arg(args,char *);
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));	
	}
	else
	{
		ft_putchar_fd(va_arg(args,int), 1);
		return (1);	
	}
}

int ft_printf(const char *s, ...)
{
	int i = 0;
	va_list args;
	int count = 0;
	va_start(args,s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("dcs",s[ i + 1 ]) != NULL)
		{
			count += ft_case(args, s[i + 1]);
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
	nb = ft_printf("hello world %d , %s, %c, %d, %d\n", 92, "hello", 'c', 380238202, 20923);
	ft_printf("\n the numer returned is : %d", nb);
	return (0);
}