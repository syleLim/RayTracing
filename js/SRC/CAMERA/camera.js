const { Vector, addVector, subVector, 
		mulVector, crossVector, dotVector, 
		multiplyVector, getRot } = require("../../LIB/vector");
const Screen = require("../SCREEN/screen");
const Ray = require("../RAY/ray");

module.exports = class Camera {
	constructor (){
		this.pos = new Vector();
		this.dir = new Vector(-1, 0, 0);
		this.ori = new Vector(0, 0, 1);
		this.w = mulVector(this.dir, -1);
		this.u = crossVector(this.ori, this.w).norm();
		this.v = crossVector(this.w, this.u).norm();
		this.fov = 66 * Math.PI / 180;
		
		this.screen = new Screen();
		this.screen.setScreen(this.fov, this.w, this.u, this.v, this.pos);
		
		this.ray = new Ray();
		this.ray.setOrigin(this.pos.x, this.pos.y, this.pos.z);
	}

	setPos(x, y, z) {
		this.pos.set(x, y, z);
		this.screen.setScreen(this.fov, this.w, this.u, this.v, this.pos);
		this.ray.setOrigin(x, y, z);
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

	setCasting(objs, light) {
		for (let i = 0; i < this.screen.height; i++) {
			for (let j = 0; j < this.screen.width; j++) {
				this.ray.calDir(this.screen.origin,
					mulVector(this.screen.vertical, i / this.screen.height),
					mulVector(this.screen.horizontal, j / this.screen.width));
				this.ray.tracing(objs);
				//this.ray.hitter.calShadow(light, objs);
				this.screen.setView(this.ray.hitter, light, i, j);
			}
		}	
	}
}