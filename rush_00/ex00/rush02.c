/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulodavi <paulodavi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:58:07 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/05 11:30:35 by paulodavi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	ft_putchar(char c);

void	print_error_mesage(void)
{
	int		i;
	char	*message;

	i = 0;
	message = "X and Y must be greater than or equal to zero.";
	while (message[i])
	{
		ft_putchar(message[i]);
		i++;
	}
	ft_putchar('\n');
}

char	select_char(int x, int y, int x_max, int y_max)
{
	bool	x_is_zero;
	bool	y_is_zero;
	bool	x_is_max;
	bool	y_is_max;

	x_is_zero = x == 0;
	y_is_zero = y == 0;
	x_is_max = x == x_max;
	y_is_max = y == y_max;
	if ((x + y == 0) || (y_is_zero && x_is_max))
	{
		return ('A');
	}
	if ((x_is_zero && y_is_max) || (x + y == x_max + y_max))
	{
		return ('C');
	}
	if (x_is_zero || y_is_zero || x_is_max || y_is_max)
	{
		return ('B');
	}
	return (' ');
}

void	rush(int x, int y)
{
	int	colunm;
	int	line;

	line = 0;
	if (x <= 0 || y <= 0)
	{
		print_error_mesage();
		return ;
	}
	while (line < y)
	{
		colunm = 0;
		while (colunm < x)
		{
			ft_putchar(select_char(colunm, line, x - 1, y - 1));
			colunm++;
		}
		ft_putchar('\n');
		line++;
	}
}
