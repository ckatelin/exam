#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_len(char *str, int i)
{
	int res;

	res = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != '\f' && str[i] != '\n' && str[i])
	{
		i++;
		res++;
	}
	return (res + 1);
}

char	*ft_find(char *str, int i)
{
	int j;
	char *mas;
	int k;

	k = 0;
	j = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != '\f' && str[i] != '\n' && str[i])
	{
		i++;
		j++;
	}
	mas = (char *)malloc(sizeof(char) * ft_len(str, i - j));
	i = i - j;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != '\f' && str[i] != '\n' && str[i])
		mas[k++] = str[i++];
	mas[k] = '\0';
	return (mas);
}

void	rostring(char *str)
{
	char *word;
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
		i++;
	word = ft_find(str, i);
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != '\f' && str[i] != '\n' && str[i])
		i++;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != '\f' && str[i] != '\n' && str[i])
			ft_putchar(str[i++]);
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
			i++;
		ft_putchar(' ');
	}
	while (*word)
		ft_putchar(*(word++));
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		rostring(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
