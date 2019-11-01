#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#include "moly.hpp"



class CSVParser {
public:
	
	char* source;
	
	void Load(string* path);
	
	void NextLine();
	
	vector<string>* header;
	vector<vector<string>*> lines;
	
	
protected:
	char* cursor;
	int currentLine;
	int currentColumn;
	
	vector<string>* grabLine();
	
};


void CSVParser::Load(string* path) {
	// read the file
	FILE* f = fopen(path->c_str(), "rb");
	
	fseek(f, 0, SEEK_END);
	int sz = ftell(f);
	fseek(f, 0, SEEK_SET);
	
	char* src = new char[sz + 1];
	
	fread(src, 1, sz, f);
	src[sz] = 0;
	
	fclose(f);
	
	
	source = src;
	cursor = src;
	currentLine = 0;
	currentColumn = 0;
	
	grabLine();
	
	while(*cursor != '\0') lines.push_back(grabLine());
	
	delete src;
}



vector<string>* CSVParser::grabLine() {
	vector<string>* cols = new vector<string>;
	
	char* s = cursor;
	char* e = s;
	
	int cindex = 0;
	
	while(1) { // columns
		
		if(*s == '"') {
			s++;
			while(1) {
				e = strchr(s, '"');
				if(*e != '"') {
					cout << "unexpected end of csv file\n";
					exit(1);
				}
				
				if(*(e + 1) == '"') { // quoted quotes
					e += 2;
					continue;
				}
				
				break;
			}
			
			// e is at the end now; extract the string 
			// TODO: unescape internal quotes
			cols->push_back(string(s, e-s));
		}
		else {
			e = strpbrk(e, ",\r\n");
			
			// e is at the end
			cols->push_back(string(s, e-s));
		}
		
		if(*e == '\r') break;
		if(*e == '\n') break;
		if(*e == '\0') break;
	
		e++;
		s = e;
		


	}
	
	s = e;
	s++; // BUG: may need better handling for \0 and \r
	cursor = s;
	
	for(string ss : *cols) {
		cout << ss << endl;
	} 
	
	return cols;
}


Element g_elements[120];


void parse_chem_csv(string path) {
	
	CSVParser csv;
	
	csv.Load(&path);
	
	return;
	
	// read the file
	FILE* f = fopen(path.c_str(), "rb");
	
	fseek(f, 0, SEEK_END);
	int sz = ftell(f);
	fseek(f, 0, SEEK_SET);
	
	char* src = new char[sz + 1];
	
	fread(src, 1, sz, f);
	src[sz] = 0;
	
	fclose(f);
	
	// this csv file has certain properties that allow us to be lazy in parsing
	char* s = src;
	
	// skip the header line
	s = strchr(s, '\n');
	
	while(*s) {
		// atomic number
		int en = strtol(s, &s, 10);
		g_elements[en].number = en;
		
		s++; // skip comma
		
		// symbol
		int l = strchr(s, ',') - s;
		g_elements[en].symbol = string(s, l);
		
		s += l + 1;
		
		// name
		l = strchr(s, ',') - s;
		g_elements[en].name = string(s, l);
		
		
// 		cout << en << " " << g_elements[en].name << " (" << g_elements[en].symbol << ")\n"; 
		if(en == 103) break; // TODO: fix this ugly hack later
		
		s = strchr(s, '\n');
	}
	
	
	
	
	delete src;
}













