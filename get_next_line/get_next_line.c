/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtamouss <rtamouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:09:56 by rtamouss          #+#    #+#             */
/*   Updated: 2023/11/27 18:28:16 by rtamouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 256

int main(){
	char buffer[BUFFER_SIZE];
	int fd = open("example.txt", O_RDONLY);
	if (fd == -1) {
        printf("Failed to open file\n");
        return 1;
    }
	size_t bytesRead = read(fd, buffer, BUFFER_SIZE - 1);
	while(bytesRead > 0)
	{
		buffer[bytesRead] = '\0';
    	printf("%s", buffer);
		bytesRead = read(fd, buffer, BUFFER_SIZE - 1);
	}
    buffer[bytesRead] = '\0'; // Null terminate the string
	close(fd);
	return 0;
}