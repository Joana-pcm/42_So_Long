/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:01:41 by jpatrici          #+#    #+#             */
/*   Updated: 2025/02/12 16:44:03 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"
#include <fcntl.h>
#include <stdio.h>

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
			&& map[i][j] != 'C' && map[i][j] != '1' 
			&& map[i][j] != '0')
				return (0);
			coin += (map[i][j] == 'C');
		}
	}
	return ((count == 2 && coin != 0));
}

int	beerfinder(char *map_file, int size)
{
	while(size > 0 && map_file[size] != '.')
			size--;
	printf("%c\n", map_file[size - 1]);
	if(size > 0 && map_file[size] != '/')
		return 1;
	return -1;
}

int	parse_file(char *map_file)
{
	int	size;
	int	fd;
	char *temp;

	size = ft_strlen(map_file);

	if (beerfinder(map_file, size) && ((!ft_strnstr(map_file, ".ber", size) 
		&& map_file[size + 1] != '\0') || size == 4)) 
		return (0);
	size = 0;
	fd = open(map_file, O_RDONLY);
	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = NULL;
		temp = get_next_line(fd);
		size++;
	}
	close(fd);
	return ((size >= 3) * size);
}

char	**map_check(char *map_file)
{
	int	size;
	int	i;
	int	fd;
	char **temp;

	fd = open(map_file, O_RDONLY);
	i = -1;
	if (fd < 0)
		return (NULL);
	if (!parse_file(map_file))
		return (0);
	else 
		size = parse_file(map_file);
	temp = ft_calloc(sizeof(char *), size + 2);
	while (++i < size)
	{
		temp[i] = get_next_line(fd);
	}
	get_next_line(fd);
	close(fd);
	if (!valid_map(temp, size))
		return (arrfree(temp), NULL);
	else
		return (temp);
}

int	valid_map(char **map, int y)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	x = ft_strchrlen(map[0], '\n');
	if (x < 3)
		return (1);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\n')
		{
			if (map[0][j] != '1' || map[i][0] != '1' 
				|| map[y - 1][j] != '1' || map[i][x - 1] != '1')
				return (0);
		}
		if (j < x && map[i][j + 1] == '\n')
			return (0);
	}
	return (!fill(map, (y - 1), (x - 1)));
}
