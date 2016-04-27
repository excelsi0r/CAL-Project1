/*
 * System.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: nuno_
 */

#include "Headers.h"

System::System()
{
	this->company = NULL;
	this->gv = NULL;
	this->g = NULL;
}

void System::initialize(const char * coords,const char * edges, const char * company, const char * schools, const char * students, const char * busfile)
{
	this->createGraph();

	this->retrieveNodes(coords);
	this->printCoords();

	this->retrieveEdges(edges);

	this->retrieveCompany(company);
	this->printCompany();

	this->retrieveBus(busfile);
	this->printBus();

	this->retrieveSchools(schools);
	this->printSchools();

	this->retrieveStudents(students);
	this->printStudents();

	this->calculate();

}

System::~System(){}

void System::retrieveCoords(const char * file)
{
	ifstream inFile;

	inFile.open(file);

	if (!inFile)
	{
		cerr << "Unable to open file " << file;
		exit(1);   // call system to stop
	}

	string  line;

	int idNo=0;
	int X=0;
	int Y=0;

	while(getline(inFile, line))
	{
		stringstream linestream(line);
		string  data;

		linestream >> idNo;

		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> X;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> Y;

		Coordenate* c = new Coordenate(idNo,X,Y);
		this->coords.push_back(c);

	}

	inFile.close();

}

void const System::printCoords()
{

	cout << endl << "Coordenates List: " << endl;
	typename vector<Coordenate *>::const_iterator it = this->coords.begin();

	while(it != this->coords.end())
	{
		cout << setprecision(12)<< (*it)->getID() << " " << (*it)->getX() << ", " << (*it)->getY() << endl;
		it++;
	}

}


void System::retrieveBus(const char * file)
{
	ifstream inFile;
	inFile.open(file);

	if (!inFile)
	{
		cerr << "Unable to open file " << file;
		exit(1);   // call system to stop
	}

	string  line;
	int cap=0;

	while(getline(inFile, line))
	{
		stringstream linestream(line);
		linestream >> cap;

		Bus * b = new Bus(cap);
		this->company->push_back(b);
	}

	inFile.close();
}

void const System::printBus()
{

	cout << endl << "Buses Capacity List: " << endl;
	typename vector<Bus *>::const_iterator it = this->company->getBuses()->begin();

	while(it != this->company->getBuses()->end())
	{
		cout << (*it)->getCapacity() << endl;
		it++;
	}
}


void System::retrieveCompany(const char * file)
{
	ifstream inFile;

	inFile.open(file);

	if (!inFile)
	{
		cerr << "Unable to open file " << file;
		exit(1);   // call system to stop
	}

	string  line;

	int idNo=0;
	int X=0;
	int Y=0;

	getline(inFile, line);

	if(line == "")
	{
		cerr << "No company coordenates on file\n";
		exit(1);
	}

	stringstream linestream(line);
	string  data;

	linestream >> idNo;

	getline(linestream, data, ';');  // read up-to the first ; (discard ;).
	linestream >> X;
	getline(linestream, data, ';');  // read up-to the first ; (discard ;).
	linestream >> Y;

	Coordenate *c = existsCoord(X,Y);

	if(c == NULL)
	{
		cerr << "Invalid Coordenates for Company. Inexistence in Coordenates List\n";
		exit(1);
	}

	Company* s = new Company();

	s->setCoord(c);
	this->company = s;

	inFile.close();
}

void const System::printCompany()
{
	cout << endl << "Company Coordenates: " << endl;
	cout << this->company->getX() <<  ", " << this->company->getY() << endl;
}


void System::retrieveSchools(const char * file)
{
	ifstream inFile;

	inFile.open(file);

	if (!inFile)
	{
		cerr << "Unable to open file " << file;
		exit(1);   // call system to stop
	}

	string  line;

	int idNo=0;
	int X=0;
	int Y=0;

	while(getline(inFile, line))
	{
		stringstream linestream(line);
		string  data;

		linestream >> idNo;

		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> X;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> Y;

		Coordenate* c = existsCoord(X,Y);

		if(c == NULL)
		{
			cerr << "Invalid Coordenates for Company. Inexistence in Coordenates List\n";
			exit(1);
		}

		School* s = new School();
		s->setCoord(c);

		this->schools.push_back(s);


	}

	inFile.close();

}

