/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:48:34 by albcamac          #+#    #+#             */
/*   Updated: 2025/05/29 17:11:16 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		moves;
	int		collect_total;
	int		collect_collected;
	t_img	player;
	t_img	collectible;
	t_img	wall;
	t_img	floor;
	t_img	exit;
}	t_game;

char	**parse_map(const char *path);
void	load_images(t_game *game);
void	render_map(t_game *game);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
int		map_width(char **map);
int		map_height(char **map);
void	find_player(t_game *g);
void	count_collectibles(t_game *g);
int		key_hook(int keycode, t_game *g);
void	move_player(t_game *g, int dx, int dy);
void	render_map(t_game *g);
int		close_game(t_game *game);
int		validate_map(t_game *g);
int		validate_chars_and_counts(t_game *g);
int		validate_rectangle(char **map);
int		validate_walls(char **map);
char	**duplicate_map(char **map);
void	free_map(char **map);
int		count_and_validate_chars(t_game *g, int *p, int *e, int *c);
void	flood_fill(char **map, int x, int y);
int		validate_path(t_game *g);
int		has_empty_or_whitespace_line(char **map);

#endif
