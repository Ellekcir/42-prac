#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (argc == 2 && argv[1][i] != '\0')
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			count = argv[1][i] - 'a';
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			count = argv[1][i] - 'A';
		write(1, &argv[1][i], 1);
		while (count > 0)
		{
				write(1, &argv[1][i], 1);
				count--;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
