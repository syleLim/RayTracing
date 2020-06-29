const { Vector ,addVector, subVector, 
	mulVector, crossVector, dotVector, 
	multiplyVector} = require("../../LIB/vector");

module.exports = class Screen {
	constructor () {
		this.width = 640;
		this.height = 480;
		this.map = [];
	}

	setWidth (width, height) {
		this.width = width;
		this.height = height;
	}

	setScreen(fov, w, u, v, pos) {
		const sw = Math.tan(fov / 2);
		const sh = sw * this.height / this.width;	
		this.origin = subVector(
			subVector(
				subVector(pos, mulVector(u, sw)), mulVector(v, sh)),
			w);
		this.horizontal = mulVector(u, 2 * sw);
		this.vertical = mulVector(v, 2 * sh);
	}

	getColoring(hitter, light) {
		const l = subVector(light.pos, hitter.pos).norm();
		const diffuse = light.getDiffuse(hitter, l);
		const specular = light.getSpecular(hitter, l);
		const color = addVector(diffuse, specular).map(e => {
			if (e > 1) 
				return 1;
			else
				return e;
		});
		return {r : color.x * 255 ,
			g : color.y * 255,
			b : color.z * 255, a : 255};
	}

	setView(hitter, light, i, j) {
		if (hitter.isHit)
			this.map.push({x : j, y : i,
					color : this.getColoring(hitter, light)});
	}
}