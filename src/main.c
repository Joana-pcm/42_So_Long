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

int	main(int ac, char **av)
{
	char **map;

	map = NULL;
	map= map_check(av[1]);
	if (ac != 2)
		return (ft_printf("Error\n"));
	if (!map || !char_check(map))
		return (ft_printf("Error\n"));
	return (0);
}

int	char_check(char **map)
{
	int	i;
	int	j;
	int	count;
	int	coin;	

	i = -1;
	coin = 0;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\n')
		{
			count += (map[i][j] == 'E' || map[i][j] == 'P');
			if (map[i][j] != 'E' && map[i][j] != 'P' 
			&& map[i][j] != '1' && map[i][j] != '0'
			&& map[i][j] != 'C')
				return (0);
			coin += (map[i][j] == 'C');
		}
	}
			ft_printf("coin\t%d\n", coin);
	return ((count != 2 || coin != 0));
}

char	**map_check(char *map_file)
{
	int	size;
	int	i;
	int	fd;
	char **temp;

	size = ft_strlen(map_file);
	if ((!ft_strnstr(map_file, ".ber", size) 
		&& map_file[size + 1] != '\0') || size == 4 
		|| map_file[ft_strchrlen(map_file, '.') - 1] == '/')
		return (0);
	fd = open(map_file, O_RDONLY);
	size = 0;
	while (get_next_line(fd))
		size++;
	close(fd);
	fd = open(map_file, O_RDWR);
	i = -1;
	if (size >= 3)
	{
		temp = ft_calloc(sizeof(char *), size + 1);
		while (++i < size)
			temp[i] = get_next_line(fd);
		if (!valid_map(temp, size))
			return (0);
		else
			return (temp);
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
	if (x <= 3)
		return (1);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\n')
		{
			if (map[0][j] != '1' || map[i][0] != '1' 
				|| map[y - 1][j] != '1' || map[i][x - 1] != '1')
				return (ft_printf("Error\n"));
		}
		if (j < x && map[i][j + 1] == '\n')
			return (ft_printf("Error\n"));
	}
	return (0);
}

/*void	init_values()*/
