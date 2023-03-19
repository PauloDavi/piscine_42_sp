/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulodavi <paulodavi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:52:13 by paulodavi         #+#    #+#             */
/*   Updated: 2023/03/19 19:18:36 by paulodavi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#define N 10

void	solve_puzzle(int board[N], int column, int *found_solutions);
bool	is_valid(int board[N], int row, int column);
void	print_solution(int board[N]);
int		ft_ten_queens_puzzle(void);

int	main(void)
{
	ft_ten_queens_puzzle();
}

int	ft_ten_queens_puzzle(void)
{
	int	board[N];
	int	found_solutions;

	found_solutions = 0;
	solve_puzzle(board, 0, &found_solutions);
	return (found_solutions);
}

void	solve_puzzle(int board[N], int column, int *found_solutions)
{
	int	row;

	if (column == N)
	{
		print_solution(board);
		(*found_solutions)++;
	}
	else
	{
		row = 0;
		while (row < N)
		{
			if (is_valid(board, row, column))
			{
				board[column] = row;
				solve_puzzle(board, column + 1, found_solutions);
			}
			row++;
		}
	}
}

bool	is_valid(int board[N], int row, int column)
{
	int	i;

	i = 0;
	while (i < column)
	{
		if (board[i] == row)
			return (false);
		if (board[i] - i == row - column)
			return (false);
		if (board[i] + i == row + column)
			return (false);
		i++;
	}
	return (true);
}

void	print_solution(int board[N])
{
	int	i;

	i = 0;
	while (i < N)
		write(1, &"0123456789"[board[i++]], 1);
	write(1, "\n", 1);
}
