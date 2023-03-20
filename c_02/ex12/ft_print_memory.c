/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:33:33 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/11 13:34:56 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	str_print_n(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_ptr_hex(char *ptr)
{
	char	ptr_hex[20];
	int		i;

	i = 15;
	while (i >= 0)
	{
		ptr_hex[i] = "0123456789abcdef"[(unsigned long)ptr % 16];
		ptr = (char *)((unsigned long)ptr / 16);
		i--;
	}
	write(1, ptr_hex, 16);
	write(1, ": ", 2);
}

void	print_char_hex(char ptr)
{
	char	tens;
	char	ones;

	tens = "0123456789abcdef"[ptr / 16];
	ones = "0123456789abcdef"[ptr % 16];
	write(1, &tens, 1);
	write(1, &ones, 1);
}

void	print_last_spaces(int size)
{
	int	i;

	i = 0;
	while (i++ < (16 - (size % 16)) / 2)
		write(1, "     ", 5);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = -1;
	while (++i < size)
	{
		if (i % 16 == 0)
		{
			if (i != 0)
				write(1, "\n", 1);
			print_ptr_hex(&((char *)addr)[i]);
		}
		print_char_hex(((char *)addr)[i]);
		if (i % 2 == 1)
			write(1, " ", 1);
		if ((i + 1) % 16 == 0)
			str_print_n(&((char *)addr)[i - 15], 16);
	}
	if (size % 16 != 0)
	{
		print_last_spaces(size);
		str_print_n(&((char *)addr)[size - (size % 16)], (size % 16));
		write(1, "\n", 1);
	}
	return (addr);
}

// int	main(void)
// {
// 	char	str[] = "Bonjour les aminches\n\n\nc\n est
// fou\ntout\nce qu on peut faire avec\n\n\nprint_memory\t\ta\tlol\tlol\t \t34";
// 	ft_print_memory(str, 94);
// 	return (0);
// }
