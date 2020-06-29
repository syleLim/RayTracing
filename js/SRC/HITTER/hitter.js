const { Vector, addVector, subVector, 
	mulVector, crossVector, dotVector, 
	multiplyVector, getRot } = require("../../LIB/vector");

module.exports = class Hitter {
	constructor () {
		this.isHit = false;
		this.t = -1;
		this.pos = new Vector();
		this.color = new Vector(1, 1, 1);
		this.normal = new Vector();
		this.origin = new Vector();
	}

	init (origin) {
		this.origin.set(origin.x, origin.y, origin.z);
		this.isHit = false;
		this.t = -1;
		this.pos.set(0, 0, 0);
		this.color = new Vector(1, 1, 1);
		this.normal = new Vector();
	}

	setHitter(pos, normal, color, t) {
		this.pos.set(pos.x, pos.y, pos.z);
		this.normal.set(normal.x, normal.y, normal.z)
		this.color.set(color.x, color.y, color.z);
		this.t = t;
		this.isHit = true;
	}

	checking(t, ray, normal, color) {
		if (t < this.t || !this.isHit)
			this.setHitter(addVector(ray.origin, mulVector(ray.dir, t)),
						normal, color, t);
	}

	calShadow(light, objs) {
		// TODO : cal shadow ray collision
	}
}