/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:18:53 by droslyn           #+#    #+#             */
/*   Updated: 2020/09/02 20:23:03 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	ft_puterror(void)
{
	write(2, "map error\n", 10);
}

void	ft_puterr_clean(char *arr)
{
	write(2, "map error\n", 10);
	if (arr != 0)
		free(arr);
}
