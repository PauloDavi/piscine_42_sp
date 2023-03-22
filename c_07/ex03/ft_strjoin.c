/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:56:41 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/18 04:12:19 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len_alloc;
	char	*join;

	if (size == 0)
		return ((char *)malloc(1 * sizeof(char)));
	i = 0;
	len_alloc = ft_strlen(sep) * (size - 1);
	while (i < size)
	{
		len_alloc += ft_strlen(strs[i]);
		i++;
	}
	join = (char *)malloc(len_alloc * sizeof(char));
	if (join == NULL)
		return (join);
	i = 0;
	while (i < size)
	{
		ft_strcat(join, strs[i]);
		if (i != size - 1)
			ft_strcat(join, sep);
		i++;
	}
	return (join);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
