#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char **str, int k)
{
	int j;

	while (k >= 0)
	{
		j = 0;
		while (str[k][j])
			ft_putchar(str[k][j++]);
		if (k > 0)
			ft_putchar(' ');
		k--;
	}
}

int		ft_countwords(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\v' && str[i] != '\f' && str[i])
			i++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'))
			i++;
		count++;
	}
	return (count);
}

int		ft_len(char *str, int i)
{
	int j;

	j = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\v' && str[i] != '\f')
	{
		i++;
		j++;
	}
	return (j + 1);
}

void	rev_wstr(char *str)
{
	int i;
	char **mas;
	int	words;
	int j;
	int k;

	words = ft_countwords(str);
	i = 0;
	k = 0;
	mas = (char **)malloc(sizeof(char *) * (words + 1));
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i])
	{
		j = 0;
		mas[k] = (char *)malloc(sizeof(char) * ft_len(str, i));
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\v' && str[i] != '\f')
			mas[k][j++] = str[i++];
		mas[k++][j] = '\0';
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
			i++;
	}
	mas[k] = 0;
	ft_print(mas, words - 1);
	free(*mas);
	free(mas);

}

int main (int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	ft_putchar('\n');
	return (0);
}