void const System::printSchools()
{

	cout << endl << "School Coordenates: " << endl;

	typename vector<School *>::const_iterator it = this->schools.begin();

	while(it != this->schools.end())
	{
		cout << (*it)->getX() << ", " << (*it)->getY() << endl;
		it++;
	}

}

void System::retrieveStudents(const char * file)
{
	ifstream inFile;

	inFile.open(file);

	if (!inFile)
	{
		cerr << "Unable to open file " << file;
		exit(1);   // call system to stop
	}

	string  line;

	int idNo=0;
	int X=0;
	int Y=0;

	while(getline(inFile, line))
	{
		stringstream linestream(line);
		string  data;

		linestream >> idNo;

		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> X;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> Y;

		Coordenate* c = existsCoord(X,Y);

		if(c == NULL)
		{
			cerr << "Invalid Coordenates for Students Home. Inexistence in Coordenates List\n";
			exit(1);
		}

		getline(inFile, line);

		if(line == "")
		{
			cerr << "No Coordenates for School\n";
			exit(1);
		}

		stringstream newlinestream(line);

		newlinestream >> idNo;

		getline(newlinestream, data, ';');  // read up-to the first ; (discard ;).
		newlinestream >> X;
		getline(newlinestream, data, ';');  // read up-to the first ; (discard ;).
		newlinestream >> Y;

		School * s = existsSchool(X,Y);

		if(s == NULL)
		{
			cerr << "Invalid Coordenates for School. Inexistence in Schools List\n";
			exit(1);
		}

		Student * st = new Student();

		st->setCoord(c);
		st->setSchool(s);

		this->students.push_back(st);

	}

	inFile.close();

}

void const System::printStudents()
{

	cout << endl << "Students Info: " << endl;

	typename vector<Student *>::const_iterator it = this->students.begin();

	while(it != this->students.end())
	{
		cout << "Home: " << (*it)->getX() << ", " << (*it)->getY() << " School: " << (*it)->getSchoolX() << ", " << (*it)->getSchoolY() << endl;
		it++;
	}

	cout << endl;

}


Coordenate * const System::existsCoord(int x, int y)
{
	Coordenate * c = NULL;

	typename vector<Coordenate *>::const_iterator it = this->coords.begin();


	while(it != this->coords.end())
	{
		if((*it)->getX() == x && (*it)->getY() == y)
		{
			c = (*it);
			return c;
		}

		it++;
	}


	return c;
}


School * const System::existsSchool(int x, int y)
{
	School * s = NULL;

	typename vector<School *>::const_iterator it = this->schools.begin();

	while(it != this->schools.end())
	{
		if((*it)->getX() == x && (*it)->getY() == y)
		{
			s = (*it);
			return s;
		}

		it++;
	}


	return s;

}

void System::createGraphViewer()
{
	this->gv = new GraphViewer(1500, 100, false);
	gv->setBackground("background.png");
	gv->createWindow(1500, 1500);
	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");

}

void System::createGraph()
{
	this->g = new Graph<int>;
}

void System::retrieveNodes(const char * file)
{
	fstream inFile;

	inFile.open(file);

	if (!inFile)
	{
		cerr << "Unable to open file " << file;
		exit(1);   // call system to stop
	}

	string  line;

	int idNo=0;
	double lon=0;
	double lat=0;

	while(getline(inFile, line))
	{
		stringstream linestream(line);
		string  data;

		if(line == "")
		{
			cerr << "No Coordenate\n";
			exit(1);
		}

		linestream >> idNo;

		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> lon;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> lat;

		Coordenate* c = new Coordenate(idNo,lon,lat);
		this->coords.push_back(c);

		this->g->addVertex(idNo);
	}

	inFile.close();
}

void System::retrieveNodesViewer(const char * file)
{
	fstream inFile;

	inFile.open(file);

	if (!inFile)
	{
		cerr << "Unable to open file " << file;
		exit(1);   // call system to stop
	}

	string  line;

	int idNo=0;
	double lon=0;
	double lat=0;

	while(getline(inFile, line))
	{
		stringstream linestream(line);
		string  data;

		if(line == "")
		{
			cerr << "No Coordenate\n";
			exit(1);
		}

		linestream >> idNo;

		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> lon;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> lat;

		this->gv->addNode(idNo,lon,lat);

	}

	inFile.close();
}

