/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:12:41 by jpatrici          #+#    #+#             */
/*   Updated: 2025/02/13 16:03:20 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct s_point
{
	int		y;
	int		x;
}		t_point;

typedef struct s_win
{
	void	*mlx;
	void	*img;
	void	*win;
	t_point	img_size;
	t_point	player;
} t_win;

/*			INITIALISING		*/

t_point	init_point(char	**map, char c);
void	init_window(t_win *window);
void	ft_exit(t_win *window);

/*			PARSING				*/

char	**map_check(char *s_map);
int		parse_file(char *map_file);
int		valid_map(char **map, int y);
void	get_size(char *map_file);
int		char_check(char **map);

/*			FLOODFILL			*/

void	floodfill(char **map, t_point size, int col, int row);
int		coincount(char **map);
int		fill(char **map, int length, int width);
char	**mapcpy(char **map, t_point size);

#endif // !SO_LONG
