const { Vector, addVector, subVector, 
	mulVector, crossVector, dotVector, 
	multiplyVector, getRot } = require("../LIB/vector")
const Camera = require("./CAMERA/camera");

const ca = new Camera();

const ori = new Vector(1, 1, 1);
ori.norm();

ca.rotate(ori);

console.log(ca);
