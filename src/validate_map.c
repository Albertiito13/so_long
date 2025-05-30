/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:16:17 by albcamac          #+#    #+#             */
/*   Updated: 2025/05/29 17:42:05 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_chars_and_counts(t_game *g)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	if (!count_and_validate_chars(g, &p, &e, &c))
		return (0);
	if (p != 1 || e != 1 || c < 1)
	{
		ft_printf("Error\nMap must have 1 P, 1 E and at least 1 C\n");
		return (0);
	}
	return (1);
}

int	has_empty_or_whitespace_line(char **map)
{
	int	i;
	int	j;

	if (!map)
		return (1);
	i = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][0] == '\0')
			return (1);
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '\t' && map[i][j] != '\r')
				break ;
			j++;
		}
		if (map[i][j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	validate_rectangle(char **map)
{
	int	width;
	int	y;

	if (!map || !map[0])
	{
		ft_printf("Error\nMap is empty or invalid\n");
		return (0);
	}
	if (has_empty_or_whitespace_line(map))
	{
		ft_printf("Error\nMap contains an empty line or only spaces\n");
		return (0);
	}
	width = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		if ((int)ft_strlen(map[y]) != width)
		{
			ft_printf("Error\nMap is not rectangular\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	validate_walls(char **map)
{
	int	width;
	int	height;
	int	x;
	int	y;

	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (ft_printf("Error\nMap is not closed (top/bottom)\n"), 0);
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (ft_printf("Error\nMap is not closed (sides)\n"), 0);
		y++;
	}
	return (1);
}

int	validate_map(t_game *g)
{
	if (!validate_rectangle(g->map))
		return (0);
	if (!validate_chars_and_counts(g))
		return (0);
	if (!validate_walls(g->map))
		return (0);
	find_player(g);
	if (!validate_path(g))
		return (0);
	return (1);
}
