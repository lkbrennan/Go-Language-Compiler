//#include "stdafx.h"
#include "TreeNode.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>


using namespace std;

TreeNode::node root;
TreeNode::node decl;
TreeNode::node func;
TreeNode::node packages;
TreeNode::node imports;

TreeNode::TreeNode() {
	root.firstchild = &packages;
	packages.sibling = &imports;
	imports.sibling = &func;
	func.sibling = &decl;

	root.data = "ROOT";
	decl.data = "DECLARATIONS";
	func.data = "FUNCTIONS";
	packages.data = "PACKAGES";
	imports.data = "IMPORTS";
};

TreeNode::node* TreeNode::createNode(string val) {
	node* parent_node = new node;
	parent_node->data = val;

	return parent_node;

}

void TreeNode::traverse(node* currentnode, int depth) {
	//code example taken from https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
	if(currentnode == NULL){
		depth--;
		return;
	}

	for (int i = 0; i <= depth; i++) {
		cout << "--";
	}

	depth++;

	cout << ">" << currentnode->data << '\n';

	traverse(currentnode->firstchild, depth);
	traverse(currentnode->sibling, --depth);
}

void TreeNode::insertNodes(node* parent, string val){
	node* child = createNode(val);

	if (parent->firstchild == NULL) {
		parent->firstchild = child;
	}
	else {
		addSibling(parent, child);
	}
}

void TreeNode::addSibling(node* sibling, node* child) {
	if (sibling->sibling == NULL) {
		sibling->sibling = child;
	}
	else {
		addSibling(sibling->sibling, child);
	}
}

