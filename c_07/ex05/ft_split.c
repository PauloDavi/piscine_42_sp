/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:18:21 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/23 12:08:26 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_is_sep(char *charset, char c);
int		ft_count_split(char *str, char *charset);
void	ft_add_str(char **result, char *prev, int size, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*start;
	char	*end;
	int		i;

	i = 0;
	result = malloc((ft_count_split(str, charset) + 1) * sizeof(char *));
	start = str;
	end = str;
	while (1)
	{
		if (ft_is_sep(charset, *str))
			end = str;
		if ((end - start) > 1)
			ft_add_str(&result[i++], start, end - start, charset);
		if (*str == '\0')
			break ;
		start = end;
		str++;
	}
	result[i] = NULL;
	return (result);
}

void	ft_add_str(char **result, char *prev, int size, char *charset)
{
	if (ft_is_sep(charset, prev[0]))
	{
		prev++;
		size--;
	}
	*result = (char *)malloc((size + 2) * sizeof(char));
	ft_strncpy(*result, prev, size);
	(*result)[size] = '\0';
}

int	ft_is_sep(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
		if (c == charset[i++] || c == '\0')
			return (1);
	return (0);
}

int	ft_count_split(char *str, char *charset)
{
	char	*start;
	char	*end;
	int		counter;

	counter = 0;
	start = str;
	end = str;
	while (1)
	{
		if (ft_is_sep(charset, *str))
			end = str;
		if (end - start > 1)
			counter++;
		if (*str == '\0')
			break ;
		start = end;
		str++;
	}
	return (counter);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
