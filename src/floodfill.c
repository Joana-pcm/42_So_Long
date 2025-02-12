/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:54:17 by jpatrici          #+#    #+#             */
/*   Updated: 2025/02/10 17:15:08 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	fill(char **map, int length, int width)
{	
	t_point	p;
	t_point	size;
	char	**temp;

	size.y = length;
	size.x = width;
	temp = mapcpy(map, size);
	p = init_point(map, 'P');
	floodfill(temp, size, p.y, p.x);
	int i = -1;
	while (temp[++i])
		ft_printf("%s", temp[i]);
	if (coincount(temp))
		return (1);
	return (0);
}

char **mapcpy(char **map, t_point size)
{
	int		i;
	char	**temp;

	i = -1;
	temp = ft_calloc(sizeof(char *), size.y + 2);
	while (map[++i])
		temp[i] = ft_strdup_gnl(map[i]); 
	return (temp);
}

void	floodfill(char **map, t_point size, int col, int row)
{
	if (col < 0 || row < 0 || col > size.y || row > size.x)
		return ;
	if (map[col][row] == '2' || map[col][row] == '1' || map[col][row] == 'e')
		return ;
	map[col][row] = '2' + ((map[col][row] == 'E') * 51);
	if (map[col][row] == 'e')
		return ;
	floodfill(map, size, col + 1, row);
	floodfill(map, size, col - 1, row);
	floodfill(map, size, col, row + 1);
	floodfill(map, size, col, row - 1);
}

int	coincount(char **map)
{
	int	coins;
	int exit;
	int i;
	int j;

	coins = 0;
	exit = 0;
	i = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				coins++;
			if (map[i][j] == 'e')
				exit++;
		}
	}
	return (coins || (exit != 1));
}

t_point	init_point(char	**map, char c)
{
	t_point	point;
	int		y;
	int		x;

	y = -1;
	point.y = y;
	while (map[++y])
	{
		x = -1;
		point.x = x;
		while (map[y][++x])
		{
			if (map[y][x] == c)
			{
				point.y = y;
				point.x = x;
				return (point);
			}
		}
	}
	return (point);
}
