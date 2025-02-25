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

int	main(int ac, char **av)
{
	char	**map;
	t_win	*window;

	map = NULL;
	window = NULL;
	if (ac != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	map = map_check(av[1]);
	if (!map || !char_check(map))
		return (ft_printf("Error\nInvalid map\n"));
	init_window(window);
	ft_exit(window);
	return (0);
}

void	init_window(t_win *window)
{
	window = malloc(sizeof(t_win *));
	window->mlx = mlx_init();
	window->img = mlx_new_image(window->mlx, 1920, 1080);
	window->img_size.x = 102;
	window->img_size.y = 102;
	window->win = mlx_new_window(window->mlx, window->img_size.x, window->img_size.y, "42_So_Long");
	mlx_loop(window->mlx);
}

void	ft_exit(t_win *window)
{
	ft_free("1t", window);
}
