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
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, data->size.x, \
				data->size.y, "42_So_Long");
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x] != '\n')
		{
			n = get_img(data->map[y][x]);
			coord.y = (y + 1) * data->img_size.y;
			coord.x = (x + 1) * data->img_size.x;
			mlx_put_image_to_window(data->mlx, data->win,\
						data->txtr[n], coord.y, coord.x);
		}
	}
	return (0);
}

void	init_txtr(t_win *data)
{
	data->txtr = ft_calloc(sizeof(void **), 6);
	data->txtr[0] = NULL;
	data->txtr[1] = NULL;
	data->txtr[2] = NULL;
	data->txtr[3] = NULL;
	data->txtr[4] = NULL;
	data->txtr[0] = mlx_xpm_file_to_image(data->mlx,\
				   "./assets/space.xpm", &data->img_size.x, &data->img_size.y);
	data->txtr[1] = mlx_xpm_file_to_image(data->mlx,\
				   "./assets/obst.xpm", &data->img_size.x, &data->img_size.y);
	data->txtr[2] = mlx_xpm_file_to_image(data->mlx,\
				   "./assets/player.xpm", &data->img_size.x, &data->img_size.y);
	data->txtr[3] = mlx_xpm_file_to_image(data->mlx,\
				   "./assets/coin.xpm", &data->img_size.x, &data->img_size.y);
	data->txtr[4] = mlx_xpm_file_to_image(data->mlx,\
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


