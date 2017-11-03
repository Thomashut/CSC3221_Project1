/*
Author: Thomas Hutchinson
Project: CSC3221 - Programming for Games - Project 1
File Name: Bin.h
Description:
The Bin acts as an object which stores a series of vectors.
It also allows the querying of specific vectors within it's storage.
Calls can be made to return the values of a vector, add a new vector
and remove a vector from the list. The max size of the bin is determined
at creation.
*/


#include "Vector3D.h";
#pragma once


class Bin {
public:
	static const int DEFAULT_BIN_SIZE = 10;
	static const int MAX_SAFE_SIZE = 1000; // Arbitary value for the max size of a bin

	// Start of Constructors
	Bin(const Bin* b); // Copy Constructor

	Bin(int b); // Normal Constructor

	Bin(); // Default Constructor

	~Bin(); // Deconstructor for Bin, required to free memory after usage


	// End of Constructors

	/* 
	   Start of Getters
	   Given a specific number go fetch the corrasponding coord from the vector at n index as determined
	   by the passed int. eg. getx(5) will get the x coord from the vector at index 5. If no vector is found
	   a NULL will be returned.
	*/
	float const getx(int num) const;
	float const gety(int num) const;
	float const getz(int num) const;

	// End of Getters

	/* Returns the bin size, used for testing. */
	int const getSize() const;

	/* Returns the amount of Vectors currently in the bin*/
	int const getCurrentCapacity() const;

	/* 
	   Given 3 float coords create a new Vector3D object and add it into the Bin. If no space
	   is available return NULL. Otherwise return the created vector to mark succsess
	*/
	Vector3D* add(float x, float y, float z);

	// Given an int index remove Vector at that index. If successful return true otherwise return false
	bool remove(int num);

	// Overload assignment opperator to ensure true copying and pointer handeling
	Bin operator=(const Bin* b);

private:
	Vector3D* vectors;
	int size;
	int currentCapacity;

	// Set the size of the bin, only allowed on construction of the bin
	void setSize(int size);

	// Used in constructors and assignments to completly override the current number of objects
	void setCapacity(int cap);

	// Passes a pointer to the bins vectors, only called internally
	Vector3D* getVectors();
};