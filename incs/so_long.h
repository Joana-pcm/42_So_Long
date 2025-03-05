/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:12:41 by jpatrici          #+#    #+#             */
/*   Updated: 2025/02/26 16:21:24 by jpatrici         ###   ########.fr       */
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

# define	W 119
# define	A 97
# define	S 115
# define	D 100
# define ESC 65307

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
	void	**txtr;
	char	**map;
	int		moves;
	t_point	size;
	t_point	img_size;
	t_point	player;
}		t_win;

/*			INITIALISING		*/

t_point	init_point(char	**map, char c);
void	init_data(char **map, t_win *data);
void	init_txtr(t_win *data);
int		ft_destroy(t_win *data);

/*			PARSING				*/

char	**map_check(char *s_map);
int		parse_file(char *map_file);
int		valid_map(char **map, int y);
void	get_size(char *map_file);
int		char_check(char **map);

/*			FLOODFILL			*/

void	floodfill(char **map, t_point size, int col, int row);
int		coincount(char **map, int e);
int		fill(char **map, int length, int width);
char	**mapcpy(char **map, t_point size);

/*			KEYHOOKS			*/

int		hooks(t_win *data);
int		keys(int symkey, t_win *data);

/*			MOVES				*/

int		moveup(t_win *data);
int		moveleft(t_win *data);
int		movedown(t_win *data);
int		moveright(t_win *data);

/*			GAME				*/

int		render(t_win *data);
int		get_img(char c);

#endif // !SO_LONG
