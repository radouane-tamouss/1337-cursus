/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:40:02 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/11 22:20:02 by rtamouss         ###   ########.fr       */
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
// 	char *s = NULL;
// 	char *k = NULL;
// 	printf("located pointer : %p\nvalue : %s\n", ft_strchr(s,'s') 
//,ft_strchr(s,'s'));
// 	printf("located pointer : %p\nvalue : %s\n", strchr(k,'s'),strchr(k,'s'));
// 	return (0);
// }