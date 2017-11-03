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

#include "Bin.h";





// Copy Constructor
Bin::Bin(const Bin* b)
{
	this->vectors = new Vector3D[b->getSize()];

	for (int i = 0; i < b->getSize(); i++)
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

	this->setCapacity(b->getCurrentCapacity());
}

// Normal Constructor
Bin::Bin(int b)
{
	if (b <= 0 || b >= MAX_SAFE_SIZE)
		b = DEFAULT_BIN_SIZE; // If user has passed an invalid number set it to the default instead
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

// Clean up bin properly by deleting all of it's stored vectors before destroying the vector array itself
Bin::~Bin()
{
	// Run through vectors and delete all of the dynamically allocated vectors
	for (int i = 0; i < this->getSize(); i++)
	{
		delete &this->vectors[i];
	}

	// Delete vector array itself
	delete[] this->vectors;
}

// Gets the x value of a vector within the bin index at position num
float const Bin::getx(int num) const
{
	// If user attempts to query a vector that doesn't exist return a 0
	if (num > this->getCurrentCapacity())
		return 0;

	Vector3D* vect = &this->vectors[num];
	return vect->getx();
}

// Gets the y value of a vector within the bin index at position num
float const Bin::gety(int num) const
{
	// If user attempts to query a vector that doesn't exist return a 0
	if (num > this->getCurrentCapacity())
		return 0;

	Vector3D* vect = &this->vectors[num];
	return vect->gety();
}

// Gets the z value of a vector within the bin index at position num
float const Bin::getz(int num) const
{
	// If user attempts to query a vector that doesn't exist return a 0
	if (num > this->getCurrentCapacity())
		return 0;

	Vector3D* vect = &this->vectors[num];
	return vect->getz();
}

int const Bin::getSize() const
{
	return this->size;
}

int const Bin::getCurrentCapacity() const
{
	return this->currentCapacity;
}

// Adds vector to the bin IFF there is enough room, else it increases the bin size and adds it then
Vector3D* Bin::add(float x, float y, float z)
{
	if (this->getCurrentCapacity() + 1 < (this->getSize() - 1))
	{
		Vector3D* vect = new Vector3D(x, y, z);
		this->vectors[this->getCurrentCapacity()] = vect;
		this->setCapacity(this->getCurrentCapacity() + 1); // Increase the capacity
		return vect;
	}
	else // If bin is full it must be resized
	{
		// A quick check to ensure that the bin does not grow too big
		if ((this->getSize() * 2) > MAX_SAFE_SIZE)
			throw "BIN HAS GOTTEN TO BIG, PLEASE STOP ADDING THINGS TO IT!";
		/*
			Create a new array of memory on the heap that is two times larger than the current bin size
			This is a bit of a naive approach that when scalled up could become quite problematic. Say
			for example the user has a bin size of 10 and they only wish to add one more vector they now
			have a bin of size 20.

			However, the reason why I have decided to do this and store more memory is because I am favouring
			performance over memory usage. Though this may waste some memory the performace won't be as 
			hampered by constatly creating new arrays of vectors and copying the contents over. If I were to
			increment the new bin size by a lower value to stands to reason that more copying might take place
			as the bin is being resized more often.
		*/
		Vector3D* newBin = new Vector3D[this->getSize() * 2];

		// Copy contents of old bin into the new ,larger, bin
		for (int i = 0; i < this->getCurrentCapacity(); i++)
		{
			newBin[i] = this->vectors[i];
		}

		// Delete the old bin
		delete[] this->vectors;

		// Keep the new bin
		this->vectors = newBin;

		// Add the new given vector into the bin
		this->setCapacity(this->getCurrentCapacity() + 1);
		Vector3D* vect = new Vector3D(x, y, z);
		this->vectors[this->getCurrentCapacity()] = vect;

		// Finally update the size member to reflect the new size of the bin
		this->setSize(this->getSize() * 2);

		return vect;
	}
}

// Removes an item from the bin and if the remove fails it returns a false
bool Bin::remove(int num)
{
	if ((num >= 0) && (num < this->getCurrentCapacity()))
	{
		Vector3D* vect = &this->vectors[num];
		delete vect;
		*vect = nullptr;
		this->setCapacity(this->getCurrentCapacity() - 1);
		return true;
	}
	else
	{
		return false;
	}

}

// Overload of the assignment operator, will clean up the current bin and copy the contents of the other bin
Bin Bin::operator=(const Bin* b)
{
	if (b == nullptr)
		throw "Not an actual bin!";

	// If the current bin has it's vector array created delete all of it's vectors and it's vector bin
	if (this->vectors)
	{
		// Clean the bin of it's stored vectors
		for (int i = 0; i < this->getCurrentCapacity(); i++)
		{
			delete &this->vectors;
		}
		// Delete the vector bin itself
		delete[] this->vectors;
	}

	this->vectors = new Vector3D[b->getSize()];

	for (int i = 0; i < b->getSize(); i++)
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

	this->setCapacity(b->getCurrentCapacity());
}

void Bin::setSize(int size)
{
	if (size < 0 || size > MAX_SAFE_SIZE)
		this->size = DEFAULT_BIN_SIZE;
	else
		this->size = size;
}

void Bin::setCapacity(int cap)
{
	this->currentCapacity = cap;
}