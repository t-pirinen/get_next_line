
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line); // <-- THIS LINE IS REQUIRED
    }
    close(fd);
    return 0;
}

