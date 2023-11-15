/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:50:51 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/15 01:07:57 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if ((size != 0) && (count > SIZE_MAX / size))
		return (NULL);
	s = (void *)malloc(count * size);
	if (s == NULL)
		return (NULL);
	ft_bzero (s, size * count);
	return (s);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	if(ft_calloc(23,2)) printf("done\n"); else printf("hhh\n");
// 	if(calloc(23, 2)) printf("done\n"); else printf("hhh\n");
// 	// printf("%lu", (SIZE_MAX )/SIZE_MAX + 12);
// 	return (0);
// }
