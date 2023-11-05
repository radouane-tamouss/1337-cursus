/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:40:02 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/05 15:14:36 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
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