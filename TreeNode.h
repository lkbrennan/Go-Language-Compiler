#include <string>
#include <vector>
//#include "stdafx.h"

using namespace std;

class TreeNode {
public:
	TreeNode();

	struct node{
		string data;
		node* firstchild = NULL;
		node* sibling = NULL;
	};

	node root;
	node decl;
	node func;
	node packages;
	node imports;

	node* createNode(string val);
	void traverse(node* parent, int depth);
	void insertNodes(node* parent, string val);
	void addSibling(node* sibling, node* child);
};