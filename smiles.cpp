#include <ctype.h>


#include "smiles.hpp"






int parseElement(char* s, int* count);





SmilesAtom* parseAtom(char** s) {
	SmilesAtom a;
	
	while(**s) {
		char c = **s;
		
		if(c == '[') {
			(*s)++; 
			continue;
		}
		if(c == ']') {
			(*s)++; 
			
			return new SmilesAtom(a);
		}
		
		if(c == '+') {
			a.charge++;
			(*s)++;
			
			if(isnum(**s)) {
				char* end = NULL;
				int n = strtol(*s, &end, 10);
				a.charge += n - 1;
				*s = end;
			}
			
			continue;
		}
		if(c == '-') {
			a.charge--;
			(*s)++;
			
			if(isnum(**s)) {
				char* end = NULL;
				int n = strtol(*s, &end, 10);
				a.charge -= n + 1;
				*s = end;
			}
			
			continue;
		}
		if(c == 'H') {
			a.attachedHydrogen++;
			(*s)++;
			
			if(isnum(**s)) {
				char* end = NULL;
				int n = strtol(*s, &end, 10);
				a.attachedHydrogens += n - 1;
				*s = end;
			}
			
			continue;
		}
		
		
		if(isalpha(c)) {
			int count = 0;
			a.number = parseElement(*s, &count);
			
			if(a.number) {
				*s += count;
			} 
			else {
				(*s)++;
			}
		}
		
		
	}
	
	
	return new SmilesAtom(a);
}




