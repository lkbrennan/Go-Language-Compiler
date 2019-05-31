//tree.insertNodes(&tree.packages, nextToken);


//#include "stdafx.h"
#include "Parser.h"
#include "Lexer.h"
#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include <string>
//#include <dos.h>

using namespace std;

TreeNode tree = TreeNode();
Lexer lexer;
string token;
string nextToken;

void Parser::Parse() {

	Token t;
	t.Value = 0;
	t.Symbol = 0;

	//Will check for a package
	nextToken = lexer.readString();
	if (nextToken == "package") {
		t.Type = Package;

		//Will read in package name
		nextToken = lexer.readString();

		tree.insertNodes(&tree.packages, nextToken);
		t.Type = StringLiteral;
	}
	//Will produce error if no package at the start
	else {
		t.Type = Error;
		errorMessage(nextToken);
	}

	//Will check for imports and the function
	ParseImport();
	ParserFunc();
}

void Parser::ParseImport() {
	Token t;
	t.Value = 0;
	t.Symbol = 0;

	nextToken = lexer.readString();
	if (nextToken == "import") {
		//Reads the name of the function
		nextToken = lexer.readString();
		if ((nextToken.at(0) == '"') && (nextToken.at((nextToken.length()) - 1) == '"'))
		{
			t.Type = Import;
			tree.insertNodes(&tree.imports, nextToken);
		}
	}
	else {
		errorMessage(nextToken);
	}
}

void Parser::ParserFunc() {
	Token t;
	t.Value = 0;
	t.Symbol = 0;

	nextToken = lexer.readString();
	if (nextToken == "func") {

		//reads function name
		nextToken = lexer.readString();
		tree.insertNodes(&tree.func, nextToken);
		t.Type = Function;

		nextToken = lexer.readString();
		//Checks for open parenthesis
		if (nextToken == "{") {
			t.Type = Openparenthesis;

			//Use the import
			nextToken = lexer.readString();

			t.Type = Import;
			//Print and other possible functions here
			ParserPrint();
			ParserEnd();
		}
		else {
			errorMessage(nextToken);
		}
	}
	else {
		errorMessage(nextToken);
	}
}

void Parser::ParserPrint() {
	Token t;
	t.Value = 0;
	t.Symbol = 0;

	//Reads in the print statement
	nextToken = lexer.readString();
	if (nextToken == "Println(\"Hello\")") {
		t.Type = Function;
		tree.insertNodes(&tree.func, nextToken);
	}
	else
	{
		errorMessage(nextToken);
	}
}

//Checks for a closed parenthesis at the end
void Parser::ParserEnd() {
	/*Token t;
	t.Value = 0;
	t.Symbol = 0;

	nextToken = lexer.readString();
	if (nextToken == "}") {
		t.Type = Closedparenthesis;
	}
	else {
		errorMessage(nextToken);
	}*/
}

//Error message
void Parser::errorMessage(string msg) {
	cout << '\n' << "Error with Token: " << msg << '\n';
}

void Parser::printTree() {
	tree.traverse(&tree.root,0);
}