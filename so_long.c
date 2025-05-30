/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:46:01 by albcamac          #+#    #+#             */
/*   Updated: 2025/05/29 17:45:17 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Usage: ./so_long maps/map.ber\n"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	game.map = parse_map(argv[1]);
	if (!game.map)
		return (ft_printf("Error\nMap Invalid\n"), 1);
	if (!validate_map(&game))
		return (free_map(game.map), 1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
			50 * map_width(game.map), 50 * map_height(game.map), "so_long");
	load_images(&game);
	find_player(&game);
	count_collectibles(&game);
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
}

/* int	main(int argc, char **argv)
{
	t_game	game;

	ft_printf("Iniciando programa\n");

	if (argc != 2)
		return (write(2, "Uso: ./so_long maps/map.ber\n", 29), 1);

	ft_memset(&game, 0, sizeof(t_game));
	ft_printf("Memoria inicializada\n");

	game.map = parse_map(argv[1]);
	ft_printf("Mapa cargado: %p\n", game.map);

	if (!game.map)
		return (write(2, "Error: mapa inválido\n", 22), 1);
	ft_printf("Mapa parseado\n");

	if (!validate_map(&game))
		return (1);
	ft_printf("Mapa validado\n");

	game.mlx = mlx_init();
	if (!game.mlx)
		return (write(2, "Error: mlx_init falló\n", 23), 1);
	ft_printf("MLX inicializado\n");

	int tile = 32;
	int win_w = tile * map_width(game.map);
	int win_h = tile * map_height(game.map);

	if (win_w > 1920 || win_h > 1080)
	{
		ft_printf("Error\nEl mapa es demasiado grande para la pantalla\n");
		free_map(game.map);
		exit(1);
	}
	ft_printf("Resolución aceptada: %dx%d\n", win_w, win_h);

	game.win = mlx_new_window(game.mlx, win_w, win_h, "so_long");
	if (!game.win)
		return (write(2, "Error: no se pudo crear la ventana\n", 36), 1);
	ft_printf("Ventana creada\n");

	load_images(&game);
	ft_printf("Imágenes cargadas\n");

	find_player(&game);
	count_collectibles(&game);
	ft_printf("Jugador y coleccionables localizados\n");

	render_map(&game);
	ft_printf("Mapa renderizado\n");

	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	ft_printf("Hooks registrados\n");

	mlx_loop(game.mlx);
	ft_printf("Bucle iniciado (esto no se imprimirá)\n");

	return (0);
} */
