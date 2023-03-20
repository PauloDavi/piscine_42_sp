/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:09:33 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/11 03:31:50 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

bool	char_is_printable(char c)
{
	if (c >= 32 && c <= 126)
	{
		return (true);
	}
	return (false);
}

void	print_char_hex(char c)
{
	char	tens;
	char	ones;

	tens = "0123456789abcdef"[c / 16];
	ones = "0123456789abcdef"[c % 16];
	write(1, "\\", 1);
	write(1, &tens, 1);
	write(1, &ones, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (char_is_printable(str[i]))
		{
			write(1, &str[i], 1);
		}
		else
		{
			print_char_hex(str[i]);
		}
		i++;
	}
}
