#include <iostream>;
using namespace std;

#include "Bin.h";
#pragma once
#include "Vector3D.h";

/*
	Author: Thomas Hutchinson
	Project: CSC3221 - Programming for Games - Project 1
	File Name: Test.cpp
	Description:
		This is a basic file that will create some vectors and test their functions.
		It will also create some bins and test it's functions as well to prove that they work.
		You may also add to this section to test out various functionality of the two classes
	*/


int main() {
	Vector3D* vect1 = new Vector3D(10,15,18);
	Vector3D* vect2 = new Vector3D(10, 5, 2);

	float x, y, z;

	/* -- Vector Testing -- */

	// Basic Construction
	x = vect1->getx();
	y = vect1->gety();
	z = vect1->getz();
	cout << "Vect1 x: " << x << " Vect1 y: " << y << " Vect1 z: " << z << endl;

	Vector3D result = new Vector3D();
	// Addition
	
	result = vect1 + vect2;

	cout << "Vect1 + Vect2 = xyz(" << vect1->getx() << ", " << vect1->gety() << ", " << vect1->getz() << ")" << endl;

	// Subtraction

	result = vect1 - vect2;

	cout << "Vect1 - Vect2 = xyz(" << vect1->getx() << ", " << vect1->gety() << ", " << vect1->getz() << ")" << endl;

	// Dot Operator

	result = vect1 * vect2;

	cout << "Vect1 * Vect2 = xyz(" << vect1->getx() << ", " << vect1->gety() << ", " << vect1->getz() << ")" << endl;

	// Division

	result = vect1 / vect2;

	cout << "Vect1 / Vect2 = xyz(" << vect1->getx() << ", " << vect1->gety() << ", " << vect1->getz() << ")" << endl;

	// Cross Product

	result = vect1 % vect2;

	cout << "Vect1 X Vect2 = xyz(" << vect1->getx() << ", " << vect1->gety() << ", " << vect1->getz() << ")" << endl;

	// Magnitude Testing

	int res = vect1->computeMagnitude();

	cout << "The magnitude of vect1 is: " << res;

	// Unit Vector

	result = vect1->unitVector();

	cout << "The unit vector of vect1 is: " << result.getx() << ", " << result.gety() << ", " << result.getz() << endl;

	// Orthongonal Testing

	result = vect1->unitVectorOrthogonal(vect2);

	cout << "The unit vector orthogonal of vect1 and vect2 is: "
		<< result.getx() << ", " << result.gety() << ", " << result.getz() << endl;

	// Copy Constructor Test

	Vector3D vect3 = new Vector3D(vect1);

	cout << "Vect 1:" << vect1->getx() << vect1->gety() << vect1->getz()
		<< " New Vector: " << vect3.getx() << vect3.gety() << vect3.getz() << endl;

	delete vect1;
	delete vect2;
	delete &result;

	/* -- End of Vector Testing --*/

	/* -- Start of Bin Testing --*/

	Bin b1 = new Bin();
	Bin b2 = new Bin(10);

	// Getter Methods Testing (size and capacity)

	cout << "Bin1 Starting capactity : " << b1.getCurrentCapacity() << endl;
	cout << "Bin1 Starting Size (Should be default size) : " << b1.getSize() << endl;

	// Add Method Testing

	b1.add(5, 3, 1);

	cout << "New Vector x: " << b1.getx(0) << " y : " << b1.gety(0) << " z : " << b1.getz << endl;

	// Bin Resizing Testing

	for (int i = 0; i <= 30; i++)
	{
		b1.add(5, 4, 3);
	}

	cout << "New Bin Size after resizing: " << b1.getSize() << " New Bin Capacity: " << b1.getCurrentCapacity();

	// Bin Remove Testing

	b1.remove(5); // Test of removing an element from in the middle of the array.

	cout << "New Bin Capacity after remove: " << b1.getCurrentCapacity();

	b1.add(50, 30, 50);
	b1.remove(b1.getCurrentCapacity);

	cout << "Vector has been removed: " << b1.getx(b1.getCurrentCapacity + 1);

	// Copy Constructor Test

	// Assignment Operator Test

	_sleep(5000000000);
}