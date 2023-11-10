/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:17:55 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/10 16:47:38 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	count_digits(int n)
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

char	*ft_itoa(int n)
{
	int		len;
	char	*s;

	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_digits(n);
	s = (char *)malloc(len + 1);
	if (!s)
		return (0);
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	s[len--] = '\0';
	while (n != 0)
	{
		s[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (s);
}
// int main(void)
// {
// 	int n = -202;
// 	char *s = ft_itoa(n);
// 	printf("%s\n",s);
// 	printf("%d\n",count_digits(n));

// 	return (0);
// }
