#include <iostream>
#include <algorithm>


#include "moly.hpp"




Element g_Elements[114];




Molecule::Molecule() {
	
}

Molecule::~Molecule() {
	for(Atom* a : atoms) delete a;
	for(Bond* b : bonds) delete b;
}

bool Molecule::hasAtom(Atom* a) {
	return atoms.end() != find(atoms.begin(), atoms.end(), a);
}


Bond* Molecule::AddAtom(Atom* a, Atom* bondPoint, int order) {
	
	if(bondPoint == NULL) {
		// adding a lone atom, as the first one, or possibly as an ion
		if(!hasAtom(a)) {
			atoms.push_back(a);
			return NULL;
		}
	}
	else if(!hasAtom(bondPoint)) {
		cout << "no valid bond point";
		return NULL;
	}
	
	// only add the atom if it doesn't exist yet
	if(!hasAtom(a)) {
		atoms.push_back(a);
	}
	
	Bond* bond = new Bond();
	bond->order = order;
	bond->a = a;
	bond->b = bondPoint;
	
	bonds.push_back(bond);
	
	return bond;
}



Atom::Atom(int number) {
	element = &g_Elements[number];
	
	// TODO: copy default electron config once that is sorted out
}

