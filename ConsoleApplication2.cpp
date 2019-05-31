/* Lexer and Parser created by Shona Doran and Lauren Keenan Brennan
Lab Exercise 1 for Compiler Construction
If your console screen closes unexpectedly while running the program,
try running it using CTRL+F5
*/

//#include "stdafx.h"
#include "Lexer.h"
#include "Parser.h"
#include <fstream>
#include <string>
//#include <dos.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	string app;
	Lexer lexer;
	Parser parser;

	
	parser.Parse();
	parser.printTree();

}

