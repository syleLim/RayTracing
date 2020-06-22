# include "tracer.h"

int main()
{
	t_objs *objs = init_objs();
	t_sphere *s1 = init_sphere();
	t_sphere *s2 = init_sphere();
	add_sphere(objs, s1);
	add_sphere(objs, s2);
	t_plane *p = init_plane();
	add_plane(objs, p);

	t_camera *c = init_camera();
	t_screen *s = init_screen(c);
	t_light *l = init_light();
	printv("s o", s->origin);
	printv("s h", s->horizontal);
	printv("s v", s->vertical);

	t_ray *r = init_ray();
	t_hitter *h = init_hitter();

	tracing(objs, l, h,r, c, s);
}