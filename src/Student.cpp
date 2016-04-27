/*
 * Student.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: nuno_
 */

#include "Headers.h"

Student::Student()
{
	this->home = NULL;
	this->school = NULL;
}

Student::~Student() {}

void Student::setCoord(Coordenate *c)
{
	this->home = c;
}

int const Student::getX()
{
	return this->home->getX();
}

int const Student::getY()
{
	return this->home->getY();
}

void Student::setSchool(School *s)
{
	this->school = s;
}
int const Student::getSchoolX()
{
	return this->school->getX();
}

int const Student::getSchoolY()
{
	return this->school->getY();
}
Coordenate * Student::getCoord()
{
	return this->home;
}

Coordenate * Student::getSchool()
{
	return this->school->getSchool();
}
