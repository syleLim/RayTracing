const { Vector, addVector, subVector, 
	mulVector, crossVector, dotVector, 
	multiplyVector, getRot } = require("../LIB/vector")
const Camera = require("./CAMERA/camera");
const Sphere = require("./OBJECTS/shpere");
const Light = require("./LIGHT/light");

const camera = new Camera();
const sphere = new Sphere();

sphere.setPos(-4, 0, 0);
const objs = [sphere];
const light = new Light();
light.setPos(-4, 0, 4);

camera.setCasting(objs, light);

// console.log(camera);
// console.log(light);
// console.log(objs[0]);

//console.log(camera.screen.map);
const { createCanvas, createImageData, Image } = require("canvas");
const fs = require("fs");
const canvas = createCanvas(camera.screen.width, camera.screen.height);
const ctx = canvas.getContext("2d");
const image = createImageData(camera.screen.width, camera.screen.height);


camera.screen.map.forEach(({x, y, color}) => {
	let index = (x + y * camera.screen.width) * 4;
	image.data[index + 0] = color.r;
	image.data[index + 1] = color.g;
	image.data[index + 2] = color.b;
	image.data[index + 3] = color.a;
	//console.log(x, y, color);
	
})


ctx.putImageData(image, 0, 0);

const out = fs.createWriteStream("./test.png");
const stream = canvas.createPNGStream();

stream.on("data", chunk => {
	out.write(chunk);
})

stream.on("end", chunk => {
	console.log("end")
})
