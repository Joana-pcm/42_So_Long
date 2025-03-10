/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:11:14 by jpatrici          #+#    #+#             */
/*   Updated: 2025/02/13 16:07:39 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	**map;
	t_win	*data;

	map = NULL;
	data = NULL;
	if (ac != 2)
		return (ft_printf("Error\nInvalid number of arguments\n"));
	map = map_check(av[1]);
	if (!map || !char_check(map))
		return (ft_printf("Error\nInvalid map\n"));
	data = ft_calloc(sizeof(t_win), 1);
	if (!data)
		return (0);
	init_data(map, data);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, data->size.x, 
				data->size.y, "42_So_Long");
	init_txtr(data);
	render(data);
	hooks(data);
	mlx_loop(data->mlx);
}

void	init_data(char **map, t_win *data)
{	
	data->mlx = NULL;
	data->size = init_point(map, '\0');
	data->map = mapcpy(map, data->size);
	arrfree(map);
	data->player = init_point(data->map, 'P');
	data->moves = 0;
	data->img_size.x = 106;
	data->img_size.y = 106;
	data->size.y *= data->img_size.y;
	data->size.x *= data->img_size.x;
}

int	ft_destroy(t_win *data)
{
	arrfree(data->map);
	imgdestroy(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit (0);
	return (0);
}

