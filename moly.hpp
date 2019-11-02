#pragma once

#include <vector>
#include <string>


using namespace std;




class Element {
public:
	int number;
	string symbol;
	string name;
	
	float AtomicMass;
	float ElectroNegativity;
	float ElectronAffinity;
	float AtomicRadius;
	float IonEnergy1st;
	float IonEnergy2nd;
	float IonEnergy3rd;
	
};


extern Element g_Elements[114];



class ElectronConfig {
public:
	struct {
		char total;
		char s, p, d, f; // 2, 6, 10, 14
		char sp1, sp2, sp3;
		
		bool full;
		bool valence;
		bool empty;
		bool hybrid;
	} levels;
	
};

class Atom {
public:
	Element* element;
	
	ElectronConfig ec;
	
	// TODO: lists of bonds and neighbors
	
	Atom(int number);
};


class Bond {
public:
	Atom* a, *b;
	float covalency; // 0.0 -a, 0.5 fully covalent, 1.0 -b
	float order;
	
	float length; // in pm
	float energy; // in kJ/mol
};


class Molecule {
public:
	
	vector<Atom*> atoms;
	vector<Bond*> bonds;
	
	float netCharge;
	
	string name;
	string fomula;
	string SMILES;
	
	Molecule();
	~Molecule();
	
	bool hasAtom(Atom* a);
	Bond* AddAtom(Atom* a, Atom* bondPoint, int order);
	
	
};









