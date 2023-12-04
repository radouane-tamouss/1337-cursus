#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
    int fd = open("example.txt", O_RDONLY);
    char *str = get_next_line(fd);
        printf("%s", str);
        free(str);
    return (0);

}