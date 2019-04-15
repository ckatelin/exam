#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_check(int n)
{
	if (n > 9 && n < 16)
		return (1);
	return (0);
}

int		ft_countlen(int n, int base)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

long int		ft_pwd(int n, int base)
{
	long int pwd;

	pwd = 1;
	while (n != 0)
	{
		n /= base;
		pwd *= base;
	}
	return (pwd / base);
}

char	*ft_itoa_base(int value, int base)
{
	int n;
	long int pwd;
	char *mas;
	int i;

	pwd = ft_pwd(value, base);
	i = 0;
	if (value < 0  && base == 10)
	{
		mas = (char *)malloc(sizeof(char) * (ft_countlen(value, base) + 2));
		mas[i++] = '-';
	}
	else
		mas = (char *)malloc(sizeof(char) * (ft_countlen(value, base) + 1));
	while (pwd != 0)
	{
		n = (value / pwd) % base;
		if (n < 0)
			n = n * (-1);
		if (ft_check(n))
			mas[i++] = n + 55;
		else
			mas[i++] = n + '0'; 
		pwd /= base;
	}
	mas[i] = '\0';
	return (mas);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%s\n", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	}
	return (0);
}
