






#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;



class CSVParser {
public:
	
	char* source;
	
	void Load(string path);
	
	vector<string>* header;
	vector<vector<string>*> lines;
	
	CSVParser();
	~CSVParser();
	
protected:
	char* cursor;
	int currentLine;
	int currentColumn;
	
	vector<string>* grabLine();
	
};
