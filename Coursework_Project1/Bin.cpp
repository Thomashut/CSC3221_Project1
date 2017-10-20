#include "Bin.h";

/*
	Author: Thomas Hutchinson
	Project: CSC3221 - Programming for Games - Project 1
	File Name: Bin.cpp
	Description:
		The Bin acts as an object which stores a series of vectors.
		It also allows the querying of specific vectors within it's storage.
		Calls can be made to return the values of a vector, add a new vector
		and remove a vector from the list. The max size of the bin is determined
		at creation.
*/

const int DEFAULT_BIN_SIZE = 10;

// Copy Constructor
Bin::Bin(const Bin* b)
{
	this->vectors = new Vector3D[b->getSize()];
	for (int i = 0; i < b->getSize(); i++)
	{
		Vector3D* vect = this->vectors[i];
		delete vect;
		this->vectors[i] = new Vector3D(b->getx(i), b->gety(i), b->getz(i));
	}
	this->currentCapacity = b->currentCapacity;
}

// Normal Constructor
Bin::Bin(int b)
{
	if (b <= 0)
		int placeholder = 0; // Thrown an exception when I figure out how to do it.
	this->vectors = new Vector3D[b];
	this->currentCapacity = 0;
}

// Default Constructor
Bin::Bin()
{
	this->vectors = new Vector3D[DEFAULT_BIN_SIZE];
	this->size = DEFAULT_BIN_SIZE;
	this->currentCapacity = 0; // No items in the bin on creation;
}

float Bin::getx(int num)
{
	return this->vectors[num]->getx();
}

float Bin::gety(int num)
{
	return this->vectors[num]->gety();
}

float Bin::getz(int num)
{
	return this->vectors[num]->getz();
}

int Bin::getSize()
{
	return this->size;
}

int Bin::getCurrentCapacity()
{
	return this->currentCapacity;
}

// Adds vector to the bin IFF there is enough room, else it returns a nullptr
Vector3D* Bin::add(float x, float y, float z)
{
	if (this->currentCapacity + 1 < this->getSize)
	{
		Vector3D* vect = new Vector3D(x, y, z);
		this->vectors[this->getCurrentCapacity] = vect;
		return vect;
	}
	else
	{
		return nullptr;
	}
}

bool Bin::remove(int num)
{
	if ((num > 0) && (num < this->getSize()))
	{
		Vector3D* vect = &this->vectors[num];
		delete vect;
		*vect = nullptr;
		return true;
	}
	else
	{
		return false;
	}

}

// TO-DO
Bin Bin::operator=(Bin b)
{
	return this;
}

