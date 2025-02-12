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

typedef	struct s_point
{
	int		y;
	int		x;
}		t_point;

char	**map_check(char *s_map);
int	parse_file(char *map_file);
int		valid_map(char **map, int y);
void	get_size(char *map_file);
int		char_check(char **map);
t_point	init_point(char	**map, char c);
void	floodfill(char **map, t_point size, int col, int row);
int		coincount(char **map);
int		fill(char **map, int length, int width);
char **mapcpy(char **map, t_point size);

#endif // !SO_LONG
