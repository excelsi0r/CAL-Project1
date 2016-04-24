/*
 * Headers File, Definition of Coordenate, Student, Company, School, Bus and System Classes
 * Author Nuno Neto
 */

#ifndef SRC_HEADERS_H_
#define SRC_HEADERS_H_

#include "Graph.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <stdlib.h>

/**
 * Coordenate Class por better positioning
 * @param x position
 * @param y position
 * @author Nuno Neto
 */

class Coordenate
{
private:
	/**
	 * integer x coordenate
	 */
	int x;
	/**
	 * integer y coordenate
	 */
	int y;
public:
	/**
	 * Default constructor for Coordenate Class, sets x and y to 0
	 */
	Coordenate();
	/**
	 * Redefinition of Coordenate Constructor, sets new values for x and y
	 * @param x
	 * @param y
	 */
	Coordenate(int x, int y);
	/**
	 * Virual Destructor for Coordenate Class
	 */
	virtual ~Coordenate();
	/**
	 * Get X method. Returns X value
	 * @return x
	 */
	int const getX();
	/**
	 * Get Y method. Returns Y value
	 * @return y
	 */
	int const getY();
};

/**
 * Bus Class. Defined through a capacity of people able to transport
 * @author Nuno Neto
 */
class Bus
{
private:
	/**
	 * Inetger. Seat number capacity of the Bus
	 */
	int capacity;
public:
	/**
	 * Default Bus Class constructor. Sets Capacity to 0
	 */
	Bus();
	/**
	 * Redefinition of Bus Class constructor sets new capaciry
	 * @param capacity
	 */
	Bus(int cap);
	/**
	 * Virtual Destructor of Bus Class
	 */
	virtual ~Bus();
	/**
	 * Get capacity method.
	 * @return Capacity
	 */
	int const getCapacity();
};

/**
 * School Class defined with a Coordenate Object
 * @author Nuno Neto
 */
class School
{
private:
	/**
	 * Coordenate object to define the School Location
	 */
	Coordenate* pos;
public:
	/**
	 * Default Constructor for School. Sets NULL to the position
	 */
	School();
	/**
	 * Virtual destroyer for School Object
	 */
	virtual ~School();
	/**
	 * Function to set Coordenate, Coordenate exists only sets the pointer to the new Coordente.
	 * There are no new Coordenates being created
	 * @param Coordenate *
	 */
	void setCoord(Coordenate *c);
	/**
	 * Get X Coordenate Value of School
	 * @return X
	 */
	int const getX();
	/**
	 * Get Y Coordenate Value of School
	 * @return Y
	 */
	int const getY();
};

/**
 * Student Class definition defined with a Coordenate of Home location and with a School Object
 * @author Nuno Neto
 */

class Student
{
private:
	/**
	 * Coordenate Pointer to home. Points to existing coordenates to avoid duplicated objects.
	 */
	Coordenate* home;
	/**
	 * School Pointer to School. Pointing to existing School to avoid duplicated objects.
	 */
	School* school;
public:
	/**
	 * Student default constructor. home and school are set to NULL
	 */
	Student();
	/**
	 * Virtual destructor for Student.
	 */
	virtual ~Student();
	/**
	 * Points home to new Coordenate Object
	 * @param Coordenate *
	 */
	void setCoord(Coordenate *c);
	/**
	 * Get X value from Coordenate.
	 * @return X
	 */
	int const getX();
	/**
	 * Get Y value from Coordenate.
	 * @return Y
	 */
	int const getY();
	/**
	 * Points School to new School Object
	 * @param School *
	 */
	void setSchool(School *s);
	/**
	 * Get X value from School.
	 * @return X of School
	 */
	int const getSchoolX();
	/**
	 * Get Y value from School.
	 * @return Y of School
	 */
	int const getSchoolY();
};

/**
 * Company Class defined through a Coordenate position a vector of Bus pointers that belong to the Company
 * @author Nuno Neto
 */
