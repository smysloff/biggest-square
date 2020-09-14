/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labsorbi <labsorbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:49:14 by labsorbi          #+#    #+#             */
/*   Updated: 2020/09/02 20:29:19 by labsorbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

int		ft_min_value(int n1, int n2, int n3)
{
	if (n1 <= n2 && n1 <= n3)
		return (n1);
	else if (n2 <= n1 && n2 <= n3)
		return (n2);
	else
		return (n3);
}

int		ft_find_value(int *dst, int i, int cols)
{
	return (ft_min_value(dst[i - 1], dst[i - cols], dst[i - (cols + 1)]) + 1);
}

int		ft_map_len(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str != '\n')
			i++;
		str++;
	}
	return (i);
}

void	ft_print_dig_map(int *map, int cols, int rows)
{
	int y;
	int x;
	int i;

	i = 0;
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			ft_putchar(map[i++]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
