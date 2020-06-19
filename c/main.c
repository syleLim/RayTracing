#include "light.h"
#include "ray.h"
#include "screen.h"

int main()
{
	vec src = {1, 2, 3};
	
	// t_light *l = init_light(src, 0.5, 0.5);
	// printv("light", l->pos);

	// t_ray *ray = init_ray(src);
	// printv("ray", ray->origin);
	// printv("ray", ray->dir);

	t_camera *c = init_camera();	
	t_screen *s = init_screen(c);

	printv("c w", c->w);
	printv("c v", c->v);
	printv("c u", c->u);
	
	printv("s o", s->origin);
	printv("s h", s->horizontal);
	printv("s v", s->vertical);
	
	vec rot;

	vmake(rot, 1, 1, 1);
	vnormalize(rot);
	camera_rotate(c, rot);
	printv("c w", c->w);
	printv("c v", c->v);
	printv("c u", c->u);
}