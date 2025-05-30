/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:13:02 by albcamac          #+#    #+#             */
/*   Updated: 2025/05/06 14:32:31 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	load_xpm(void *mlx, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	return (img);
}

void	load_images(t_game *game)
{
	game->wall = load_xpm(game->mlx, "textures/wall.xpm");
	game->floor = load_xpm(game->mlx, "textures/floor.xpm");
	game->player = load_xpm(game->mlx, "textures/player.xpm");
	game->collectible = load_xpm(game->mlx, "textures/collectible.xpm");
	game->exit = load_xpm(game->mlx, "textures/exit.xpm");
}

void	render_tile(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img, x * 50, y * 50);
}

void	render_map(t_game *g)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			tile = g->map[y][x];
			if (tile == '1')
				render_tile(g, g->wall.img, x, y);
			else if (tile == '0')
				render_tile(g, g->floor.img, x, y);
			else if (tile == 'C')
				render_tile(g, g->collectible.img, x, y);
			else if (tile == 'E')
				render_tile(g, g->exit.img, x, y);
			if (x == g->player_x && y == g->player_y)
				render_tile(g, g->player.img, x, y);
			x++;
		}
		y++;
	}
}
