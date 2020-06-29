const { Vector, addVector, subVector, 
	mulVector, crossVector, dotVector, 
	multiplyVector, getRot } = require("../../LIB/vector");

module.exports = class Object {
	constructor () {
		this.pos = new Vector();
		this.ori = new Vector(0, 0, 1);
		this.color = new Vector(1, 0, 0);
	}

	setPos(x, y, z) {
		this.pos.set(x, y, z);
	}
	
	setColor(r, g, b) {
		this.color.set(r / 256, g / 256, b / 256);
	}

	rotate(ori) {
		this.ori.set(ori.x, ori.y, ori.z);
	}
}