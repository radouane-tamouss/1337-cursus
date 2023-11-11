/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 00:17:05 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/12 00:17:14 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// static int is_sep(char c, char sep)
// {
// 	return (c == sep);
// }

// static int	count_words(char const *s, char sep)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		while (is_sep(s[i],sep) && s[i])
// 		i++;
// 		if (s[i] && !is_sep(s[i],sep))
// 		{
// 			count++;
// 			while (s[i] && !is_sep(s[i],sep))
// 				i++;
// 		}
// 	}
// 	return (count);
// }

// char **ft_split(char const *s, char c)
// {
// 	char	**res;
// 	int		i;
// 	int		start;
// 	int		end;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	if (!s)
// 		return (NULL);
// 	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
// 	if (!res)
// 		return (NULL);
// 	while (is_sep(s[i],c) && s[i])
// 			i++;
// 	while (s[i])
// 	{
// 		start = i;
// 		while (s[i] && !is_sep(s[i],c))
// 			i++;
// 		end = i;
// 		res[j] = (char *)malloc(end - start + 1);
// 		if (!res[j])
// 			return (NULL);
// 		ft_strlcpy(res[j], &s[start], end - start + 1);
// 		j++;
// 		while (s[i] && is_sep(s[i],c))
// 			i++;
// 	}
// 	res[j] = NULL;
// 	return (res);
// }

// char **ft_split(char const *s, char c)
// {
// 	char	**res;
// 	int i = 0;
// 	int j = 0;
// 	int start = 0;

// 	if (!s)
// 		return (NULL);
// 	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
// 	if (!res)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		start = i;
// 		while (s[i] && s[i] != c)
// 			i++;
// 		if (start < i)
// 		{
// 			res[j] = ft_substr(s, start, i - start);
// 			if (!res[j])
// 				return (NULL);
// 			j++;
// 		}
// 	}
// 	res[j] = NULL;
// 	return (res);
// }

// #include <stdio.h>
// int	 main(void)
// {
// 	char *s  = ",,,,,,,hello x,world,,,,,, this a te   ,    ,  st,,,";
// 	char **split = ft_split(s,',');
// 	int i = 0;
// 	while (split[i] != NULL)
// 	{
// 		printf("%d = |%s|\n" , i, split[i]);
// 		i++;
// 	}
// 	return 0;
// }