class Company
{
private:
	/**
	 * Coordenate position of the company. Points to an existing object in order to avoid duplicated objects.
	 */
	Coordenate* pos;
	/**
	 * Vector of Bus pointers. Points to all the Buses own from the company
	 */
	vector<Bus *> buses;
public:
	/**
	 * Default Company constructor. Sets Coordenate NULL
	 */
	Company();
	/**
	 * Virtual Destructor for Company Class
	 */
	virtual ~Company();
	/**
	 * Sets the a new coordenate. Pointing to a new existing Coordenate.
	 * @param Coordenate*
	 */
	void setCoord(Coordenate *c);
	/**
	 * Push Back method to push a Bus* to the vector of buses. Registers new Bus to the Company
	 */
	void push_back(Bus* bus);
	/**
	 * Get X coordenate method. Returns the X value of the Coordenate position of the Company
	 * @return X
	 */
	int const getX();
	/**
	 * Get Y coordenate method. Returns the Y value of the Coordenate position of the Company
	 * @return X
	 */
	int const getY();
	/**
	 * Returns a pointer to the position where the vector of Bus pointer is located.
	 * @return vector<Bus *>*
	 */
	vector<Bus *>* const getBuses();

};

/**
 * System class. This class is where all Coordenates, Students, Schools and Compay are stored.
 * This Class also manages all these objects and stores all the information
 * @author Nuno Neto
 */
class System
{
private:
	/**
	 * Company element pointer. Points to Company already created
	 */
	Company* company;
	/**
	 * Vector of Coordenate pointers. This vector contains all the Coordenates of the System.
	 */
	vector<Coordenate* > coords;
	/**
	 * Vector of Student pointers. This vector contains all the Students of the System.
	 */
	vector<Student *> students;
	/**
	 * Vector of School pointers. This vector contains all the Schools of the System.
	 */
	vector<School *> schools;
public:
	/**
	 * System class Default constructor. Sets Company NULL.
	 */
	System();
	/**
	 * System virtual destructor.
	 */
	virtual ~System();
	/**
	 * Function intialize to initialize System object. It will retrieve all the objects from System Files.
	 * @param coords file
	 * @param company file
	 * @param schools file
	 * @param students file
	 * @param buses file
	 */
	void initialize(const char * coords, const char * company, const char * schools, const char * students, const char * busfile);
	/**
	 * Retrieve all coordenats from the coords file. Allocates new Coordenates and stores the pointers in the vector coords.
	 * This is also the Nodes file, must be 'idNo;X;Y'
	 * @param coordenates file
	 */
	void retrieveCoords(const char * file);
	/**
	 * Prints a list all coordenates int the vector coords.
	 */
	void const printCoords();
	/**
	 * Retrieve all buses from the buses file. Allocates new Buses and stores the pointers in the vector buses of the Company.
	 * Must have each bus capacity per line.
	 * @param buses file
	 */
	void retrieveBus(const char * file);
	/**
	 * Prints a list of all buses in the Buses Vector of the Company.
	 */
	void const printBus();
	/**
	 * Retrieve the Company from the company file. Allocates new Company and stores the pointer in the System Company*.
	 * File must have one line like 'idNo;X;Y'
	 * @param company file
	 */
	void retrieveCompany(const char * file);
	/**
	 * Prints a list of the Company postion.
	 */
	void const printCompany();
	/**
	 * Retrieve the Schools from the schools file. Allocates new Schools and stores the pointers in the vector of shcools.
	 * File must have a Coordenate of School per line like 'idNo;X;Y'
	 * @param school file
	 */
	void retrieveSchools(const char * file);
	/**
	 * Prints a list of all Schools int shcools vector
	 */
	void const printSchools();
	/**
	 * Retrieves Students form the students files. This file must have even number of lines.
	 * Two lines define the Student. First line defines Home and second the School.
	 * Both location are defined through nodes 'idNo;X;Y'.
	 * @param students file
	 */
	void retrieveStudents(const char * file);
	/**
	 * Prints a list of all Students information on the students vector.
	 */
	void const printStudents();
	/**
	 * This function searchs for a existing coordenate with x and y values in the coords vector.
	 * If exists returns the pointer to where the coordenate is allocated. If does not exist returns NULL
	 * This function is used in all retrieve functions of the System in order to not create new nodes
	 * @return Coordenate* or NULL
	 */
	Coordenate * const existsCoord(int x, int y);
	/**
	 * This function searchs for a existing School with x and y values in the schools vector.
	 * If exists returns the pointer to where the school is allocated. If does not exist returns NULL
	 * This function is used in all retrieve functions of the System in order to not create new nodes
	 * @return School* or NULL
	 */
	School * const existsSchool(int x, int y);
};
#endif /* SRC_HEADERS_H_ */
