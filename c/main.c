# include "tracer.h"
# include <fcntl.h>
# include <unistd.h>
t_game	*init_game()
{
	t_game	*game;

	if(!(game = malloc(sizeof(t_game))))
		exit(1);
	game->components = init_components();
	game->objs = init_objs();
	return (game);
}

void ft_printf(t_game *game)
{
	t_window *w = game->components->window;
	t_camera *c = game->components->camera;
	//t_screen *s = game->components->screen;
	t_light *l = game->components->light;

	printf("====componentest====\n");
	printf("window : \n");
	printf("\tsize : %d, %d\n", w->width, w->height);
	printf("camera : \n");
	printv("\tpos : ", c->pos);
	printv("\tdir : ", c->dir);
	printv("\tori : ", c->up);
	printf("\tfov : %.3f\n", c->fov);
	printf("light :");
	printv("\tpos :", l->pos);
	printv("\tcolor :", l->color);
	printv("\tambi :", l->ambient);

	t_sphere *sp = game->objs->spheres[0];
	t_plane *p = game->objs->planes[0];
	t_square *sq = game->objs->squares[0];
	t_cylinder *cy = game->objs->cylinders[0];
	t_triangle *t = game->objs->triangles[0];

	printf("\n\n======objects=====\n");
	printf("sphere :\n");
	printv("\tpos : ", sp->pos);
	printf("\trad : %.3f\n", sp->radius);
	printv("\tcolor : ", sp->color);
	printf("plane :\n");
	printv("\tpos : ", p->point);
	printv("\tnormal : ", p->normal);
	printv("\tcolor : ", p->color);
	printf("square :\n");
	printv("\tpos : ", sq->pos);
	printv("\tnormal : ", sq->normal);
	printf("\tsize : %.3f\n", sq->size);
	printv("\tcolor : ", sq->color);
	printf("cylinder :\n");
	printv("\tpos : ", cy->pos);
	printv("\tnormal : ", cy->normal);
	printf("\tdiameter : %.3f\n", cy->diameter);
	printf("\theight : %.3f\n", cy->height);
	printv("\tcolor : ", cy->color);
	printf("triangle :\n");
	printv("\ta : ", t->a);
	printv("\tb : ", t->b);
	printv("\tc : ", t->c);
	printv("\tcolor : ", t->color);
}

int main()
{
	int		fd;
	t_game	*game;

	game = init_game();
	fd = open("./DB/map.rt", O_RDONLY);
	
	parsing(fd, game->objs, game->components);

	
	//ft_printf(game);
	tracing(game->objs,
		 game->components->light,
		game->components->screen,
		game->components->window);
	mlx_loop(game->components->window->mlx);
}