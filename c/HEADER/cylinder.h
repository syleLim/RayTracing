#ifndef CYLINDER_H
# define CYLINDER_H
# include "DB.h"
# include "vector.h"
# include "ray.h"
# include "hitter.h"

typedef struct	s_circle
{
	int			id;
	vec			pos;
	vec			normal;
	double		radius;
	vec			color;
}				t_circle;

typedef struct	s_cylinder
{
	int			id;
	vec			pos;
	t_circle	*circles[2];
	vec			normal;
	vec			p1;
	vec			p2;
	double		diameter;
	double		height;
	vec			color;
}				t_cylinder;

t_circle	*make_circle(vec pos, vec normal, double radius, vec color);
void		set_circle_pos(t_circle *circle, vec pos);
void		set_circle_normal(t_circle *circle, vec normal);
void		set_circle_radius(t_circle *circle, double radius);
void		set_circle_color(t_circle *circle, vec color);
void		collision_circle(t_circle *circle,
						t_ray *ray, t_hitter *hitter);
void		shadow_collision_circle(t_circle *circle,
							t_ray *ray, t_hitter *hitter);
void		collision_cylinder(t_cylinder *cylinder,
						t_ray *ray, t_hitter *hitter);
void		shadow_collision_cylinder(t_cylinder *cylinder,
							t_ray *ray, t_hitter *hitter);
t_cylinder	*init_cylinder();
void		set_cylinder_pos(t_cylinder *cylinder, vec pos);
void		set_cylinder_normal(t_cylinder *cylinder, vec normal);
void		set_cylinder_diameter(t_cylinder *cylinder, double diameter);
void		set_cylinder_height(t_cylinder *cylinder, double height);
void		set_cylinder_color(t_cylinder *cylinder, vec color);

#endif