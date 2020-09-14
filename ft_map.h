/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labsorbi <labsorbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 11:46:55 by labsorbi          #+#    #+#             */
/*   Updated: 2020/09/02 20:41:24 by labsorbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H
# define BUFSIZE 80
# define FILE_M "./map6"
# define PMOD 0644
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_data
{
	char			*array;
	char			*ptr_map;
	char			empty;
	char			obst;
	char			full;
	int				num_str;
}					t_data;

typedef struct		s_pos
{
	int				y;
	int				x;
}					t_pos;

typedef struct		s_info
{
	int				c;
	int				r;
	int				l;
	int				r_p;
	int				r_s;
}					t_info;

void				ft_print_map(t_data *map);
int					ft_min_value(int n1, int n2, int n3);
int					ft_find_value(int *dst, int i, int cols);
int					ft_map_len(char *str);
void				ft_print_dig_map(int *map, int cols, int rows);
void				ft_putchar(char c);
int					ft_strlen(char *str);
void				ft_putstr(char *str);
int					ft_atoi(char *str);
void				ft_size_map(char *file);
void				ft_puterror(void);
void				ft_read_stdin(void);
void				ft_puterr_clean(char *arr);
void				ft_check_map(t_data *map_data);
void				ft_check_line_map(t_data *map_data, int count,
						int l_c, char *ptr_mp);
void				ft_create_data(t_data *map_data);
void				ft_create_data_num(t_data *map_data, int i);
void				ft_create_arr(int size, char *file);

#endif
