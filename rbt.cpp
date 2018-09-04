#include <iostream>
#include "rbt.h"
using namespace std;


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
            output<<n1.data<<endl;
            return output;
        }
};
int main(){
    Node a(3),b(2),c(1),d(4),e(6);
    RBTree <Node> tree;
    tree.addNode(&a);
    tree.addNode(&b);
    tree.addNode(&c);
    tree.addNode(&d);
    tree.addNode(&e);
    for (int i=0;i<10;i++){
        Node *f=new Node(i);
        tree.addNode(f);
    }
    for (int i=20;i>10;i--){
        Node *f=new Node(i);
        tree.addNode(f);
    }
    tree.printTree();
    cout<<tree.count<<endl;
    cout<<tree.repeat<<endl;

}
