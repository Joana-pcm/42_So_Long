/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:25:03 by jpatrici          #+#    #+#             */
/*   Updated: 2025/02/26 15:29:55 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	hooks(t_win *data)
{
	mlx_hook(data->mlx, KeyRelease, KeyReleaseMask, &keys, &data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, &ft_destroy, &data);
	return (0);
}

int	keys(int symkey, t_win data)
{
	if (symkey == ESC)
	{
	exit(0);	
	}
	else if (symkey == W)
		moveup(data);
	else if (symkey == A)
		moveleft(data);
	else if (symkey == S)
		movedown(data);
	else if (symkey == D)
		moveright(data);
	(void) data;
	return (0);
}

int	moveup(t_win *data)
{
	t_point	p;

	p = data->player;
	
	if (data->map[p.x][p.y - 1] == '0' ||
	data->map[p.x][p.y - 1] == 'C')
	{
		data->map[p.x][p.y - 1] = 'P';
		data->map[p.x][p.y] = '0';
	}
	if (!coincount(data->map, 1))
		return (1);
		/*open the exit*/
	return (0);
}

int	moveleft(t_win *data)
{
	t_point	p;

	p = data->player;
	if (data->map[p.y][p.x - 1] == '0' ||
	data->map[p.y][p.x -1] == 'C')
	{
		data->map[p.x][p.y]
	}
}
int	movedown(t_win *data);
int	moveright(t_win *data);
