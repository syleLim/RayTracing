const { Vector, addVector, subVector, 
	mulVector, crossVector, dotVector, 
	multiplyVector, getRot } = require("../../LIB/vector");

module.exports = class Light {
	constructor () {
		this.pos = new Vector(0, 0, 0);
		this.color = new Vector(1, 1, 1);
		this.ambient = new Vector(0, 0, 0);
		this.intensity = 1;
	}

	setPos(x, y, z) {
		this.pos.set(x, y, z);
	}

	setColor(r, g, b) {
		this.color.set(x / 256, y / 256, z / 256);
	}

	setIntensity(intensity) {
		this.intensity = intensity;
	}

	setAmbient(r, g, b, ratio) {
		this.ambient.set(ratio * r / 256 , ratio * g / 256, ratio * b / 256);
	}

	getDiffuse(hitter, l) {
		const m = Math.max(hitter.normal.dot(l), 0);
		return multiplyVector(mulVector(this.color, m, this.intensity),
					hitter.color);
	}

	getSpecular(hitter, l) {
		const r = mulVector(hitter.normal, 2 * hitter.normal.dot(l))
					.sub(l);
		const v = subVector(hitter.origin, hitter.pos).norm();
		const m = Math.max(r.dot(v), 0);
		return multiplyVector(mulVector(this.color, m * this.intensity),
					hitter.color)
	}
}