/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 01:35:18 by rtamouss          #+#    #+#             */
/*   Updated: 2023/12/02 01:49:44 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc(i + 2, 1);
	else if (buffer[i] == 0)
		line = ft_calloc(i + 1, 1);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line);
}

char	*ft_rest(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	temp = (char *)malloc(sizeof(char) * ((ft_strlen(str) - i) + 1));
	if (!temp)
		return (0);
	i++;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}

char	*join_and_free(char *result, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(result, buffer);
	free(result);
	return (temp);
}

char	*read_file(int fd, char *result)
{
	char	*buffer;
	int		bytesread;

	bytesread = 1;
	if (!result)
		result = ft_calloc(1, 1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buffer);
			free(result);
			return (NULL);
		}
		buffer[bytesread] = 0;
		result = join_and_free(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), result);
}

char	*get_next_line(int fd)
{
	static char	*stock[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX|| BUFFER_SIZE <= 0)
		return (NULL);
	stock[fd] = read_file(fd, stock[fd]);
	if (!stock[fd])
		return (NULL);
	line = ft_get_line(stock[fd]);
	stock[fd] = ft_rest(stock[fd]);
	return (line);
}
