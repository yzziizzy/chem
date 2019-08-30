







class SmilesAtom {
public:
	int number;
	int isotope;
	int attachedHydrogens;
	int charge;
	
	bool aromaticShorthand;
	
	SmilesAtom() {};
	SmilesAtom(&SmilesAtom a) { *this = a; };
	SmilesAtom(int _number) { *this = {}; number = _number; };
}



int parseSmiles(char* src);

