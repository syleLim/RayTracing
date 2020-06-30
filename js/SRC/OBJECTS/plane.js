const Object = require("./object")
const { Vector, addVector, subVector, 
	mulVector, crossVector, dotVector, 
	multiplyVector, getRot, normalizeVector } = require("../../LIB/vector");

module.exports = class Plane extends Object {
	constructor() {
		super();
		this.normal = normalizeVector(this.ori);
	}

	rotate(ori) {
		this.normal = normalizeVector(ori);
	}

	equation(origin, dir) {
		
		if (this.normal.dot(dir) === 0)
			return (-1);
		return (this.normal.dot(this.pos) - this.normal.dot(origin)) 
					/ this.normal.dot(dir);
	}

	tracing(ray)  {
		const t = this.equation(ray.origin, ray.dir);
		
		if (t >= 0)
			ray.hitter.checking(t, ray, this.normal, this.color);
	}
}