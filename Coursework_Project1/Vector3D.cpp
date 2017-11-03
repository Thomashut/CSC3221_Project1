#include "Vector3D.h";
#include <math.h>;

/*
	Author: Thomas Hutchinson
	Project: CSC3221 - Programming for Games - Project 1
	File Name: Vector3D.cpp
	Description:
		Source file for the Vector3D class. The vector3D class provides the features
		of a vector workiing within 3D space. The class itself will allow the user
		to perform various equations upon the vector against other vectors as well
		as get and change the information of the vector itself.
*/

// Copy constructor, takes another vector and copyies values over
Vector3D::Vector3D(const Vector3D* vector)
{
	float x, y, z;
	x = vector->getx();
	y = vector->gety();
	z = vector->getz();
	
	this->setx(x);
	this->sety(y);
	this->setz(z);
}

Vector3D::Vector3D(float x, float y, float z)
{
	this->setx(x);
	this->sety(y);
	this->setz(z);
}

// Deafault constructor
Vector3D::Vector3D()
{
	this->setx(DEFAULT_CORD);
	this->sety(DEFAULT_CORD);
	this->setz(DEFAULT_CORD);
}

// Deconstructor for vector to clean up all memory usage
Vector3D::~Vector3D()
{
	delete this->x;
	delete this->y;
	delete this->z;
}

// Returns the x value of the current vector
float Vector3D::getx() const
{
	return *x;
}

// Returns the y value of the current vector
float Vector3D::gety() const
{
	return *y;
}

// Returns the z value of the current vector
float Vector3D::getz() const
{
	return *z;
}

// Computes the magnitude of the current vector and returns it as a float
float Vector3D::computeMagnitude() const
{
	// Return the square root of the sum of all coordinates to the power of 2
	return sqrt(pow(this->getx(), 2.0) + pow(this->gety(), 2.0) + pow(this->getz(), 2.0));
}

// Calculate the sum of the current vector and a given vector -- Overloads the + opeartor
Vector3D Vector3D::operator+(Vector3D* rhs)
{
	this->setx(this->getx() + rhs->getx());
	this->sety(this->gety() + rhs->gety());
	this->setz(this->getz() + rhs->getz());

	return *this;
}

// Subtract the current vector from a given vector -- Overloads the - operator
Vector3D Vector3D::operator-(Vector3D* rhs)
{
	this->setx(this->getx() - rhs->getx());
	this->sety(this->gety() - rhs->gety());
	this->setz(this->getz() - rhs->getz());

	return *this;
}

// Multiply the current vector by a given scalar -- Overloads the * operator
Vector3D Vector3D::operator*(float scalar)
{
	this->setx(this->getx() * scalar);
	this->sety(this->gety() * scalar);
	this->setz(this->getz() * scalar);
	return *this;
}

// Divide the current vector by a given scalar -- Overloads the / operator
Vector3D Vector3D::operator/(float scalar)
{
	// Check to ensure that no elements in the vector or the scalar are zero to avoid divide by 0 errors
	if (scalar == 0 || this->getx() == 0 || this->gety() == 0 || this->getz() == 0)
		throw "Divide by zero error!";

	this->setx(this->getx() / scalar);
	this->sety(this->gety() / scalar);
	this->setz(this->getz() / scalar);
	return *this;
}

// Cross Product of Two Vectors (this and the given vector rhs)
Vector3D Vector3D::operator%(Vector3D* rhs)
{
	/*
				Vector3D(y1 * z2 - z1 * y2,
			x1 * z2 - z1 * x2,
			x1 * y2 - y2 * x1)
	*/
	if (rhs == nullptr)
		throw "NOT A REAL VECTOR!";

	// Floats used to store the intermediate values of the vector calculation
	float x = DEFAULT_CORD;
	float y = DEFAULT_CORD;
	float z = DEFAULT_CORD;

	// Calculate the cross product
	x = (gety() * rhs->getz()) - (this->getz() * rhs->gety());
	y = (this->getz() * rhs->getx()) - (this->getx() * rhs->getz());
	z = (this->getx() * rhs->gety()) - (this->gety() * rhs->getx());

	// Assign the temp variables to the this
	this->setx(x);
	this->sety(y);
	this->setz(z);

	// Return the object so that multiple operators may be stacked
	return *this;
}

// Assignment operator overload, will properly copy another vector making sure to clean memory as it goes
Vector3D& Vector3D::operator=(Vector3D* rhs)
{
	if (rhs == nullptr)
		throw ("Not a real Vector!");
		
	if (this == rhs);
		return *this; // If objecs are equal just return the current object

	// Setter method handles memory managment deleting and setting
	this->setx(rhs->getx());
	this->sety(rhs->gety());
	this->setz(rhs->getz());

	return *this;
}

// Overload the equals method to ensure correct sense of equals
bool Vector3D::operator==(Vector3D* rhs) const
{
	return (this->getx() == rhs->getx() &&
		this->gety() == rhs->gety() &&
		this->getz() == rhs->getz());
}

// Calculates the unit vector of the current vector. Returns a new unit vector **user must delete this themselves!
Vector3D Vector3D::unitVector()
{
	float mag = this->computeMagnitude(); // Calculate magnitude once as it can be an resource intensive function

	Vector3D* unitVector = new Vector3D(); // Create a default vector to store the unit vector in

	// Divide the current vector by it's magnitude and store that in the new unit vector
	unitVector->setx(this->getx() / mag);
	unitVector->sety(this->gety() / mag);
	unitVector->setz(this->getz() / mag);

	return unitVector;
}

/*
	Computes the unit vector orthogonal by:
	1. Calculating the cross product of the current vector and the given vector (rhs)
	2. It then divides that new cross product vector by it's own magnitude
	3. This will give the unit vector orthogonal of the origional vector and the given vector

	This will then become equal to the unit vector orthogonal
*/
Vector3D Vector3D::unitVectorOrthogonal(Vector3D* rhs)
{
	// Calcuate the cross product of the current vector and the right hand side
	*this % rhs;

	// Divide the cross product vector by the calculated magnitude of the cross product vector
	*this / this->computeMagnitude();
	
	// Return this which is now the unit vector orthongional 
	return *this;
}

/*
	These setters will take a float and turn that into a dynamic object upon the heap
	The setter will then assign the corrasponding pointer in the object to that new float on the heap
	If the setter finds the object already holds a value then it will delete that value first before
	assigning the new to avoid memory overflows
*/
void Vector3D::setx(float x)
{
	if (this->x)
	{
		//delete this->x;
		this->x = new float(x);
	}
	else
	{
		this->x = new float(x);
	}
}

void Vector3D::sety(float y)
{
	if (this->y == nullptr)
		this->y = new float(y);
	else
	{
		//delete this->y;
		this->y = new float(y);
	}
}

void Vector3D::setz(float z)
{
	if (this->z == nullptr)
		this->z = new float(z);
	else
	{
		//delete this->z;
		this->z = new float(z);
	}
}