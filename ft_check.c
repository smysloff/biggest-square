/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:25:31 by droslyn           #+#    #+#             */
/*   Updated: 2020/09/02 20:40:24 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	ft_check_map(t_data *map_data)
{
	char	*ptr_mp;
	int		count;
	int		last_count;

	count = 0;
	last_count = 0;
	if (map_data->empty == map_data->obst ||
			map_data->empty == map_data->full ||
			map_data->obst == map_data->full)
		return (ft_puterr_clean(map_data->array));
	ptr_mp = map_data->ptr_map;
	while (*ptr_mp == map_data->empty || *ptr_mp == map_data->obst ||
			*ptr_mp == '\n')
	{
		if (*ptr_mp == map_data->empty || *ptr_mp == map_data->obst)
			count++;
		else if (*ptr_mp == '\n')
			last_count++;
		ptr_mp++;
	}
	if (*ptr_mp != '\0' || count == 0 || last_count != map_data->num_str)
		return (ft_puterr_clean(map_data->array));
	ft_check_line_map(map_data, 0, 0, ptr_mp);
}

void	ft_check_line_map(t_data *map_data, int count, int l_c, char *ptr_mp)
{
	if (map_data->num_str > 1)
	{
		ptr_mp = map_data->ptr_map;
		while (*ptr_mp != '\n' && *ptr_mp != '\0')
		{
			l_c++;
			ptr_mp++;
		}
		ptr_mp = map_data->ptr_map;
		while (*ptr_mp)
		{
			while (*ptr_mp != '\n' && *ptr_mp != '\0')
			{
				ptr_mp++;
				count++;
			}
			if (count != l_c)
				return (ft_puterr_clean(map_data->array));
			count = 0;
			if (*ptr_mp != '\0')
				ptr_mp++;
		}
	}
	ft_print_map(map_data);
}
