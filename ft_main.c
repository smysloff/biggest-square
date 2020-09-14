/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 21:52:04 by droslyn           #+#    #+#             */
/*   Updated: 2020/09/02 21:52:11 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
	{
		ft_read_stdin();
		return (0);
	}
	while (i < argc)
	{
		if (i > 1 && i < argc)
			write(1, "\n", 1);
		ft_size_map(argv[i]);
		i++;
	}
	return (0);
}
