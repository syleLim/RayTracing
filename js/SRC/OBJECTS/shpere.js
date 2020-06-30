const Object = require("./object")
const { Vector, addVector, subVector, 
	mulVector, crossVector, dotVector, 
	multiplyVector, getRot } = require("../../LIB/vector");

module.exports = class Sphere extends Object {
	constructor() {
		super();
		this.radius = 1;
	}

	equation(oc, dir) {
		const [a, b, c] = [dir.dot(dir), oc.dot(dir), 
						oc.dot(oc) - this.radius * this.radius];
		const discriminant = b * b - a * c;
		let value;

		if (discriminant < 0)
			return (-1);
		value = (-b - Math.sqrt(discriminant)) / a;
		if (value > 0)
			return (value);
		value = (-b + Math.sqrt(discriminant)) / a;
		if (value > 0)
			return (value);
		return (-1);
	}

	tracing(ray)  {
		const t = this.equation(subVector(ray.origin, this.pos), ray.dir);
		const normal = addVector(ray.origin, mulVector(ray.dir, t))
						.sub(this.pos).norm();
		if (t >= 0)
			ray.hitter.checking(t, ray, normal, this.color);
	}
}