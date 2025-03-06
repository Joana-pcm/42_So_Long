/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:50:19 by jpatrici          #+#    #+#             */
/*   Updated: 2025/03/06 20:18:07 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

/*void	memfree(t_win *data, char **map)*/
/*{*/
/*}*/

void	arrfree(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	imgdestroy(t_win *data)
{
	int	i;

	i = -1;
	while (++i < 5)
		mlx_destroy_image(data->mlx, data->txtr[i]);
	free(data->txtr);
}
