# LLRBT
### A generic c++ template to build Left leaning red black tree [1]
*** As of now adding nodes and printing it inorder is supported. Further support will be added soon along with more refinements. ***

The project aims to build a template for self balanced tree based on Robert Sedgewick's (princeton university) left leaning red black tree.
As of now the template provides a way to create nodes by inheriting one of the supporting class "RBTNode" which appends the user data structure with necessary RBT attributes and enables the user to build a balanced tree.
As of now, it requires the user class to overload relational operators and ostream operator. 

How does it work?
The template provides a way to arrange any given set of nodes in a balanced tree structure. 
As such the template doesn't take any extra space apart from a few tree attributes. The user class/DS has to allocate memory and add the node to be a part of the tree. 
Although there is a need for the user class to overload the operators so that the tree is arranged based on the user class key.
Reference:
[1]: https://www.cs.princeton.edu/~rs/talks/LLRB/LLRB.pdf 

