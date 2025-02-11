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
	int		coins;
	char	target;

	size.y = length;
	size.x = width;
	coins = 0;
	p = init_point(map, 'P');
	target = map[p.y][p.x];
	ft_printf("hi\n");
	coins = floodfill(map, size, p.y, p.x);
	int i = -1;
	while(map[++i])
		ft_printf("%s", map[i]);
	if (coins == coincount(map))
		return (1);
	return (0);
}

int	floodfill(char **map, t_point size, int col, int row)
{
	int	coins;

	coins = 0;
	if (col <= 0 || row <= 0 || col >= size.y || row >= size.x)
		return (coins);
	if (map[col][row] == '2' || map[col][row] != 'P')
		return (coins);
	if (map[col][row] == 'C')
		coins++;
	map[col][row] = '2' + (map[col][row] == 'E');
	floodfill(map, size, col + 1, row);
	floodfill(map, size, col - 1, row);
	floodfill(map, size, col, row + 1);
	floodfill(map, size, col, row - 1);
	return (coins);
}

int	coincount(char **map)
{
	int	coins;
	int i;
	int j;

	coins = 0;
	i = 0;
	j = 0;
	while (map[++i])
	{
		while (map[i][++j])
			if (map[i][j] == 'C')
				coins++;
	}
	return (coins);
}

t_point	init_point(char	**map, char c)
{
	t_point	point;
	int		y;
	int		x;

	y = 0;
	x = 0;
	point.x = x;
	point.y = y;
	while (map[++y])
	{
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
