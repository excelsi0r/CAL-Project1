/*
 * Coordenate.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: nuno_
 */

#include "Headers.h"

Coordenate::Coordenate()
{
	this->x = 0;
	this->y = 0;

}

Coordenate::Coordenate(int x, int y)
{
	this->x = x;
	this->y = y;

}

Coordenate::~Coordenate() {
	// TODO Auto-generated destructor stub
}

int const Coordenate::getX()
{
	return x;
}

int const Coordenate::getY()
{
	return y;
}
