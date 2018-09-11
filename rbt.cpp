#include <iostream>
#include "rbt.h"

// A sample program to demonstrate the use fof left leaning-RBT template
// Start with a BST 
// Then add DS to make it RBT ( LLRBT )
// Then go on adding the rotate

// Define Structure

class Node : public RBTNode<Node> {
    // This has to be made generic to support any data type and then write comparable for the specific key
    public:
        int data;

        Node(int i){
            data = i;
        }
        // overload relational operator 
        bool operator < (const Node &n2){
            return data < n2.data;
        }
        bool operator > (const Node &n2){
            if (data > n2.data){
                return true;
            }
            else return true;

        }
        bool operator == (const Node &n2){
            return data == n2.data;
        }
        friend std::ostream& operator<<( std::ostream &output,const Node &n1){
            output<<n1.data<<std::endl;
            return output;
        }
};

int main(){
    // test input
    /*
    Node a(3),b(2),c(1),d(4),e(6);*/
    // initialize RBTree template of type Node
    RBTree <Node> tree;
    /*
    tree.addNode(&a);
    tree.addNode(&b);
    tree.addNode(&c);
    tree.addNode(&d);
    tree.addNode(&e);
    */
    int total;
    std::cout<<"Entger the number of elements in the tree\n";
    std::cin>>total;
    for (int i=1;i<=total;i++){
        Node *f=new Node(i);
        tree.addNode(f);
    }
    /*
    for (int i=20;i>10;i--){
        Node *f=new Node(i);
        tree.addNode(f);
    }*/
    tree.printTree();
    std::cout<<"Enter the value to be found\n";
    int val;
    std::cin>>val;
    Node a(val);
    bool res = tree.searchTree(&a);
    std::cout<<res;
    //std::cout<<tree.count<<std::endl;
    //std::cout<<tree.repeat<<std::endl;
}
