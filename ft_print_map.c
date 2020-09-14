/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labsorbi <labsorbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:40:30 by labsorbi          #+#    #+#             */
/*   Updated: 2020/09/02 20:29:11 by labsorbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	ft_render_cycle(t_data *map, int *dig_map, t_pos *p, t_info *i)
{
	int j;

	j = 0;
	p->y = 0;
	while (p->y < i->r)
	{
		p->x = 0;
		while (p->x < i->c)
		{
			if (dig_map[j] == 0)
				ft_putchar(map->obst);
			else
			{
				if (p->y > i->r_p / i->c - i->r_s && p->y <= i->r_p / i->c &&
					p->x > i->r_p % i->c - i->r_s && p->x <= i->r_p % i->c)
					ft_putchar(map->full);
				else
					ft_putchar(map->empty);
			}
			j++;
			p->x++;
		}
		ft_putchar('\n');
		p->y++;
	}
}

void	ft_create_chr_map(t_data *map, char **chr_map)
{
	int		i;
	char	*src;

	src = map->ptr_map;
	i = 0;
	while (*src)
	{
		if (*src != '\n')
			(*chr_map)[i++] = *src;
		src++;
	}
	(*chr_map)[i] = '\0';
}

int		ft_create_dig_map(t_data *map, char *chr_map, int **dig_map, int cols)
{
	int		i;
	int		max;
	int		rect;
	char	*src;

	src = chr_map;
	max = 0;
	i = 0;
	while (i < (map->num_str * cols))
	{
		if (src[i] == map->obst)
			(*dig_map)[i] = 0;
		else if (i < cols || i % cols == 0)
			(*dig_map)[i] = (src[i] == map->obst) ? 0 : 1;
		else
			(*dig_map)[i] = ft_find_value(*dig_map, i, cols);
		if ((*dig_map)[i] > max)
		{
			max = (*dig_map)[i];
			rect = i;
		}
		i++;
	}
	return (rect);
}

void	ft_render_map(t_data *map, int *dig_map, int cols, int rect_pos)
{
	t_pos		*pos;
	t_info		*info;

	pos = (t_pos *)malloc(sizeof(t_pos));
	if (!pos)
		return ;
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return ;
	info->r_s = dig_map[rect_pos];
	info->r_p = rect_pos;
	info->c = cols;
	info->r = map->num_str;
	info->l = map->num_str * cols;
	ft_render_cycle(map, dig_map, pos, info);
	free(pos);
	free(info);
}

void	ft_print_map(t_data *map)
{
	char	*chr_map;
	int		*dig_map;
	int		cols;
	int		len;
	int		rect_pos;

	len = ft_map_len(map->ptr_map);
	cols = len / map->num_str;
	chr_map = (char *)malloc(sizeof(char) * (len + 1));
	if (!chr_map)
		return ;
	dig_map = (int *)malloc(sizeof(int) * len);
	if (!dig_map)
		return ;
	ft_create_chr_map(map, &chr_map);
	rect_pos = ft_create_dig_map(map, chr_map, &dig_map, cols);
	ft_render_map(map, dig_map, cols, rect_pos);
	free(map->array);
	free(chr_map);
	free(dig_map);
}
