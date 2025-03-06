/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:28:00 by jpatrici          #+#    #+#             */
/*   Updated: 2025/03/05 16:41:21 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	render(t_win *data)
{
	int	y;
	int	x;
	int	n;
	t_point	coord;

	y = -1;

	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x] != '\n')
		{
			n = get_img(data->map[y][x]);
			coord.y = y * data->img_size.y;
			coord.x = x * data->img_size.x;
			mlx_put_image_to_window(data->mlx, data->win,
						data->txtr[n], coord.x, coord.y);
		}
	}
	return (0);
}

void	init_txtr(t_win *data)
{
	data->txtr = malloc(sizeof(void *) * 5);
	data->txtr[0] = mlx_xpm_file_to_image(data->mlx,
				   "./assets/space.xpm", &data->img_size.x, &data->img_size.y);
	data->txtr[1] = mlx_xpm_file_to_image(data->mlx,
				   "./assets/obst.xpm", &data->img_size.x, &data->img_size.y);
	data->txtr[2] = mlx_xpm_file_to_image(data->mlx,
				   "./assets/player.xpm", &data->img_size.x, &data->img_size.y);
	data->txtr[3] = mlx_xpm_file_to_image(data->mlx,
				   "./assets/coin.xpm", &data->img_size.x, &data->img_size.y);
	data->txtr[4] = mlx_xpm_file_to_image(data->mlx,
				   "./assets/exit.xpm", &data->img_size.x, &data->img_size.y);

}

int		get_img(char c)
{
	if(c == '0')
		return (0);
	if(c == '1')
		return (1);
	if(c == 'P')
		return (2);
	if(c == 'C')
		return (3);
	if(c == 'E')
		return (4);
	return (-1);
}


