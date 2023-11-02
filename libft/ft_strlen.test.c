#include <stdio.h>
#include "libft.h"  // Assuming "libft.h" contains the function prototype for ft_strlen

int main() {
    char myString[] = "Hello, world!";
    size_t length;

    // Call the ft_strlen function to find the length of myString
    length = ft_strlen(myString);

    printf("The length of the string is: %zu\n", length);

    return 0;
}

