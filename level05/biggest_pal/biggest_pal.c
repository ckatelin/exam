/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:59:27 by ckatelin          #+#    #+#             */
/*   Updated: 2019/06/10 18:44:13 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1)
}

char	*pal(char *str)
{
	int left;
	int right;
	int cur;
	int i;
	char *mas;
	int len;

	len = ft_strlen(argv[1]);
	if (str[0] == '\0' || str[1] == '\0')
		return (str);
	else
	{
		i = 1;
		while (str[i])
		{
			left = i - 1;
			right = i + 1;
			while (left >= 0 && right <= len)
			{
				if (
				left--;
				right++;
			}
			i++;
		}
	}
	return (mas);
}

int		main(int argc, char **argv)
{
	char *mas;

	if (argc == 2)
		mas = pal(argv[1]);
	while (*mas)
		ft_putchar(*mas++);
	ft_putchar('\n');
}
