/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:40:02 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/11 18:53:57 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	i = 0;
	while (i <= size)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int		main(void)
// {
// 	char *s = "hello";
// 	char *k = "hello";
// 	printf("located pointer : %p\nvalue : %s\n", ft_strchr(s,'\0')
//,ft_strchr(s,'\0'));
// 	printf("located pointer : %p\nvalue : %s\n", strchr(k,'\0'),strchr(k,'\0'));
// 	return (0);
// }