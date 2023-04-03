/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:14:42 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/23 03:08:23 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

int		ft_strlen(char *str);
bool	ft_verify_base(char *base);
int		ft_strchar(char *str, char to_find);
char	*ft_convnbr_base(int nbr, char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_nbrlen(int nbr, int base_len);
int		mod(int nbr);

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

bool	ft_verify_base(char *base)
{
	int	base_len;
	int	i;

	i = 0;
	base_len = ft_strlen(base);
	if (base_len <= 1)
		return (false);
	while (base[i] != '+' && base[i] != '-' && !(base[i] >= '\t'
			&& base[i] <= '\r') && base[i] != ' ' && base[i] != '\0')
		i++;
	if (i != base_len)
		return (false);
	i = 0;
	while (base[i + 2] != '\0')
	{
		if (ft_strchar(&base[i + 1], base[i]) != -1)
			return (false);
		i++;
	}
	return (true);
}

char	*ft_convnbr_base(int nbr, char *base)
{
	int		base_len;
	int		size;
	int		i;
	char	*str_nbr;

	base_len = ft_strlen(base);
	size = ft_nbrlen(nbr, base_len);
	str_nbr = malloc((size + 1) * sizeof(char));
	if (str_nbr == NULL)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		str_nbr[0] = '-';
		i = 1;
	}
	str_nbr[size] = '\0';
	while (--size >= 0 + i)
	{
		str_nbr[size] = base[mod(nbr % base_len)];
		nbr /= base_len;
	}
	return (str_nbr);
}

int	mod(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

int	ft_nbrlen(int nbr, int base_len)
{
	int	len;

	len = 1;
	if (nbr < 0)
		len++;
	while (nbr / base_len != 0)
	{
		len++;
		nbr /= base_len;
	}
	return (len);
}
