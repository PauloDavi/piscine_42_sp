/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:10:27 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/08 03:20:48 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

bool	valid_num(int num)
{
	int		i;
	int		current_digit;
	int		previous_digit;
	bool	digits_seen[10];

	i = 0;
	while (i < 10)
	{
		digits_seen[i] = false;
		i++;
	}
	previous_digit = 10;
	while (num != 0)
	{
		current_digit = num % 10;
		if (digits_seen[current_digit] || current_digit > previous_digit)
			return (false);
		previous_digit = current_digit;
		digits_seen[current_digit] = true;
		num /= 10;
	}
	return (true);
}

void	print_num(int num, int n)
{
	int		i;
	char	digits[9];

	i = 0;
	while (i < n)
	{
		digits[i] = '0';
		i++;
	}
	i = 0;
	while (i < n)
	{
		digits[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &digits[i], 1);
		i--;
	}
}

int	calc_max_value(int n)
{
	int	i;
	int	max_value;

	i = n - 1;
	max_value = 0;
	while (i >= 0)
	{
		max_value *= 10;
		max_value += 9 - i;
		i--;
	}
	return (max_value);
}

void	ft_print_combn(int n)
{
	int	i;
	int	max_value;
	int	value;

	i = 0;
	value = 0;
	max_value = calc_max_value(n);
	while (i < n - 1)
	{
		value *= 10;
		value += ++i;
	}
	while (value <= max_value)
	{
		if (valid_num(value))
		{
			print_num(value, n);
			if (value != max_value)
				write(1, ", ", 2);
		}
		value++;
	}
}
