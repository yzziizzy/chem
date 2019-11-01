#pragma once

#include <vector>
#include <string>


using namespace std;




class ElectronShell {
public:
	char level;
	char type; // l-number, not the letter. s=0, p=1, d=2, f=3
	char occupancy;
};


class Element {
public:
	int number;
	string symbol;
	string name;
	
	
	
};



void parse_chem_csv(string path);
