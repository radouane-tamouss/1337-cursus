/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:00:33 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/19 21:18:57 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ft_printf.h"
#include <stdarg.h>

void ft_case(va_list args, const char format)
{
	if(format == 'd')
		ft_putnbr_fd(va_arg(args,int), 1);
	else if(format == 's')
		ft_putstr_fd(va_arg(args,char *), 1);
	else
		ft_putchar_fd(va_arg(args,int), 1);
}

void ft_printf(const char *s, ...)
{
	int i = 0;
	va_list args;
	va_start(args,s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("dcs",s[ i + 1 ]) != NULL)
		{
			ft_case(args, s[i + 1]);
			i++;
		}
		else
			ft_putchar_fd(s[i],1);
		i++;
	}
}

int main(void)
{
	ft_printf("hello world %d , %s, %c, %d, %d", 92, "hello", 'c', 380238202, 20923);
	return (0);
}