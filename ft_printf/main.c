/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:13:57 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/22 23:10:34 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <assert.h>
#include <limits.h>

int main(void)
{
    char c = 'a'; // Test character
    char *s = "Hello, World!"; // Test string
    void *p = &c; // Test pointer
    int d = INT_MIN; // Test signed decimal integer
    unsigned int u = UINT_MAX; // Test unsigned decimal integer
    unsigned int x = 0xABCDEF; // Test unsigned hexadecimal integer (lowercase)
    unsigned int X = 0xABCDEF; // Test unsigned hexadecimal integer (uppercase)

    // Test with a character
    int d1 = printf("%c\n", c);
    int d2 = ft_printf("%c\n", c);
    assert(d1 == d2);

    // Test with a string
    d1 = printf("%s\n", s);
    d2 = ft_printf("%s\n", s);
    assert(d1 == d2);

    // Test with a pointer
    d1 = printf("%p\n", p);
    d2 = ft_printf("%p\n", p);
    assert(d1 == d2);

    // Test with a signed decimal integer
    d1 = printf("%d\n", d);
    d2 = ft_printf("%d\n", d);
    assert(d1 == d2);

    // Test with an unsigned decimal integer
    d1 = printf("%u\n", u);
    d2 = ft_printf("%u\n", u);
    assert(d1 == d2);

    // Test with an unsigned hexadecimal integer (lowercase)
    d1 = printf("%x\n", x);
    d2 = ft_printf("%x\n", x);
    assert(d1 == d2);

    // Test with an unsigned hexadecimal integer (uppercase)
    d1 = printf("%X\n", X);
    d2 = ft_printf("%X\n", X);
    assert(d1 == d2);

    // Test with a percent sign
    d1 = printf("%%\n");
    d2 = ft_printf("%%\n");
    assert(d1 == d2);

    printf("All tests passed!\n");
    return 0;
}
