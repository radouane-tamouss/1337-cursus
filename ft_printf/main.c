/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:13:57 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/22 22:54:38 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

#include "ft_printf.h"

int main(void)
{
	int d = ft_printf(NULL);
	int d2 = printf(NULL);
	printf("%d %d", d, d2);
    return 0;
}