#include "light.h"
#include "ray.h"
#include "screen.h"
#include "sphere.h"

int main()
{
	vec src = {1, 2, 3};
	
	// t_light *l = init_light(src, 0.5, 0.5);
	// printv("light", l->pos);

	// t_ray *ray = init_ray(src);
	// printv("ray", ray->origin);
	// printv("ray", ray->dir);

	// t_camera *c = init_camera();	
	// t_screen *s = init_screen(c);

	// printv("c dir", c->dir);
	// printv("c w", c->w);
	// printv("c v", c->v);
	// printv("c u", c->u);
	
	// printv("s o", s->origin);
	// printv("s h", s->horizontal);
	// printv("s v", s->vertical);
	
	// vec rot;

	// vmake(rot, 1, 1, 1);
	// vnormalize(rot);
	// camera_rotate(c, rot);
	// printv("c dir", c->dir);
	// printv("c w", c->w);
	// printv("c v", c->v);
	// printv("c u", c->u);

	t_sphere *s = init_sphere();
	t_ray * r = init_ray();
	t_hitter *h = init_hitter();

	vec pos = {-1, 0, 0};
	set_sphere_pos(s, pos);
	set_ray_dir(r, pos);
	collision_sphere(s, r, h);

	printv("h", h->pos);
}