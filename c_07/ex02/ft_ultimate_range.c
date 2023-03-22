/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:32:57 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/18 03:51:27 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	range_size;
	int	*aux;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	range_size = max - min;
	aux = (int *)malloc((range_size) * sizeof(int));
	if (aux == NULL)
	{
		*range = NULL;
		return (-1);
	}
	while (i < range_size)
	{
		aux[i] = i + min;
		i++;
	}
	*range = aux;
	return (range_size);
}
