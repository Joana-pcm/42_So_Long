/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:43:25 by jpatrici          #+#    #+#             */
/*   Updated: 2025/03/10 18:48:57 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

char	*ft_gnl(int fd)
{
	static char	*line;
	int		i;

	i = 0;
	if (!line)
	{
		line = ft_strdup("");
		if (!line)
			return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_getline(line, fd, &i);
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

void	ft_getline(char *line, int fd, int *n)
{
	static char buffer[BUFFER_SIZE];
	static int	buffer_pos;
	static int	buffer_read;
	int	i;

	i = *n;
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break;
		}
		
		line = ft_strjoin(line, &buffer[buffer_pos++]);
		if (buffer[buffer_pos - 1] == '\n')
			break ;
	}
	*n = i;
}
