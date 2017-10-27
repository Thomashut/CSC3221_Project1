#pragma once

/*
	Author: Thomas Hutchinson
	Project: CSC3221 - Programming for Games - Project 1
	File Name: Vector3D.h
	Description:
		Header file for the Vector3D class. The vector3D class provides the features
		of a vector workiing within 3D space. The class itself will allow the user
		to perform various equations upon the vector against other vectors as well 
		as get and change the information of the vector itself.
*/

class Vector3D {
public:

	Vector3D(const Vector3D* vector); // Copy Constructor
	Vector3D(float x, float y, float z); // Normal Constructor
	Vector3D(); // Default Constructor


	/* Start of Getters */
	float gety();
	float getx();
	float getz();
	/* End of Getters*/

	/* Calculates the magnitude of the current vector and returns it */
	float computeMagnitude();

	/* Start of Operator Overloads*/
	Vector3D operator+(Vector3D* rhs);

	Vector3D operator-(Vector3D* rhs);

	/* Multiplies the current Vector by a given scalar */
	Vector3D operator*(float scalar);


	/* Divides the current Vector by a given scalar*/
	Vector3D operator/(float scalar);

	/* Calculates the Vector product of two Vectors*/
	Vector3D operator%(Vector3D* rhs);

	/* Overload for assignment operator ensures correct copying */
	Vector3D& operator=(Vector3D* rhs);

	bool operator==(Vector3D* rhs);

	/* End of Operator Overloads*/

	/* Produces a unit vector (of mag 1) pointing in the same direction of a given vector */
	Vector3D unitVector(Vector3D* rhs);

	/* Returns a vector orthogonal to two given vectors (vector product) */
	Vector3D unitVectorOrthogonal(Vector3D* v1, Vector3D* v2);



private:
	float* x;
	float* y;
	float* z;

	void setx(float x);
	void sety(float y);
	void setz(float z);
};