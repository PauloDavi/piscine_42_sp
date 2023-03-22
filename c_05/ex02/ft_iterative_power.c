/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:22:45 by paulodavi         #+#    #+#             */
/*   Updated: 2023/03/20 15:28:00 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	number;

	number = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (--power)
		number *= nb;
	return (number);
}
