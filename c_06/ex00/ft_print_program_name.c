/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:16:46 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/17 14:21:30 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	if (argc < 1)
		return (0);
	ft_putstr(argv[0]);
	write(1, "\n", 1);
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}
