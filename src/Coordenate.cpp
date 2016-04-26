/*
 * Coordenate.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: nuno_
 */

#include "Headers.h"

Coordenate::Coordenate()
{
	this->lon = 0;
	this->lat = 0;
	this->idNo = 0;

}

Coordenate::Coordenate(int idNo, double lon, double lat)
{
	this->lon = lon;
	this->lat = lat;
	this->idNo = idNo;

}

Coordenate::~Coordenate() {
	// TODO Auto-generated destructor stub
}

double const Coordenate::getX()
{
	return lon;
}

double const Coordenate::getY()
{
	return lat;
}
double const Coordenate::getID()
{
	return this->idNo;
}
