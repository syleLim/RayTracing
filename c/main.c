/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 11:19:11 by seolim            #+#    #+#             */
/*   Updated: 2020/07/22 12:32:30 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"
#include "export.h"

t_game	*init_game(void)
{
	t_game	*game;

	if (!(game = malloc(sizeof(t_game))))
		error_exit("Malloc Error Occured");
	game->camera_id = 0;
	game->components = init_components();
	game->objs = init_objs();
	return (game);
}

int		exit_event(void)
{
	exit(0);
}

int		key_event(int key, t_game *game)
{
	if (key == ESC)
		exit(0);
	if ((key == ONE || key == TWO || key == THREE || key == FOUR)
		&& key - 18 < game->components->camera_nums)
		game->camera_id = key - 18;
	tracing(game->objs,
		game->components,
		game->camera_id);
	return (TRUE);
}

int		main(int argc, char *argv[])
{
	int		fd;
	t_game	*game;

	game = init_game();
	fd = open("./DB/map.rt", O_RDONLY);
	parsing(fd, game->objs, game->components);
	tracing(game->objs,
		game->components,
		game->camera_id);
	if (argc == 1 && argv[0])
	{
		mlx_key_hook(game->components->window->window, &key_event, game);
		mlx_hook(game->components->window->window, 17, 0, &exit_event, game);
		mlx_loop(game->components->window->mlx);
	}
	else
		export_bmp("test.bmp", game->components->window);
}
