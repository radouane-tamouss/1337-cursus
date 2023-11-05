/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:50:51 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/05 14:53:37 by rtamouss         ###   ########.fr       */
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

// int	main(void)
// {
// 	int	*h;
// 	h = ft_calloc(5, sizeof(int));
// 	int i = 0;
// 	while ( i < 5 )
// 	{
// 		printf("h[%d] = %d \n", i, h[i]);
// 		i++;
// 	}
// 	return 0;
// }