GraphViewer *  System::getGV()
{
	return this->gv;
}

void System::retrieveEdges(const char * file)
{
	fstream inFile;

	inFile.open(file);

	if (!inFile)
	{
		cerr << "Unable to open file " << file;
		exit(1);   // call system to stop
	}

	string  line;

	int idedge=0;
	int idsource=0;
	int iddest=0;
	double w=0;


	while(getline(inFile, line))
	{
		stringstream linestream(line);
		string  data;

		if(line == "")
		{
			cerr << "No Edges\n";
			exit(1);
		}

		linestream >> idedge;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> idsource;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> iddest;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> w;


		this->g->addEdge(idsource,iddest,w);

	}

	inFile.close();
}

void System::retrieveEdgesViewer(const char * file)
{
	fstream inFile;

	inFile.open(file);

	if (!inFile)
	{
		cerr << "Unable to open file " << file;
		exit(1);   // call system to stop
	}

	string  line;

	int idedge=0;
	int idsource=0;
	int iddest=0;
	double w=0;


	while(getline(inFile, line))
	{
		stringstream linestream(line);
		string  data;

		if(line == "")
		{
			cerr << "No Edges\n";
			exit(1);
		}

		linestream >> idedge;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> idsource;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> iddest;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> w;

		this->gv->addEdge(idedge,idsource,iddest,EdgeType::UNDIRECTED);

	}

	inFile.close();
}

vector<Student *> System::getStudentsOfSchool(School * s)
{
	vector<Student *> vt;

	typename vector<Student *>::const_iterator it = this->students.begin();

	while(it != this->students.end())
	{
		if((*it)->getSchoolX() == s->getX() && (*it)->getSchoolY() == s->getY())
			vt.push_back((*it));
		it++;
	}

	return vt;
}


int System::getSeats(vector<Bus *> * vb)
{
	typename vector<Bus *>::const_iterator it = vb->begin();

	int seats = 0;

	while(it != vb->end())
	{
		seats += (*it)->getCapacity();
		it++;
	}

	return seats;
}


void System::calculate()
{

	cout << "\nGetting Paths \n";
	typename vector<School *>::const_iterator it = this->schools.begin();

	vector<Bus *> vb = this->company->getBusesVector();
	if(vb.size() == 0)
	{
		cout << "No Buses for transport\n";
		return;
	}


	while(it != this->schools.end())
	{
		if(vb.size() == 0)
		{
			cout << "\nNo Buses left at the Station\n";
			cout << "Must Wait till they are Back\n\n";
			vb = this->company->getBusesVector();
		}

		vector<Student *> vt = this->getStudentsOfSchool((*it));

		this->toSchool(vt,&vb);

		it++;
	}

}


void System::toSchool(vector<Student *> vs, vector<Bus*>* vb)
{
	int students = vs.size();

	typename vector<Bus *>::const_iterator itb = vb->begin();
	typename vector<Student *>::const_iterator its = vs.begin();
	Coordenate * school = (*its)->getSchool();


	while(students > 0)
	{

		vector<Coordenate *> coords;
		coords.push_back(this->company->getCoord());

		if(itb == vb->end())
			itb = vb->begin();

		for(size_t i = (*itb)->getCapacity(); i >0 ; i--)
		{
			if(its == vs.end())
				break;
			coords.push_back((*its)->getCoord());
			students--;
			its++;
		}
		itb++;

		coords.push_back(school);

		this->path(coords);


	}

}

void System::path(vector<Coordenate *> path)
{
	stringstream out;

	for(size_t i = 1; i < path.size(); i++)
	{

		int idorigem = i - 1;
		int idchegada = i;

		this->g->dijkstraShortestPath(path[idorigem]->getID());
		vector<int> vec = this->g->getPath(path[idorigem]->getID(),path[idchegada]->getID());

		for(size_t j = 0; j < vec.size() -1; j++)
		{
			out << vec[j] << "->" ;
		}

	}
	out << path[path.size()-1]->getID();
	out << "\n";
	cout << out.str();
}
