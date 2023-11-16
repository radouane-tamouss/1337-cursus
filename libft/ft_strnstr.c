/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:43:24 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/16 18:20:18 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0' && len == 0)
		return ((char *)haystack);
	else if (!len)
		return (NULL);
	else if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
	i++;
	}
	return (NULL);
}

// #include <string.h>
// int	main(void)
// {
// 	char *needle = "world";
// 	char *haystack = "hello this is world test hello";
// 	printf("%s",ft_strnstr(haystack,needle,ft_strlen(haystack)));
// 	printf("\n%s",strnstr(haystack,needle,ft_strlen(haystack)));
// 	return (0);
// }