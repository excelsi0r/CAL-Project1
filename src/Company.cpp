/*
 * Company.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: nuno_
 */

#include "Headers.h"

Company::Company()
{
	this->pos = NULL;
}

Company::~Company(){}

void Company::setCoord(Coordenate * c)
{
	this->pos = c;
}

int const Company::getX()
{
	return this->pos->getX();
}

int const Company::getY()
{
	return this->pos->getY();
}

void Company::push_back(Bus* bus)
{
	this->buses.push_back(bus);
}

vector<Bus *> * const Company::getBuses()
{
	return &this->buses;
}
