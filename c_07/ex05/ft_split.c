/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:11:36 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/22 00:53:09 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_is_sep(char *charset, char c);
int		ft_count_words(char *str, char *charset);
void	ft_add_str(char **result, char *prev, int size, int is_frist);

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*end;
	char	*start;
	int		i;

	result = malloc((ft_count_words(str, charset) + 1) * sizeof(char *));
	i = 0;
	start = str;
	end = str;
	while (1)
	{
		if (ft_is_sep(charset, *str))
			end = str;
		if (end - start > 1)
			ft_add_str(&result[i++], start, end - start, !(str - start));
		if (*str++ == '\0')
			break ;
		start = end;
	}
	result[i] = NULL;
	return (result);
}

void	ft_add_str(char **result, char *prev, int size, int is_frist)
{
	if (!is_frist)
	{
		prev++;
		size--;
	}
	*result = (char *)malloc((size + 1) * sizeof(char));
	ft_strncpy(*result, prev, size);
	(*result)[size] = '\0';
}

int	ft_is_sep(char *charset, char c)
{
	while (*charset != '\0')
		if (c == *charset++ || c == '\0')
			return (1);
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (ft_is_sep(charset, str[i]) && !ft_is_sep(charset, str[i + 1])
			&& str[i + 1] != '\0')
			counter++;
		else if (i == 0 && !ft_is_sep(charset, str[i]))
			counter++;
		i++;
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
