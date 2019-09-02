#pragma once

#include <vector>
#include <string>


using namespace std;



#define BOND_IONIC 0
#define BOND_SINGLE 1
#define BOND_DOUBLE 1


class ElectronShell {
public:
	char level;
	char type; // l-number, not the letter. s=0, p=1, d=2, f=3
	char occupancy;
}


class Element {
public:
	int number;
	string symbol;
	string name;
	
	
	
};


class Atom;

class Bond {
public:
	Atom* a, *b;
	int type;
	
	Element* getElement();
	
	// GIGO
	Atom* getOther(Atom* me) {
		return a == me ? b : a;
	}
};

class Group {
public:
	vector<Atom*> atoms;
	vector<Bond*> bonds;
};


class Atom {
public:
	int elem;
	vector<Bond*> bonds;
	
	int netCharge;
};



class Moly {
public:
	Atom* root;
	vector<Atom*> atoms;
	
	string name;
	
	void AddBond(Atom* target, Bond* bond);
};




void parse_chem_csv(string path);
