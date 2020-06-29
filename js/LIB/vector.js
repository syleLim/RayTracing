const addVector = (v1, v2) => 
	new Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);

const subVector = (v1, v2) => 
	new Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);

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

const getRot = (before, after) => {
	const axis = crossVector(before, after);
	const c = getAngle(before, after);
	const s = Math.sqrt(1 - c * c);
	const rot = [
			new Vector(axis.x * axis.x * (1 - c) + c,
			axis.x * axis.y * (1 - c) + axis.z * s,
			axis.x * axis.z * (1 - c) - axis.y * s),
			new Vector(axis.x * axis.y * (1 - c) - axis.z * s,
			axis.y * axis.y * (1 - c) + c,
			axis.y * axis.z * (1 - c) - axis.x * s),
			new Vector(axis.x * axis.z * (1 - c) + axis.y * s,
			axis.y * axis.z * (1 - c) - axis.x * s,
			axis.z * axis.z * (1 - c) + c)
		]
	return (rot);
}

class Vector {
	constructor(x = 0, y = 0, z = 0) {
		this.x = x;
		this.y = y;
		this.z = z;
		return (this);
	}

	set (x, y, z) {
		this.x = x;
		this.y = y;
		this.z = z;
		return (this);
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
		return (this);
	}

	sub (v) {
		this.x -= v.x;
		this.y -= v.y;
		this.z -= v.z;
		return (this);
	}

	mul (t) {
		this.x *= t;
		this.y *= t;
		this.z *= t;
		return (this);
	}

	dot (v) {
		return this.x * v.x + this.y * v.y + this.z * v.z;
	}

	norm () {
		const len = this.len();
		
		this.x /= len;
		this.y /= len;
		this.z /= len;
		return (this);
	}

	multiply (v) {
		this.x *= v.x;
		this.y *= v.y;
		this.z *= v.z;
		return (this);
	}

	rotate(rot) {
		const temp = [ this.dot(rot[0]), this.dot(rot[1]), this.dot(rot[2]) ];
		this.x = temp[0];
		this.y = temp[1];
		this.z = temp[2];
		return (this);
	}

	map(callback) {
		const x = callback(this.x);
		const y = callback(this.y);
		const z = callback(this.z);
		return new Vector(x, y, z);
	}
}

module.exports =  { Vector ,addVector, subVector, 
		mulVector, crossVector, dotVector, 
		multiplyVector, getRot};