/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulodavi <paulodavi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:22:45 by paulodavi         #+#    #+#             */
/*   Updated: 2023/03/16 00:33:17 by paulodavi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int number;

	number = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (--power)
		number *= nb;
	return (number);
}