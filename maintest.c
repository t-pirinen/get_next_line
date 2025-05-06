
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	char	*print;

	while ((print = get_next_line(fd)))
		printf("\n%s", print);
	printf("\n");
}