/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:01:32 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/03 22:20:50 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char src[] = "hello world";
// 	char dst[] = "hello";

// 	printf("len = %zu , dst = %s, src = %s", ft_strlcpy(dst,src,0), dst, src);
// 	printf("\nlen = %zu , dst = %s, src = %s", strlcpy(dst,src,0), dst, src);
// 	return (0);
// }
