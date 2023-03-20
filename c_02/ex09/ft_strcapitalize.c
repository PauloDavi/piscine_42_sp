/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:32:47 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/09 22:00:59 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_strupcase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (true);
	}
	return (false);
}

bool	is_strlowercase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (true);
	}
	return (false);
}

bool	is_strnumber(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (true);
	}
	return (false);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			if (is_strlowercase(str[i]))
				str[i] -= 'a' - 'A';
		}
		else
		{
			if (!is_strupcase(str[i]) && !is_strlowercase(str[i])
				&& !is_strnumber(str[i]))
			{
				if (str[i + 1] != '\0')
				{
					if (is_strlowercase(str[i + 1]))
						str[i + 1] -= 'a' - 'A';
				}
			}
		}
		i++;
	}
	return (str);
}
