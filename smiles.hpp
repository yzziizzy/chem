





// used to cache data while parsing a smiles string
class SmilesMeta {
public:
	Atom* atom;
	
	int number;
	int isotope;
	int attachedHydrogens;
	int charge;
	
	bool aromaticShorthand;
	
};



int parseSmiles(char* src);

