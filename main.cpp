#include <string>


#include "csv.hpp"
#include "moly.hpp"

using namespace std;



Element g_Elements[114];



int main(int argc, char* argv[]) {
	
	
	CSVParser csv;
	
	csv.Load("elements.csv");

	
	for(vector<string>* line : csv.lines) {
		
		Element* e;
		
		int num = strtol((*line)[0].c_str(), NULL, 10);
		e = &g_Elements[num];
		
		e->number = num;
		e->symbol = (*line)[1];
		e->name = (*line)[2];
		
		e->AtomicMass = strtof((*line)[3].c_str(), NULL);
		e->ElectroNegativity = strtof((*line)[6].c_str(), NULL);
		e->AtomicRadius = strtof((*line)[7].c_str(), NULL);
		e->IonEnergy1st = strtof((*line)[8].c_str(), NULL);
		e->ElectronAffinity = strtof((*line)[9].c_str(), NULL);
		
	}
	
	
	return 0;
}
