/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:12:41 by jpatrici          #+#    #+#             */
/*   Updated: 2025/02/05 17:12:43 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"

typedef	struct s_mark
{
	int		y;
	int		x;
}		t_mark;

int	map_check(char *s_map);
int	valid_map(char **map, int y);

#endif // !SO_LONG
