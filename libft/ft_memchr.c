/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:06:36 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/05 18:21:15 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((void *)(ptr + i));
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// void	*ft_memchr(const void *s, int c, size_t n);

// int main() {
//     const char *str1 = "This is a test string";
//     int target1 = 'a';
//     size_t length1 = strlen(str1);
// 	void *myresult = ft_memchr(str1,target1,length1);
// 	void *oresult = memchr(str1,target1,length1);
// 	if (myresult != NULL)
// 		printf("my result \nFound %c at : %p\n", target1, myresult);
// 	else
// 		printf("%c not found in the string.\n",target1);
// 	if (oresult != NULL)
// 		printf("their result\nFound %c at : %p\n", target1, oresult);
// 	else
// 		printf("%c not found in the string.\n",target1);
// 	return 0;
// }
