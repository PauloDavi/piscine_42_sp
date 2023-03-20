/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:25:58 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/13 13:32:19 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len_str;
	int	len_to_find;

	len_str = ft_strlen(str);
	len_to_find = ft_strlen(to_find);
	i = 0;
	if (len_str >= len_to_find)
	{
		while (i <= len_str - len_to_find)
		{
			j = 0;
			while (j < len_to_find)
			{
				if (str[i + j] != to_find[j])
					break ;
				j++;
			}
			if (j == len_to_find)
				return (&str[i]);
			i++;
		}
	}
	return (NULL);
}
