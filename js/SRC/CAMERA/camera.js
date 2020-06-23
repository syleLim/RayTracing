const { Vector, addVector, subVector, 
		mulVector, crossVector, dotVector, 
		multiplyVector, getRot } = require("../../LIB/vector");
const Screen = require("../SCREEN/screen")

module.exports = class Camera {
	constructor (){
		this.pos = new Vector(0, 0, 0);
		this.dir = new Vector(-1, 0, 0);
		this.ori = new Vector(0, 0, 1);
		this.w = mulVector(this.dir, -1);
		this.u = crossVector(this.ori, this.w).norm();
		this.v = crossVector(this.w, this.u).norm();
		this.fov = 66 * Math.PI / 180;
		this.screen = new Screen();
		this.screen.setScreen(this.fov, this.w, this.u, this.v, this.pos);
	}

	setPos(x, y, z) {
		this.pos.set(x, y, z);
		this.screen.setScreen(this.fov, this.w, this.u, this.v, this.pos);
	}

	setFov(fov) {
		this.fov = fov * Math.PI / 180;
		this.screen.setScreen(this.fov, this.w, this.u, this.v, this.pos);
	}

	rotate(ori) {
		const rot = getRot(this.ori, ori);
		this.dir.rotate(rot).norm();
		this.w.rotate(rot).norm();
		this.u.rotate(rot).norm();
		this.v.rotate(rot).norm();
		this.ori.set(ori.x, ori.y, ori.z)
		this.screen.setScreen(this.fov, this.w, this.u, this.v, this.pos);
	}
}