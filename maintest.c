
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	int		fd;
	char	buf[256];
	int		chars_read;

	fd = open("test.txt", O_RDONLY);
	while ((chars_read = read(fd, buf, 6)))
	{
		buf[chars_read] = '\0';
		printf("\n%s", buf);
	}
	printf("\n");
}