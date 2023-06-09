/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:21:16 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/22 12:31:24 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	range;

	if (min >= max)
		return (NULL);
	range = max - min;
	tab = malloc((range) * sizeof(int));
	if (tab == NULL)
		return (tab);
	i = 0;
	while (i < range)
	{
		tab[i] = i + min;
		i++;
	}
	return (tab);
}
