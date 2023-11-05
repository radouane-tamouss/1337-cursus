/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:50:51 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/05 02:52:42 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = (void *)malloc(count * size);
	if (s == NULL)
		return (NULL);
	ft_bzero (s, size * count);
	return (s);
}

// #include <stdio.h>
// #include <stdlib.h>
// // Your ft_calloc function here
// int main() {
// 	size_t	count = 5;
// 	size_t	size = sizeof(int);
// 	int*	array = (int*)ft_calloc(count, size);
// 	if (array == NULL)
// 	{
// 		return 1;
// 	}
// 	for (size_t i = 0; i < count; i++)
// 	{
// 		printf("array[%zu] = %d\n", i, array[i]);
// 	}
// 	free(array);
// 	return 0;
// }
