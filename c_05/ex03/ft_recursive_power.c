/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:22:45 by paulodavi         #+#    #+#             */
/*   Updated: 2023/03/20 15:28:39 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	number;

	number = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 1)
		return (nb * ft_recursive_power(nb, power - 1));
	return (nb);
}
