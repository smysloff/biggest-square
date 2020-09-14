/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labsorbi <labsorbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 20:32:47 by labsorbi          #+#    #+#             */
/*   Updated: 2020/09/02 20:29:24 by labsorbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_atoi(char *str)
{
	int				minus;
	unsigned int	num;

	num = 0;
	minus = 1;
	while (*str)
	{
		while (*str == ' ')
			str++;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				minus = -minus;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			num = num * 10 + (*str - '0');
			str++;
		}
		break ;
	}
	return (num * minus);
}
