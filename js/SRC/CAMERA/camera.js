const { Vector, addVector, subVector, 
		mulVector, crossVector, dotVector, 
		multiplyVector} = require("../../LIB/vector");
const Screen = require("../SCREEN/screen")

module.exports = class Camera {
	constructor (){
		this.pos = new Vector(0, 0, 0);
		this.dir = new Vector(-1, 0, 0);
		this.ori = new Vector(0, 0, 1);
		this.w = mulVector(this.dir, -1);
		this.u = crossVector(this.ori, this.w);
		this.u.norm();
		this.v = crossVector(this.w, this.u);
		this.v.norm();
		this.fov = 66 * Math.PI / 180;
		this.screen = new Screen();
		this.screen.setScreen(this.fov, this.w, this.u, this.v, this.pos);
	}

	setPos(x, y, z) {
		this.pos.set(x, y, z);
	}

	setFov(fov) {
		this.fov = fov * Math.PI / 180;
	}

	rotate(ori) {
		// TODO : rotataion is get axis and angle and rotate
	}
}