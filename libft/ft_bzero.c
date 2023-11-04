/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:59:51 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/04 21:40:26 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	c;

	c = 0;
	ft_memset(s, c, n);
}

#include <stdio.h>
#include <string.h>
int main(void)
{
	char h[5] = "hello";

	ft_bzero(h,sizeof(h));
	size_t i = 0;
	while (i < sizeof(h))
	{
		printf("|%x|",h[i]);
		i++;
	}
}