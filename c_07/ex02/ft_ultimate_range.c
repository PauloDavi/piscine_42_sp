/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:32:57 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/22 12:34:44 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	range_size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	range_size = max - min;
	*range = malloc((range_size) * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < range_size)
	{
		(*range)[i] = i + min;
		i++;
	}
	return (range_size);
}
