#include "Vector3D.h";

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
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::Vector3D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

float Vector3D::getx()
{
	return this->x;
}

float Vector3D::gety()
{
	return this->y;
}

float Vector3D::getz()
{
	return this->z;
}

// TO-DO: actually create;
float Vector3D::computeMagnitude()
{
	return 0.0;
}

Vector3D Vector3D::operator+(Vector3D* rhs)
{
	this->x += rhs->x;
	this->y += rhs->y;
	this->z += rhs->z;

	return this;
}

Vector3D Vector3D::operator-(Vector3D* rhs)
{
	this->x -= rhs->x;
	this->y -= rhs->y;
	this->z -= rhs->z;

	return this;
}

// TO-DO Create;
Vector3D Vector3D::operator*(float scalar)
{
	return this;
}

// TO-DO Create;
Vector3D Vector3D::operator/(float scalar)
{
	return this;
}

// TO-DO
Vector3D Vector3D::operator%(Vector3D* rhs)
{
	return this;
}

// TO-DO
Vector3D Vector3D::operator=(Vector3D* rhs)
{
	return this;
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