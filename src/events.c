/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:49:00 by albcamac          #+#    #+#             */
/*   Updated: 2025/05/29 17:31:20 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(t_game *g, int x, int y)
{
	char	tile;

	tile = g->map[y][x];
	return (tile == '0' || tile == 'C' || tile == 'E');
}

static void	handle_tile(t_game *g, int x, int y, char tile)
{
	if (tile == 'C')
	{
		g->collect_collected++;
		g->map[y][x] = '0';
	}
	else if (tile == 'E')
	{
		if (g->collect_collected == g->collect_total)
		{
			ft_printf("Victory!\n");
			exit(0);
		}
		else
		{
			ft_printf("Collectibles are missing!\n");
			return ;
		}
	}
}

void	move_player(t_game *g, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	tile;
	char	prev_tile;

	new_x = g->player_x + dx;
	new_y = g->player_y + dy;
	tile = g->map[new_y][new_x];
	prev_tile = g->map[g->player_y][g->player_x];
	if (!is_valid_move(g, new_x, new_y))
		return ;
	handle_tile(g, new_x, new_y, tile);
	if (prev_tile != 'E')
		g->map[g->player_y][g->player_x] = '0';
	g->player_x = new_x;
	g->player_y = new_y;
	g->moves++;
	ft_printf("Moves: %d\n", g->moves);
	render_map(g);
}

int	key_hook(int keycode, t_game *g)
{
	if (keycode == 65307)
		close_game(g);
	else if (keycode == 'w' || keycode == 119)
		move_player(g, 0, -1);
	else if (keycode == 's' || keycode == 115)
		move_player(g, 0, 1);
	else if (keycode == 'a' || keycode == 97)
		move_player(g, -1, 0);
	else if (keycode == 'd' || keycode == 100)
		move_player(g, 1, 0);
	return (0);
}

int	close_game(t_game *g)
{
	ft_printf("Closing the game...\n");
	if (g->map)
		free_map(g->map);
	if (g->player.img)
		mlx_destroy_image(g->mlx, g->player.img);
	if (g->wall.img)
		mlx_destroy_image(g->mlx, g->wall.img);
	if (g->floor.img)
		mlx_destroy_image(g->mlx, g->floor.img);
	if (g->collectible.img)
		mlx_destroy_image(g->mlx, g->collectible.img);
	if (g->exit.img)
		mlx_destroy_image(g->mlx, g->exit.img);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	exit(0);
	return (0);
}
