/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:09:58 by rtamouss          #+#    #+#             */
/*   Updated: 2023/12/04 08:26:39 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE INT_MAX
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

size_t	ft_strlen(const char *theString);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_get_line(char *buffer);
char	*ft_rest(char *buffer);
char	*read_file(int fd, char *result);
char	*get_next_line(int fd);

#endif // GET_NEXT_LINE_H
