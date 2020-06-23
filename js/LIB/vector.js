class Vector {
	constructor(x, y, z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}

	set (x, y, z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}

	len () {
		return Math.sqrt(this.x * this.x 
			+ this.y * this.y 
			+ this.z * this.z);
	}

	add (v) {
		this.x += v.x;
		this.y += v.y;
		this.z += v.z;
	}

	sub (v) {
		this.x -= v.x;
		this.y -= v.y;
		this.z -= v.z;
	}

	mul (t) {
		this.x *= t;
		this.y *= t;
		this.z *= t;
	}

	dot (v) {
		return this.x * v.x + this.y * v.y + this.z * v.z;
	}

	norm () {
		const len = this.len(this);
		
		this.x /= len;
		this.y /= len;
		this.z /= len;
	}

	multiply (v) {
		this.x *= v.x;
		this.y *= v.y;
		this.z *= v.z;
	}
}


const addVector = (v1, v2) => 
	new Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v1.z);

const subVector = (v1, v2) => 
	new Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v1.z);

const mulVector = (v, t) => 
	new Vector(t * v.x, t * v.y, t * v.z);

const dotVector = (v1, v2) => 
	v1.x * v2.x + v1.y * v2.y * v1.z * v2.z;

const crossVector = (v1, v2) => 
	new Vector(v1.y * v2.z - v1.z * v2.y,
				v1.z * v2.x - v1.x * v2.z,
				v1.x * v2.y - v1.y * v2.x);

const  multiplyVector = (v1, v2) => 
	new Vector(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);

const getAngle = (v1, v2) => 
	v1.dot(v2) / (v1.len() * v2.len());

module.exports =  { Vector ,addVector, subVector, 
		mulVector, crossVector, dotVector, 
		multiplyVector};