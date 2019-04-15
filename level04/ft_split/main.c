#include <stdio.h>

char    **ft_split(char *str);

int main(int argc, char **argv)
{
	int i;
	char **mas;

	i = 0;
	if (argc == 2)
	{
		mas = ft_split(argv[1]);
		while (mas[i])
			printf("%s\n", mas[i++]);
	}
	return (0);
}
