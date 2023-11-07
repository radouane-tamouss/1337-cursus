/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:58:04 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/07 18:43:40 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_is_sep(char c, char sep)
{
    return (c == sep);
}

static int ft_count_words(char const *str, char sep)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        while (str[i] && ft_is_sep(str[i], sep))
            i++;
        if (str[i] && !ft_is_sep(str[i], sep))
        {
            count++;
            while (str[i] && !ft_is_sep(str[i], sep))
                i++;
        }
    }
    return (count);
}

char **ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	res = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && ft_is_sep(s[i], c))
		i++;
	while (s[i])
	{
		start = i;
		while (s[i] && !ft_is_sep(s[i], c))
			i++;
		end = i;
		res[j] = (char *)malloc(end - start + 1);
		if (!res[j])
			return (NULL);
		ft_strlcpy(res[j], &s[start], end - start + 1);
		j++;
		while (s[i] && ft_is_sep(s[i], c))
			i++;
	}
	res[j] = NULL;
	return (res);
}


// #include <stdio.h>
// int	 main(void)
// {
// 	char *s  = "hello x,world,,,,,, this a te   ,    ,  st,,";
// 	char **split = ft_split(s,',');
// 	int i = 0;
// 	while (split[i] != NULL)
// 	{
// 		printf("%d = |%s|\n" , i, split[i]);
// 		i++;
// 	}
// 	return 0;
// }