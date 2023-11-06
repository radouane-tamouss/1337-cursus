/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:42:55 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/06 20:22:42 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	size_t	dlen;

	i = 0;
	j = 0;
	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (dstsize <= dlen)
		return (slen + dstsize);
	while (src[i] && i < (dstsize - dlen - 1))
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char src[] = "world";
// 	char dst[50] = "hello, ";
// 	printf ("return = %zu , src = %s, dst = %s\n", 
// 					ft_strlcat(dst,src,17),src,dst);
// 	char src1[] = "world";
// 	char dst1[50] = "hello, ";
// 	printf ("\nreturn = %zu , src = %s, dst = %s", 
// 					strlcat(dst1,src1,17),src,dst);
// 	return (0);
// }