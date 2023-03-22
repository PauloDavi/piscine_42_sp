/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:14:42 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/18 15:20:16 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

int		ft_strlen(char *str);
char	*ft_strstr(char *str, char *to_find);
void	ft_putnbr(int nb, char *base, int base_len);
bool	ft_verify_base(char *base);
int		ft_strchar(char *str, char to_find);
void	ft_putnbr_base(int nbr, char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (ft_verify_base(base))
		ft_putnbr(nbr, base, base_len);
}

bool	ft_verify_base(char *base)
{
	int	base_len;
	int	i;

	i = 0;
	base_len = ft_strlen(base);
	if (base_len <= 1)
		return (false);
	while (base[i] != '+' && base[i] != '-' && base[i] != ' '
		&& base[i] != '\0')
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

void	ft_putnbr(int nb, char *base, int base_len)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr / base_len > 0)
	{
		ft_putnbr(nbr / base_len, base, base_len);
	}
	write(1, &base[nbr % base_len], 1);
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
