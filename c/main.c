# include "tracer.h"
# include "export.h"

t_game	*init_game()
{
	t_game	*game;

	if(!(game = malloc(sizeof(t_game))))
		exit(1);
	game->camera_id = 0;
	game->components = init_components();
	game->objs = init_objs();
	return (game);
}



void ft_printf(t_game *game)
{
	t_window *w = game->components->window;
	
	printf("====componentest====\n");
	printf("window : \n");
	printf("\tsize : %d, %d\n", w->width, w->height);
	int i = -1;
	while (++i < game->components->camera_nums)
	{
		t_camera *c = game->components->cameras[i];
		printf("camera - %d : \n", i);
		printv("\tpos : ", c->pos);
		printv("\tdir : ", c->dir);
		printv("\tori : ", c->up);
		printv("\tw : ", c->w);
		printv("\tu : ", c->u);
		printv("\tv : ", c->v);
		printf("\tfov : %.3f\n", c->fov);
		t_screen *s = game->components->screens[i];
		printf("screen - %d : \n", i);
		printv("\tvertical : ", s->vertical);
		printv("\torigin : ", s->origin);
		printv("\thorizontal : ", s->horizontal);
	}
	// while (++i < game->components->light_nums)
	// {
	// 	t_light *l = game->components->lights[i];
	// 	printf("light - %d :", i);
	// 	printv("\tpos :", l->pos);
	// 	printv("\tcolor :", l->color);
	// }
	// printv("\tambient : ", game->components->ambient);
	// t_sphere *sp = game->objs->spheres[0];
	// t_plane *p = game->objs->planes[0];
	// t_square *sq = game->objs->squares[0];
	// t_cylinder *cy = game->objs->cylinders[0];
	// t_triangle *t = game->objs->triangles[0];

	// printf("\n\n======objects=====\n");
	// printf("sphere :\n");
	// printv("\tpos : ", sp->pos);
	// printf("\trad : %.3f\n", sp->radius);
	// printv("\tcolor : ", sp->color);
	// printf("plane :\n");
	// printv("\tpos : ", p->point);
	// printv("\tnormal : ", p->normal);
	// printv("\tcolor : ", p->color);
	// printf("square :\n");
	// printv("\tpos : ", sq->pos);
	// printv("\tnormal : ", sq->normal);
	// printf("\tsize : %.3f\n", sq->size);
	// printv("\tcolor : ", sq->color);
	// printf("cylinder :\n");
	// printv("\tpos : ", cy->pos);
	// printv("\tnormal : ", cy->normal);
	// printf("\tdiameter : %.3f\n", cy->diameter);
	// printf("\theight : %.3f\n", cy->height);
	// printv("\tcolor : ", cy->color);
	// printf("triangle :\n");
	// printv("\ta : ", t->a);
	// printv("\tb : ", t->b);
	// printv("\tc : ", t->c);
	// printv("\tcolor : ", t->color);
}

int exit_event()
{
	exit(0);
}

int	key_event(int key, t_game *game)
{
	if (key == ESC)
		exit(0);
	if ((key == ONE || key == TWO || key == THREE || key == FOUR)
		&& key - 18 < game->components->camera_nums)
		game->camera_id = key - 18;
	//if ((key == UP || key == DOWN || key == RIGHT || key == LEFT))
	//	move_camera(game->components->cameras, key);
	tracing(game->objs,
		 game->components,
		 game->camera_id);
	return (TRUE);
}

int expose_event()
{
	printf("work?\n");
	return (TRUE);
}

int main(int argc, char *argv[])
{
	int		fd;
	t_game	*game;

	game = init_game();
	fd = open("./DB/map.rt", O_RDONLY);
	parsing(fd, game->objs, game->components);
	ft_printf(game);
	tracing(game->objs,
		 game->components,
		 game->camera_id);
	if (argc == 1)
	{
		mlx_key_hook(game->components->window->window, &key_event, game);
		mlx_hook(game->components->window->window, 17, 0, &exit_event, game);
		mlx_loop(game->components->window->mlx);
	}
	else
		export_bmp("test.bmp", game->components->window);
}