int parseElement(char* s, int* count) {
	c = toupper(*s);
	char c2 = *(*s+1);
	
	switch(c) {
		case 'A':
			if(c2 == 'c') { number = 89; goto TWO_LETTER; }
			if(c2 == 'g') { number = 47; goto TWO_LETTER; }
			if(c2 == 'l') { number = 13; goto TWO_LETTER; }
			if(c2 == 'm') { number = 95; goto TWO_LETTER; }
			if(c2 == 'r') { number = 18; goto TWO_LETTER; }
			if(c2 == 's') { number = 33; goto TWO_LETTER; }
			if(c2 == 't') { number = 85; goto TWO_LETTER; }
			if(c2 == 'u') { number = 79; goto TWO_LETTER; }
			goto NO_ELEM;
		case 'B':
			if(c2 == 'a') { number = 56; goto TWO_LETTER; }
			if(c2 == 'e') { number = 4; goto TWO_LETTER; }
			if(c2 == 'h') { number = 107; goto TWO_LETTER; }
			if(c2 == 'i') { number = 83; goto TWO_LETTER; }
			if(c2 == 'k') { number = 97; goto TWO_LETTER; }
			if(c2 == 'r') { number = 35; goto TWO_LETTER; }
			number = 5;
			goto ONE_LETTER;
		case 'C':
			if(c2 == 'a') { number = 20; goto TWO_LETTER; }
			if(c2 == 'd') { number = 48; goto TWO_LETTER; }
			if(c2 == 'e') { number = 58; goto TWO_LETTER; }
			if(c2 == 'f') { number = 98; goto TWO_LETTER; }
			if(c2 == 'l') { number = 17; goto TWO_LETTER; }
			if(c2 == 'm') { number = 96; goto TWO_LETTER; }
			if(c2 == 'n') { number = 112; goto TWO_LETTER; }
			if(c2 == 'o') { number = 27; goto TWO_LETTER; }
			if(c2 == 's') { number = 55; goto TWO_LETTER; }
			if(c2 == 'r') { number = 24; goto TWO_LETTER; }
			if(c2 == 'u') { number = 29; goto TWO_LETTER; }
			number = 6;
			goto ONE_LETTER;
		case 'D':
			if(c2 == 'b') { number = 105; goto TWO_LETTER; }
			if(c2 == 'y') { number = 66; goto TWO_LETTER; }
			if(c2 == 's') { number = 110; goto TWO_LETTER; }
			goto NO_ELEM;
		case 'E':
			if(c2 == 'r') { number = 68; goto TWO_LETTER; }
			if(c2 == 's') { number = 99; goto TWO_LETTER; }
			if(c2 == 'u') { number = 63; goto TWO_LETTER; }
			goto NO_ELEM;
		case 'F':
			if(c2 == 'e') { number = 26; goto TWO_LETTER; }
			if(c2 == 'l') { number = 114; goto TWO_LETTER; }
			if(c2 == 'm') { number = 100; goto TWO_LETTER; }
			if(c2 == 'r') { number = 87; goto TWO_LETTER; }
			number = 9;
			goto ONE_LETTER;
		case 'G':
			if(c2 == 'a') { number = 31; goto TWO_LETTER; }
			if(c2 == 'd') { number = 64; goto TWO_LETTER; }
			if(c2 == 'e') { number = 32; goto TWO_LETTER; }
			goto NO_ELEM;
		case 'H':
			if(c2 == 'e') { number = 2; goto TWO_LETTER; }
			if(c2 == 'f') { number = 72; goto TWO_LETTER; }
			if(c2 == 'g') { number = 80; goto TWO_LETTER; }
			if(c2 == 'o') { number = 67; goto TWO_LETTER; }
			if(c2 == 's') { number = 108; goto TWO_LETTER; }
			number = 1;
			goto ONE_LETTER;
		case 'I':
			if(c2 == 'n') { number = 49; goto TWO_LETTER; }
			if(c2 == 'r') { number = 77; goto TWO_LETTER; }
			number = 53;
			goto ONE_LETTER;
		case 'K':
			if(c2 == 'r') { number = 36; goto TWO_LETTER; }
			number = 19;
			goto ONE_LETTER;
		case 'L':
			if(c2 == 'a') { number = 57; goto TWO_LETTER; }
			if(c2 == 'i') { number = 3; goto TWO_LETTER; }
			if(c2 == 'r') { number = 103; goto TWO_LETTER; }
			if(c2 == 'u') { number = 71; goto TWO_LETTER; }
			if(c2 == 'v') { number = 116; goto TWO_LETTER; }
			goto NO_ELEM;
		case 'M':
			if(c2 == 'c') { number = 115; goto TWO_LETTER; }
			if(c2 == 'd') { number = 101; goto TWO_LETTER; }
			if(c2 == 'g') { number = 12; goto TWO_LETTER; }
			if(c2 == 'n') { number = 25; goto TWO_LETTER; }
			if(c2 == 'o') { number = 42; goto TWO_LETTER; }
			if(c2 == 't') { number = 109; goto TWO_LETTER; }
			goto NO_ELEM;
		case 'N':
			if(c2 == 'a') { number = 11; goto TWO_LETTER; }
			if(c2 == 'b') { number = 41; goto TWO_LETTER; }
			if(c2 == 'd') { number = 60; goto TWO_LETTER; }
			if(c2 == 'e') { number = 10; goto TWO_LETTER; }
			if(c2 == 'h') { number = 113; goto TWO_LETTER; }
			if(c2 == 'i') { number = 28; goto TWO_LETTER; }
			if(c2 == 'o') { number = 102; goto TWO_LETTER; }
			if(c2 == 'p') { number = 93; goto TWO_LETTER; }
			number = 7;
			goto ONE_LETTER;
		case 'O':
			if(c2 == 'g') { number = 118; goto TWO_LETTER; }
			if(c2 == 's') { number = 76; goto TWO_LETTER; }
			number = 8;
			goto ONE_LETTER;
		case 'P':
			if(c2 == 'a') { number = 91; goto TWO_LETTER; }
			if(c2 == 'b') { number = 82; goto TWO_LETTER; }
			if(c2 == 'd') { number = 46; goto TWO_LETTER; }
			if(c2 == 'm') { number = 61; goto TWO_LETTER; }
			if(c2 == 'o') { number = 84; goto TWO_LETTER; }
			if(c2 == 'r') { number = 59; goto TWO_LETTER; }
			if(c2 == 't') { number = 78; goto TWO_LETTER; }
			if(c2 == 'u') { number = 94; goto TWO_LETTER; }
			number = 15;
			goto ONE_LETTER;
		case 'R':
			if(c2 == 'a') { number = 88; goto TWO_LETTER; }
			if(c2 == 'b') { number = 37; goto TWO_LETTER; }
			if(c2 == 'e') { number = 75; goto TWO_LETTER; }
			if(c2 == 'f') { number = 104; goto TWO_LETTER; }
			if(c2 == 'g') { number = 111; goto TWO_LETTER; }
			if(c2 == 'h') { number = 45; goto TWO_LETTER; }
			if(c2 == 'n') { number = 86; goto TWO_LETTER; }
			if(c2 == 'u') { number = 44; goto TWO_LETTER; }
			goto NO_ELEM;
		case 'S':
			if(c2 == 'b') { number = 51; goto TWO_LETTER; }
			if(c2 == 'c') { number = 21; goto TWO_LETTER; }
			if(c2 == 'e') { number = 34; goto TWO_LETTER; }
			if(c2 == 'g') { number = 106; goto TWO_LETTER; }
			if(c2 == 'i') { number = 14; goto TWO_LETTER; }
			if(c2 == 'm') { number = 62; goto TWO_LETTER; }
			if(c2 == 'n') { number = 50; goto TWO_LETTER; }
			if(c2 == 'r') { number = 38; goto TWO_LETTER; }
			number = 16;
			goto ONE_LETTER;
		case 'T':
			if(c2 == 'a') { number = 73; goto TWO_LETTER; }
			if(c2 == 'b') { number = 65; goto TWO_LETTER; }
			if(c2 == 'c') { number = 43; goto TWO_LETTER; }
			if(c2 == 'e') { number = 52; goto TWO_LETTER; }
			if(c2 == 'h') { number = 90; goto TWO_LETTER; }
			if(c2 == 'i') { number = 22; goto TWO_LETTER; }
			if(c2 == 'l') { number = 81; goto TWO_LETTER; }
			if(c2 == 'm') { number = 69; goto TWO_LETTER; }
			if(c2 == 's') { number = 117; goto TWO_LETTER; }
			goto NO_ELEM;
		case 'U':
			number = 92;
			goto ONE_LETTER;
		case 'V':
			number = 23;
			goto ONE_LETTER;
		case 'W':
			number = 74;
			goto ONE_LETTER;
		case 'X':
			if(c2 == 'e') { number = 54; goto TWO_LETTER; }
			goto NO_ELEM;
		case 'Y':
			if(c2 == 'b') { number = 70; goto TWO_LETTER; }
			number = 39;
			goto ONE_LETTER;
		case 'Z':
			if(c2 == 'n') { number = 30; goto TWO_LETTER; }
			if(c2 == 'r') { number = 40; goto TWO_LETTER; }
			goto NO_ELEM;
	}
	
// error
NO_ELEM:
	if(count) *count = 0;
	return 0;

// success
ONE_LETTER:
	if(count) *count = 1;
	return number;
	
TWO_LETTER:
	if(count) *count = 2;
	return number;
}


