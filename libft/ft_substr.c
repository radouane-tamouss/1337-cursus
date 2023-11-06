/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:19:16 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/06 21:53:55 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	size_t			s_len;

	i = 0;
	str = (char *)malloc(len + 1);
	if (s == NULL || !str)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		str[0] = '\0';
		return (str);
	}
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = "hello world test please";
// 	char *sub;
// 	sub = ft_substr(s,6,7);
// 	printf("%s",sub);
// 	return (0);
// }