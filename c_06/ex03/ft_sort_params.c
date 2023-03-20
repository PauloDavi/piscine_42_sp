/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:15:37 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/17 18:01:15 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_swap(char **a, char **b);
void	ft_sort_char_tab(char **tab, int size);

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
		return (0);
	ft_sort_char_tab(argv, argc);
	while (i < argc)
	{
		ft_putstr(argv[i++]);
		write(1, "\n", 1);
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char **a, char **b)
{
	char	*aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_sort_char_tab(char **tab, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
