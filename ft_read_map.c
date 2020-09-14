/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 21:51:08 by droslyn           #+#    #+#             */
/*   Updated: 2020/09/02 21:51:26 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	ft_read_stdin(void)
{
	char	buf[BUFSIZE];
	int		n;
	int		fd;

	if ((fd = open(FILE_M, O_CREAT | O_RDWR | O_TRUNC, PMOD)) == -1)
	{
		ft_puterror();
		return ;
	}
	while ((n = read(0, buf, BUFSIZE)) > 0)
		if (write(fd, buf, n) != n)
			return (ft_puterror());
	close(fd);
	ft_size_map(FILE_M);
}

void	ft_create_data(t_data *map_data)
{
	char	*ptr_arr;
	int		i;

	i = 0;
	ptr_arr = map_data->array;
	while (ptr_arr[i] != '\n' && ptr_arr[i] != '\0')
		i++;
	if (ptr_arr[i] == '\0' || i < 4)
		return (ft_puterr_clean(map_data->array));
	if (ptr_arr[i] == '\n')
	{
		map_data->ptr_map = &ptr_arr[i + 1];
		map_data->full = ptr_arr[i - 1];
		map_data->obst = ptr_arr[i - 2];
		map_data->empty = ptr_arr[i - 3];
		if (ptr_arr[i + 1] == '\0')
			return (ft_puterr_clean(map_data->array));
	}
	ft_create_data_num(map_data, i - 4);
}

void	ft_create_data_num(t_data *map_data, int i)
{
	char	*numb;
	char	*ptr_arr;

	ptr_arr = map_data->array;
	if (!(numb = malloc(sizeof(char) * i + 1)))
		return (ft_puterr_clean(map_data->array));
	numb[i] = '\0';
	while (i >= 0)
	{
		numb[i] = ptr_arr[i];
		i--;
	}
	map_data->num_str = ft_atoi(numb);
	if (map_data->num_str <= 0)
	{
		ft_puterr_clean(map_data->array);
		free(numb);
		return ;
	}
	free(numb);
	ft_check_map(map_data);
}

void	ft_create_arr(int size, char *file)
{
	t_data		map_data;
	char		*ptr_arr;
	int			fd;
	int			n;
	char		c;

	if (!(ptr_arr = malloc(sizeof(char) * size + 1)))
		return (ft_puterror());
	if ((fd = open(file, 0)) == -1)
		return (ft_puterror());
	map_data.array = ptr_arr;
	while ((n = read(fd, &c, 1)) > 0)
	{
		*ptr_arr = c;
		ptr_arr++;
	}
	if ((n = read(fd, &c, 1)) == -1)
	{
		close(fd);
		ft_puterr_clean(ptr_arr);
		return ;
	}
	close(fd);
	*ptr_arr = '\0';
	ft_create_data(&map_data);
}

void	ft_size_map(char *file)
{
	int		fd;
	int		n;
	int		size;
	char	buf[BUFSIZE];

	size = 0;
	if ((fd = open(file, 0)) == -1)
	{
		ft_puterror();
		return ;
	}
	while ((n = read(fd, buf, BUFSIZE)) > 0)
		size = size + n;
	if (size == 0)
	{
		ft_puterror();
		return ;
	}
	if ((n = close(fd)) == -1)
	{
		ft_puterror();
		return ;
	}
	ft_create_arr(size, file);
}
