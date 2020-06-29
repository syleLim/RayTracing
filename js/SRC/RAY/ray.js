const { Vector, addVector, subVector, 
	mulVector, crossVector, dotVector, 
	multiplyVector, getRot } = require("../../LIB/vector");
const Hitter = require("../HITTER/hitter")

module.exports = class Ray {
	constructor () {
		this.origin = new Vector();
		this.dir = new Vector(-1, 0, 0)
		this.hitter = new Hitter();
	}

	setOrigin(x, y, z) {
		this.origin.set(x, y, z);
	}

	setDir(dir) {
		this.dir.set(dir.x,  dir.y, dir.z);
	}

	calDir(origin, u, v) {
		this.setDir(addVector(addVector(origin, u), v));
	}

	tracing(objs) {
		this.hitter.init(this.origin);
	
		objs.forEach(obj => {
			obj.tracing(this);
		});
	}
}