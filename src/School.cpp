/*
 * School.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: nuno_
 */

#include "Headers.h"

School::School()
{
	this->pos = NULL;
}

School::~School(){}

void School::setCoord(Coordenate * c)
{
	this->pos = c;
}

int const School::getX()
{
	return this->pos->getX();
}

int const School::getY()
{
	return this->pos->getY();
}

Coordenate * School::getSchool()
{
	return this->pos;
}

