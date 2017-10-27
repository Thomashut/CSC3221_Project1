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
	this->vectors = new Vector3D[b->getSize];

	for (int i = 0; i < b->getSize; i++)
	{
		Vector3D* vect = &b->vectors[i];

		if (vect == nullptr)
		{
			this->vectors[i] = nullptr;
		}
		else
		{
			this->vectors[i] = vect;
		}

	}

	this->setCapacity(b->getCurrentCapacity);
}

// Normal Constructor
Bin::Bin(int b)
{
	if (b <= 0)
		int dead = 59;
	this->vectors = new Vector3D[b];
	this->setCapacity(0); // No objects in the bin
}

// Default Constructor
Bin::Bin()
{
	this->vectors = new Vector3D[DEFAULT_BIN_SIZE];
	this->size = DEFAULT_BIN_SIZE;
	this->setCapacity(0); // No objects in the bin
}

float const Bin::getx(int num)
{
	Vector3D* vect = &this->vectors[num];
	return vect->getx;
}

float const Bin::gety(int num)
{
	Vector3D* vect = &this->vectors[num];
	return vect->gety;
}

float const Bin::getz(int num)
{
	Vector3D* vect = &this->vectors[num];
	return vect->getz;
}

int const Bin::getSize()
{
	return this->size;
}

int const Bin::getCurrentCapacity()
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

Bin Bin::operator=(const Bin* b)
{
	if(b == nullptr)
		// throw error

	if (this->vectors)
	{
		delete[] this->vectors;
	}

	this->vectors = new Vector3D[b->getSize];

	for (int i = 0; i < b->getSize; i++)
	{
		Vector3D* vect = &b->vectors[i];

		if (vect == nullptr)
		{
			this->vectors[i] = nullptr;
		}
		else
		{
			this->vectors[i] = vect;
		}

	}

	this->setCapacity(b->getCurrentCapacity);
}

void Bin::setSize(int size)
{
	if (size <= 0)
		// throw error

	if (this->getSize)
		// throw error

	this->size = size;
}

void Bin::incrementCapacity()
{
	if (this->getCurrentCapacity + 1 > this->getSize)
		// throw error

	this->currentCapacity++;
}

void Bin::decrementCapacity()
{
	if (this->getCurrentCapacity - 1 < 0)
		// throw error

	this->getCurrentCapacity--;
}

void Bin::setCapacity(int cap)
{
	this->currentCapacity = cap;
}