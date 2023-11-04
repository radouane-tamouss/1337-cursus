/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:40:43 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/04 20:45:10 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (ptr);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	int v = 0;
// 	int b = 0;
// 	ft_memset(&v, 5, 4);
// 	printf("%d",v);
// 	memset(&b,5,4);
// 	printf("\n%d",b);
// 	return 0;
// }
