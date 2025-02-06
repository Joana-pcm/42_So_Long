/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:11:14 by jpatrici          #+#    #+#             */
/*   Updated: 2025/02/05 17:13:09 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (!map_check(av[1]))
	{
		ft_printf("Error\n");
		return (1);
	}

	return (0);
}

int	map_check(char *s_map)
{
	int	size;
	int	i;
	int	fd;
	char **map;
	/*char *temp;*/

	size = ft_strlen(s_map);
	if ((!ft_strnstr(s_map, ".ber", size) 
		&& s_map[size + 1] != '\0') || size == 4 
		|| s_map[ft_strchrlen(s_map, '.') - 1] == '/')
		return (0);
	fd = open(s_map, O_RDONLY);
	size = 0;
	printf("%i\n", fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%p\n", get_next_line(fd));
	printf("%p\n", get_next_line(fd));
	printf("%p\n", get_next_line(fd));
	/*while ((temp = get_next_line(fd)) != NULL)*/
	/*{*/
	/*	size++;*/
	/*}*/
	printf("here\n");
	close(fd);
	fd = open(s_map, O_RDWR);
	i = -1;
	if (size > 3)
	{
		map = ft_calloc(sizeof(char *), size + 1);
		while (++i < size)
			map[i] = get_next_line(fd);
		printf("%c\n", map[0][ft_strlen(map[0])]);
		return (!valid_map(map, size));
	}
	return (0);
}

int	valid_map(char **map, int y)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	x = ft_strchrlen(map[0], '\n');
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[0][j] != '1' || map[i][0] != '1' 
				|| map[y][j] != '1' || map[i][x] != '1')
				return (ft_printf("Error\n"));
		}
		if (j < x && map[i][j + 1] == '\n')
			return (ft_printf("Error\n"));
	}
	return (0);
}
