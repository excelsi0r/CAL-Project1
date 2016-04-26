#include "Headers.h"
#include "Graph.h"

#define COORDFILE 		"nodes.txt"
#define COMPANYFILE 	"company.txt"
#define SCHOOLSFILE 	"schools.txt"
#define	STUDENTSFILE	"students.txt"
#define BUSFILE			"bus.txt"
#define EDGEFILE		"edges.txt"

using namespace std;

int main()
{
	System * system = new System();

	system->initialize(COORDFILE,EDGEFILE, COMPANYFILE, SCHOOLSFILE, STUDENTSFILE, BUSFILE);

	system->calculate();

	Sleep(10000);
}


