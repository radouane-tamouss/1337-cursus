/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:42:55 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/04 00:21:25 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;

	if(dstlen >= dstsize)
		return (srclen + dstsize);
	while (src[i] && i < dstsize - dstlen - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (srclen + dstlen);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char src[] = "world";
	char dst[20] = "hello, ";
	

	printf ("return = %zu , src = %s, dst = %s\n", ft_strlcat(dst,src,17),src,dst);
	

	char src1[] = "world";
	char dst1[20] = "hello, ";
	printf ("\nreturn = %zu , src = %s, dst = %s", strlcat(dst1,src1,17),src,dst);
	return (0);
}