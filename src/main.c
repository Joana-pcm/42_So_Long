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
	void	*mlx;
	void	*win;

	map = NULL;
	if (ac != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	map = map_check(av[1]);
	if (!map || !char_check(map))
		return (ft_printf("Error\nInvalid map\n"));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "IDK");
	mlx_loop(mlx);
	return (0);
}

