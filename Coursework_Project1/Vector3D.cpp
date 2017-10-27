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
	this->x = vector->getx;
	this->y = vector-> gety;
	this->z = vector->getz;
}

Vector3D::Vector3D(float x, float y, float z)
{
	this->setx(x);
	this->sety(y);
	this->setz(z);
}

Vector3D::Vector3D()
{
	this->setx(0);
	this->sety(0);
	this->setz(0);
}

float Vector3D::getx()
{
	return *this->x;
}

float Vector3D::gety()
{
	return *this->y;
}

float Vector3D::getz()
{
	return *this->z;
}

float Vector3D::computeMagnitude()
{
	// Return the square root of the sum of all coordinates to the power of 2
	return sqrt(pow(this->getx, 2.0) + pow(this->gety, 2.0) + pow(this->getz, 2.0));
}

Vector3D Vector3D::operator+(Vector3D* rhs)
{
	this->setx(this->getx + rhs->getx);
	this->sety(this->gety + rhs->gety);
	this->setz(this->getz + rhs->getz);

	return *this;
}

Vector3D Vector3D::operator-(Vector3D* rhs)
{
	this->setx(this->getx - rhs->getx);
	this->sety(this->gety - rhs->gety);
	this->setz(this->getz - rhs->getz);

	return *this;
}

Vector3D Vector3D::operator*(float scalar)
{
	this->setx(this->getx * scalar);
	this->sety(this->gety * scalar);
	this->setz(this->getz * scalar);
	return *this;
}

Vector3D Vector3D::operator/(float scalar)
{
	this->setx(this->getx / scalar);
	this->sety(this->gety / scalar);
	this->setz(this->getz / scalar);
	return *this;
}

// TO-DO
Vector3D Vector3D::operator%(Vector3D* rhs)
{
	return this;
}

// TO-DO
Vector3D& Vector3D::operator=(Vector3D* rhs)
{
	if (rhs == nullptr)
		// throw error
		
	if (this == rhs);
		return *this; // If objecs are equal just return the current object

	// Setter method handles memory managment deleting and setting
	this->setx(rhs->getx);
	this->sety(rhs->gety);
	this->setz(rhs->getz);

	return *this;
}

// Overload the equals method to ensure correct sense of equals
bool Vector3D::operator==(Vector3D* rhs)
{
	return (this->getx == rhs->getx &&
		this->gety == rhs->gety &&
		this->getz == rhs->getz);
}

// TO-DO
Vector3D Vector3D::unitVector(Vector3D* rhs)
{
	return this;
}

// TO-DO
Vector3D Vector3D::unitVectorOrthogonal(Vector3D* v1, Vector3D* v2)
{
	return this;
}

/*
	These setters will take a float and turn that into a dynamic object upon the heap
	The setter will then assign the corrasponding pointer in the object to that new float on the heap
	If the setter finds the object already holds a value then it will delete that value first before
	assigning the new to avoid memory overflows
*/
void Vector3D::setx(float x)
{
	if (this->getx == nullptr)
		this->x = new float(x);
	else
	{
		delete this->x;
		this->x = new float(x);
	}
}

void Vector3D::sety(float y)
{
	if (this->getx == nullptr)
		this->y = new float(y);
	else
	{
		delete this->y;
		this->y = new float(y);
	}
}

void Vector3D::setz(float z)
{
	if (this->getz == nullptr)
		this->z = new float(z);
	else
	{
		delete this->z;
		this->z = new float(z);
	}
}