int identifySimpleElement(char** s) {
	int n = 0;
	switch(toupper(**s)) {
		case 'B': 
			if(tolower(*(*s+1)) == 'r') {
				n = 35;
				(*s)++;
			}
			else n = 5;
			break;
		case 'C':
			if(tolower(*(*s+1)) == 'l') {
				n = 17;
				(*s)++;
			}
			else n = 6;
			break;
		case 'N': n = 7; break;
		case 'O': n = 8; break;
		case 'P': n = 15; break;
		case 'S': n = 16; break;
		case 'F': n = 9; break;
		case 'I': n = 53; break;
		default:
			return 0;
	}
	
	(*s)++;
	
	return n;
}


int parseSmiles(char* src) {
	
	char* s = src;
	
	while(*s) {
		char c = *s;
		
		if(c == '.') { // "non-bond"
			
			continue;
		}
		if(c == '-') { // single
			
			continue;
		}
		if(c == '=') { // double
			
			continue;
		}
		if(c == '#') { // triple
			
			continue;
		}
		if(c == '$') { // quadruple
			
			continue;
		}
		if(c == ':') { // aromatic "one and a half" 
			
			continue;
		}
		if(c == '/') { // sterochemical (3D) single bonds
			
			continue;
		}
		if(c == '\\') { // sterochemical (3D) single bonds
			
			continue;
		}
		
		if(c == '%') { // double-digit ring
			
			continue;
		}
		if(isnum(c)) { // ring
			
			continue;
		}
		
		
		if(c == '[') {
			int num = 0;
			SmilesAtom* a = parseElement(&s, &num);
			
			
		}
		if(isalpha(c)) {
			int number = identifySimpleElement(&s);
			if(!number) {
				cout << "broken short element: "<<c<<".\n";
				s++;
			}
			
			SmilesAtom* a = new SmilesAtom(number);
			
			if(islower) {
				// aromatic bonding, seems to be implied in front of this atom
				a->aromaticShorthand = true;
			}
		}
		
		
	}
	
	
	
	
	
	
	
	
}





