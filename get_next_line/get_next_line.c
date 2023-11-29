/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:09:56 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/29 23:14:16 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 23

size_t	ft_strlen(const char *theString)
{
	int	i;

	i = 0;
	while (theString[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

void *ft_calloc(size_t num, size_t size)
{
    char *ptr;
    size_t i;

    ptr = malloc(num * size);
    if (!ptr)
        return NULL;

    for (i = 0; i < num * size; i++)
        ptr[i] = 0;

    return ptr;
}

char	*ft_strchr(const char *string, int searchedChar )
{
	char	*str;

	str = (char *)string;
	while (*str != searchedChar && *str != 0)
		str++;
	if (*str == searchedChar)
		return (str);
	else
		return (NULL);
}
char *ft_line(char *buffer)
{
	char *line;
	int i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while(buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if(buffer[i] && buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line);
}
char *ft_next(char *buffer)
{
	int i;
	int j;
	char *line;

	i = 0;
	while(buffer[i] && buffer[i] != '\n')
		i++;
	if(!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// len of file - len of firstline + 1
	line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	//line == buffer
	while(buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return(line);
}
char *read_file(int fd, char *result)
{
	char *buffer;
	int	bytesRead;

	if(!result)
		result = ft_calloc(1,1);
	bytesRead = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while(!ft_strchr(buffer, '\n') && bytesRead > 0)
	{
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		if(bytesRead == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytesRead] = 0;
		result = ft_strjoin(result, buffer);
	}
	free(buffer);
	return (result);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;
	
	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	
	buffer = read_file(fd, buffer);
	if(!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (buffer);
}

int main()
{
	int fd = open("example.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	
	
	
	return (0);
}

