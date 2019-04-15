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
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != '\f' && str[i] != '\n')
	{
		i++;
		res++;
	}
	return (res + 1);
}

char	*ft_find(char *str)
{
	int i;
	char *mas;
	int k;

	k = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
		i++;
	mas = (char *)malloc(sizeof(char) * ft_len(str,i));
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
	word = ft_find(str);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
		i++;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != '\f' && str[i] != '\n')
		i++;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
			i++;
		ft_putchar(' ');
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != '\f' && str[i] != '\n')
			ft_putchar(str[i++]);
	}
	while (*word)
		ft_putchar(*(word++));
	free(word);
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
