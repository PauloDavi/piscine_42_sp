/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:34:50 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/21 20:32:06 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str);
char				*ft_strdup(char *src);
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*array;

	array = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		i++;
	}
	array[i] = (t_stock_str){0, NULL, NULL};
	return (array);
}

char	*ft_strdup(char *src)
{
	int		size;
	char	*p_str;
	int		i;

	size = ft_strlen(src) + 1;
	p_str = malloc(size * 1);
	i = 0;
	while (i < size)
	{
		p_str[i] = src[i];
		i++;
	}
	return (p_str);
}
