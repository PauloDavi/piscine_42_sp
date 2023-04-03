/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:51:31 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/20 21:09:02 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_is_space(char c);
bool	ft_is_number(char c);
int		ft_strlen(char *str);

int	ft_atoi(char *str)
{
	int	i;
	int	number;
	int	multiplyer;

	i = 0;
	number = 0;
	multiplyer = 1;
	while (str[i] != '\0' && ft_is_space(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (number);
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			multiplyer *= -1;
	while (ft_is_number(str[i]))
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * multiplyer);
}

bool	ft_is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (true);
	return (false);
}

bool	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
