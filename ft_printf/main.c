/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:20:57 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/23 19:43:42 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int d1 = ft_printf("%d %s %i %x %s %p %% %u %p\n", NULL, NULL, NULL, NULL, "he", NULL, -5, 14546543);
	int d2 = printf("%d %s %i %x %s %p %% %u %p\n", NULL, NULL, NULL, NULL, "he", NULL, -5,14546543);
	printf("%d --- %d", d1, d2);
	return (0);
}
