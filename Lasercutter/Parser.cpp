#include "Parser.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

Parser::Parser()
{
}

Parser::Parser(std::string path){
	this->path = path;
	init_dispatch();
}

Parser::~Parser()
{
}

// Einlesen des OP Codes aus der File
void Parser::readOPCode_fromFile()
{
	std::string puffer; // Puffer fuer das einlesen
	this->fi.open(this->path, std::ios::in); // Oeffne die Datei mit Path nur einlesend
	if (this->fi.good()) // Falls die Datei vorhanden ist 
		while (!this->fi.eof()) // lese solange wie das EOF nicht erreicht ist !
		{
			getline(fi, puffer); // Lese eine Zeile und puffere
			if (!(puffer.find("#") != std::string::npos)) // Ignoriere Zeilen die mit # Anfangen (oder eines Enthalten)
				this->op_Codes.push_back(puffer); // Schiebe den inhalt des Puffers an das Ende des Vector
			
		}
	this->fi.close(); // Schiesse die datei anschliesend wieder
}

// Uebergibt an die Adressen der beiden ints die Koordinaten x, y
void Parser::getCoordinates(int pos_in_vec, int* x, int* y)
{
	if (this->validOPCode(&this->op_Codes[pos_in_vec]))
	{
		std::size_t pos = this->op_Codes[pos_in_vec].find(", ");
		if (pos == std::string::npos) // Falls kein , im String gefunden worden ist --> LASER ON / LASER OFF
		{
			*x = -1; *y = -1;
		}
		else
		{		// Position des ersten Whitespaces ermitteln + 1 (Damit er nicht mit in die fktn uebergeht)
			*x = std::stoi(this->op_Codes[pos_in_vec].substr(this->op_Codes[pos_in_vec].find(" ") + 1));//, this->op_Codes[pos_in_vec].find(" ") + 1));
			/* Substring mit der pos (s.h. oben) MOVE 10, 10
														  ^^
			*/
			*y = std::stoi(this->op_Codes[pos_in_vec].substr(pos + 1, this->op_Codes[pos_in_vec].find("\n")));
		}
	}
	else
	{
		*x = -1; *y = -1; // Achtung mit andern abklaeren bezueglich der Koordinaten
	}
	
}

// Ueberpruefung des OP Codes 
bool Parser::validOPCode(std::string* opcode)
{
    for (unsigned int i = 0; i < this->dispatch_Table.size(); i++)
		if (opcode->find(dispatch_Table[i]) != std::string::npos) // Falls der OP Code in der Dispatch Table zu finden ist
				return true;									  // --> OP Code Valid
	return false;
}

// Dispatch Table init mit gueltigen OP Code Befehlen
void Parser::init_dispatch()
{
	this->dispatch_Table.push_back("LASER ON");
	this->dispatch_Table.push_back("LASER OFF");
	this->dispatch_Table.push_back("MOVE");
}
