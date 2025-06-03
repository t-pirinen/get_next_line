
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	char	*line;

	int test_txt = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(test_txt));
	while ((line = get_next_line(test_txt)))
	{
		// if (!line)
		// 	return (0);
		printf("%s", line);
	}
}
