/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:11:12 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/08 00:51:33 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(int a)
{
	ft_putchar('0' + (a / 10));
	ft_putchar('0' + (a % 10));
}

void	print_comb(int a, int b)
{
	if (a != b)
	{
		print_number(a);
		ft_putchar(' ');
		print_number(b);
		if (!(a == 98 && b == 99))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_comb(a, b);
			b++;
		}
		a++;
	}
}
