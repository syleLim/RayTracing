#include "screen.h"

void		up_cross(vec dest, vec v)
{
	vec	temp;

	vzero(temp);
	temp[Z] = 1.;
	cross(dest, temp, v);
}

t_screen	*set_screen(t_screen *screen,
							vec origin, vec dir, double fov)
{
	double hh = tan(fov / 2);
	double hw = hh *
		((double)screen->width / (double)screen->height);
	vec w, u, v;
	vneg(w, dir);
	up_cross(u, w);
	cross(v, w, u);
	

}

t_screen	*init_screen(double width, double height)
{
	t_screen	*screen;

	if (!(screen = malloc(sizeof(t_screen))))
		return (NULL);
	screen->width = width;
	screen->height = height;
	vzero(screen->origin);
	vzero(screen->vertical);
	vzero(screen->horizontal);
	return (screen);
}