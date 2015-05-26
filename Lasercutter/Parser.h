#pragma once
#include <string>
#include <fstream>
#include <vector>

class Parser
{
public:
	// Variablen
	std::vector < std::string > op_Codes;
	std::string path;
	std::ifstream fi;
	// Konstr,- Destruktor
	Parser();
	Parser(std::string);
	virtual ~Parser();
	// Methoden
	void readOPCode_fromFile();
	void getCoordinates(int pos_in_vec, int* x, int* y);
private:
	std::vector <std::string> dispatch_Table;
	void init_dispatch();
	bool validOPCode(std::string*);

};