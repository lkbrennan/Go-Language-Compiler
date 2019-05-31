//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
//#include <dos.h>
#include "Lexer.h"

using namespace std;

ifstream inFile("input.go");

string Lexer::readString()
{
	string app;

	if (inFile.fail()) {
		cerr << "Unable to open file for reading." << endl;
		exit(1);
	}

	if (inFile.is_open())
	{
			char c;
			inFile.get(c);

			if ((c == '\r') || (c == '\n')) {
				inFile.get(c);
			}

			while ((c != ' ')&&(c != '\n')){
				app.append(1, c); 
				inFile.get(c);
			} 

			//used if you want to print out the .go file
			/*if (c == ' ') {
				cout << c;
			}*/

			if (inFile.eof()) {
				return("EOF");
			}

			//used if you want to print out the .go file
			//cout << app;
			return(app);
	}
}