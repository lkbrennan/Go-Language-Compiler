//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
//#include <dos.h>

using namespace std;

enum TokenType
{
	Openparenthesis,
	Closedparenthesis,
	Error,
	Package,
	Function,
	Main,
	Declaration,
	Import,
	StringLiteral,
	EndOfFile
};

struct Token
{
	TokenType   Type;
	double      Value;
	char      Symbol;

	Token() :Type(), Value(0), Symbol(0)
	{}
};

class Parser {
public:
	void Parse();
	void ParsePackagename();
	void ParseImport();
	void ParserFunc();
	void ParserPrint();
	void ParserEnd();
	void errorMessage(string msg);
	void printTree();
};
