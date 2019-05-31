The members of this project were Lauren Keenan Brennan and Shona Doran.

The compiler will read in the code with the lexer by reading each character. If the character is a non token character like a space, tab or new line then it will be ignored. 
If not, it will be appended to a string and given to the parser. This will continue until the end of the file has been reached. The parser will then start reading the tokens
given to it by the lexer. It will start with package and then continue to check each token is written correctly and placed in the right place. If not an error message will occur
that will also display the token causing the issue.

The first 5 nodes of the tree (Root, Packages, Imports, Functions & Declarations) are created when the tree is initialised. From there, we assign types to each token in the parser and 
they are then added to certain nodes in the tree. There is an insertNode, createNode and add sibling fundtion in the treeNode.cpp file which allow for nodes to be created and inserted 
onto the correct parent node. The tree was traversed using a depth first search so everything was printed out in order of its parent nodes.

We have included a test file named input.go that will be run with the program. It has been written to run correctly but if brackets or functions and such are removed it will display an error
message to the user. This code was tested in a vagrant environment.