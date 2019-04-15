#include <stdlib.h>

int		ft_countwords(char *str)
{
	int count;

	count = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	while (*str)
	{
		while (*str && *str != ' ' && *str != '\t' && *str != '\n' && *str != '\v'
				&& *str != '\f')
			str++;
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f')
			str++;
		count++;
	}
	return (count);
}

int		ft_countsym(char *str, int i)
{
	int count;

	count = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&
			str[i] != '\v' && str[i] != '\f')
	{
		count++;
		i++;
	}
	return (count + 1);
}

char    **ft_split(char *str)
{
	int i;
	char **mas;
	int all;
	int k;
	int j;

 	i = 0;
	k = 0;
	all = ft_countwords(str);
	if (!(mas = (char **)malloc(sizeof(char *) * (all + 1))))
		return (NULL);
	while (k < all)
	{
		j = 0;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
				str[i] == '\v' || str[i] == '\f')
			i++;
		if (!(mas[k] = (char *)malloc(sizeof(char) * ft_countsym(str, i))))
			return (NULL);
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
				&& str[i] != '\v' && str[i] != '\f')
			mas[k][j++] = str[i++];
		mas[k++][j] = '\0';
	}
	mas[k] = 0;
	return (mas);
}
