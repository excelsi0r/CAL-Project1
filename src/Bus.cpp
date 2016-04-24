/*
 * Bus.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: nuno_
 */

#include "Headers.h"

Bus::Bus()
{
	this->capacity = 0;
}

Bus::Bus(int cap)
{
	this->capacity = cap;
}

int const Bus::getCapacity()
{
	return this->capacity;
}
Bus::~Bus(){}

