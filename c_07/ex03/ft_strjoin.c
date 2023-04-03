/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:56:41 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/23 13:07:50 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_total_len(int size, char **strs, int sep_len);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	char	*dest;
	int		total_len;
	int		i;

	if (size == 0)
		return (malloc(sizeof(char)));
	total_len = ft_total_len(size, strs, ft_strlen(sep));
	str = malloc(total_len * sizeof(char));
	if (str == NULL)
		return (NULL);
	dest = str;
	i = -1;
	while (++i < size)
	{
		ft_strcpy(str, strs[i]);
		str += ft_strlen(strs[i]);
		if (i != (size - 1))
		{
			ft_strcpy(str, sep);
			str += ft_strlen(sep);
		}
	}
	*str = '\0';
	return (dest);
}

int	ft_total_len(int size, char **strs, int sep_len)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		if (i++ != (size - 1))
			total += sep_len;
	}
	return (total + 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
