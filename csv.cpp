#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

#include "moly.hpp"



class CSVParser {
public:
	
	char* source;
	
	void Load(string* path);
	
	void NextLine();
	char* 
	
protected:
	char* cursor;
	int currentLine;
	int currentColumn;
	
	char* buffer;
}


void CSVParser::Load(string* path) {
	// read the file
	FILE* f = fopen(path.c_str(), "rb");
	
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
}

// returns NULL for eol/eof, cursor otherwise
char* CSVParser::checkEOL() {
	char* s = cursor;
	while(*s) {
		if(*s == '\r' || *s == '\n') return NULL;
		if(*s == ',' ) return cursor;
		s++;
	}
	return NULL;
}


char* CSVParser::findEOC() {
	char* s = cursor;
	while(*s) {
		if(*s == '\r' || *s == '\n') return s - 1;
		if(*s == ',' ) return  s - 1;
		s++;
	}
	return s - 1;
}

// returns 0 for normal, 1 for end of line (does not move to next line)
char* CSVParser::NextColumn() {
	while(1) {
		
		if(*cursor == ',') {
			cursor++;
			char* e = findEOC();
			
			
		} 
		else if(*cursor == '"') {
			cursor++;
			char* e = findEOC();
			
			
		} 
		
	}
}

void CSVParser::NextLine() {
	
}




Element g_elements[120];


void parse_chem_csv(string path) {
	
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













