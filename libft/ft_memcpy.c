/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:20:39 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/05 14:28:58 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t			i;
	unsigned char	*dstptr;
	unsigned char	*srcptr;

	i = 0;
	dstptr = (unsigned char *)dst;
	srcptr = (unsigned char *)src;
	while (i < n)
	{
		dstptr[i] = srcptr[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int add(int a , int b)
// {
// 	return a + b;
// }
// int	main(void)
// {
// 	char src[] = "hello, memcpy!";
// 	char dst[] = "hello, memcpy!";
// 	char src1[] = "hello, memcpy!";
// 	char dst1[] = "hello, memcpy!";
// 	ft_memcpy(dst,src,sizeof(src));
// 	memcpy(dst1,src1,sizeof(src));

// 	 printf("Source:      %s\n", src);
//     printf("Destination: %s\n", dst);
// 	    printf("return value: %s\n", ft_memcpy(dst,src,sizeof(src)));

// 	 printf("Source:      %s\n", src1);
//     printf("Destination: %s\n", dst1);
// 	return 0; 
// }