const { Vector ,addVector, subVector, 
	mulVector, crossVector, dotVector, 
	multiplyVector} = require("../../LIB/vector");

module.exports = class Screen {
	constructor () {
		this.width = 640;
		this.height = 480;
	}

	setWidth (width, height) {
		this.width = width;
		this.height = height;
	}

	setScreen(fov, w, u, v, pos) {
		const sw = Math.tan(fov / 2);
		const sh = w * this.height / this.width;	
		this.origin = subVector(
			subVector(
				subVector(pos, mulVector(u, sw)), mulVector(v, sh)),
			w);
		this.horizontal = mulVector(u, 2 * sw);
		this.vertical = mulVector(v, 2 * sh);
	}
}