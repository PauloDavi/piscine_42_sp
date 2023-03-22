/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:14:44 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/18 15:19:40 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

int		ft_strlen(char *str);
bool	ft_verify_base(char *base);
int		ft_strchar(char *str, char to_find);
void	ft_putnbr_base(int nbr, char *base);
int		ft_atoi_base(char *str, char *base);

void	ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	ft_putnbr_base((ft_atoi_base(nbr, base_from)), base_to);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	number;
	int	multiplyer;
	int	len;

	i = 0;
	number = 0;
	multiplyer = 1;
	len = ft_strlen(base);
	if (!ft_verify_base(base))
		return (0);
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	if (i == len)
		return (number);
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			multiplyer *= -1;
	while (ft_strchar(base, str[i]) != -1)
	{
		number *= len;
		number += ft_strchar(base, str[i++]);
	}
	return (number * multiplyer);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchar(char *str, char to_find)
{
	int	i;

	i = 0;
	while (str[i] != to_find && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}
